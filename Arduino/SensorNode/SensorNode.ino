#include <SPI.h>
#include <MCP492X.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "Configuration.h"
#include <OneWire.h>

Adafruit_INA219 ina219(0x41); //top side ina219
OneWire  ds(2);  // on pin 19 (a 5k6 pullup is present)
byte sealed_addr[8] = {0x28, 0xA0, 0xCC, 0xE0, 0x08, 0x00, 0x00, 0x2D};

MCP492X VIdac(dac_cs);

  //Create rolling average array

//=============================================================================================
//=============================================================================================
//                                      SETUP
//=============================================================================================
//=============================================================================================

void setup(void)
{
  pinMode(m1flt, INPUT_PULLUP);
  pinMode(m2flt, INPUT_PULLUP);
  pinMode(m1slp, OUTPUT);
  pinMode(m2slp, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(m2dir, OUTPUT);
  pinMode(m1pwm, OUTPUT);
  pinMode(m2pwm, OUTPUT);
  pinMode(ldac, OUTPUT);
  pinMode(13, OUTPUT);

  //put the outputs to sleep and set PWM off to begin with
  digitalWrite(m1slp, LOW);
  digitalWrite(m2slp, LOW);
  digitalWrite(m1pwm, LOW);
  digitalWrite(m2pwm, LOW);
  digitalWrite(m1dir, LOW);
  digitalWrite(m2dir, LOW);
  digitalWrite(ldac, HIGH);

  Serial.begin(115200);

  uint32_t currentFrequency;

  // Initialize the INA219.
  ina219.begin();

  

  // m1_switch(on, AtoB);

  VIdac.begin();
}

//=============================================================================================
//=============================================================================================
//                                      START OF MAIN LOOP
//=============================================================================================
//=============================================================================================
void loop(void)
{
 //get DS18b20 temperatrue (or not depending on timer
 //non time critical timed tasks:
     current_time = millis();
  if (current_time - previousDS_time > 1000) {
    ds18();
  }
  //log data by sending over serial to Pi 5 times per sec
  if ((current_time - previousSER_time > 200) && polishing) {
      send_sample();
      previousSER_time=current_time;
  }

  if (iv_sample) {
    iv_sample = false;
    get_elec(); //sample electrical parameters
    set_flow();
  }

  if (output_update_flag && !scan_complete) {
    scan_update();
    //Serial.println(current_voltage);
  }
  

  if(Serial.available()){
    receive_command();
  }

  if(charge_target<=total_charge_transfer && polishing){
    stopTimer(TC3_IRQn); //stop the sampling
    dacUp(0, 0);//switch off the supply
    polishing = false;
    total_charge_transfer=0;
    
  }

  //delay(2000);
  //send_sample();
  // m1_ground();
  //m1_switch(off, AtoB);

}

//=============================================================================================
//=============================================================================================
//                                   SERIAL COMMUNICATIONS
//=============================================================================================
//=============================================================================================
void receive_command() {
  String command = Serial.readStringUntil('\n');

  if (command.substring(0, command.indexOf(":")) == "SCANV") { //Start a voltage scan
    Serial.println("STARTING");
    scan_complete = false; //initiate scan
    fwd_voltage_scan(true);
    startTimer(TC1, 0, TC3_IRQn, 25); //TC1 channel 0, is serial send timer and sensor sample rate
  }
  if (command.substring(0, command.indexOf(":")) == "SCANI") { //start a current scan
    scan_complete = false; //initiate scan
    startTimer(TC1, 0, TC3_IRQn, 25); //TC1 channel 0, is serial send timer and sensor sample rate
  }
  if (command.substring(0, command.indexOf(":")) == "MAXV") { // maximum voltage for scan or polish followed by :<maximum_voltage>
    max_voltage = command.substring(command.indexOf(":") + 1).toFloat();
  }
  if (command.substring(0, command.indexOf(":")) == "MINV") { // minimum voltage for scan or polish followed by :<minimum_voltage>
    min_voltage = command.substring(command.indexOf(":") + 1).toFloat();
  }
  if (command.substring(0, command.indexOf(":")) == "MAXI") { // maximum current for scan or polish followed by :<maximum_current>
    max_current = command.substring(command.indexOf(":") + 1).toFloat();
  }
  if (command.substring(0, command.indexOf(":")) == "MINI") { // maximum voltage for scan or polish followed by :<maximum_current>
    min_current = command.substring(command.indexOf(":") + 1).toFloat();
  }
  if (command.substring(0, command.indexOf(":")) == "VSEC") { // maximum voltage for scan or polish followed by :<maximum_current>
    volt_sec = command.substring(command.indexOf(":") + 1).toFloat();
  }
   if (command.substring(0, command.indexOf(":")) == "RUN") { // maximum voltage for scan or polish followed by :<maximum_current>
    run_process(max_current, command.substring(command.indexOf(":") + 1).toFloat());
    startTimer(TC1, 0, TC3_IRQn, 50); //TC1 channel 0, is serial send timer and sensor sample rate set to 50Hz
  }
  return;

}
void send_sample() {
  Serial.print("data:");
  Serial.print(oe_voltage);
  Serial.print(":");
  Serial.print(oe_current_s);
  Serial.print(":");
  Serial.print(ie_voltage);
  Serial.print(":");
  Serial.print(ie_current);
  Serial.print(":");
  Serial.print(surf_temp);
  Serial.print(":");
  Serial.print(el_flow);
  Serial.print(":");
  Serial.println(total_charge_transfer);

  return;
}

//=============================================================================================
//=============================================================================================
//                                   POWER CONTROL FUNCTIONS
//=============================================================================================
//=============================================================================================
void run_process(float current, float total_charge){
  dacUp(30, current);
  charge_target = total_charge; //set total charge transfer
  previous_accumulation = millis();
  polishing = true;
  return;
}
//=============================================================================================
//=============================================================================================
void fwd_voltage_scan(boolean electrode) { //scanrate in volts per second electrode to scan (outer = true)
  scan_limit = max_voltage;
  scan_dir = true; //set scan direction positive
  polishing = true;
  dacUp(min_voltage, 4000);

  if (electrode) { //outer electrode selected
    volt_step = volt_sec / 100;
    startTimer(TC1, 1, TC4_IRQn, 100); //start scan with an update rate of 100hz
  }
  return;
}
//=============================================================================================
//=============================================================================================
void scan_update() {
  output_update_flag = false;
  //Serial.println("SCAN UPDATE"); Serial.println(scan_limit);
  float new_voltage = current_voltage + volt_step;

  if (current_voltage >= max_voltage) {
    scan_dir = false;
  }
  if (scan_dir) {
    dacUp(new_voltage, 4000); //increase output voltage
  }
  else {
    new_voltage = current_voltage - volt_step;
    if (new_voltage < min_voltage) {
      new_voltage = 0.0;
      scan_complete = true;
      polishing = false;
      //Serial.println("SCAN COMPLETE");
      stopTimer(TC4_IRQn); //stop scan update timer
      stopTimer(TC3_IRQn); //stop serial/sensor update timer
    }
    dacUp(new_voltage, 4000); //decrease output voltage
  }

  return;
}

//=============================================================================================
//=============================================================================================
void dacUp(float voltage, int current) {
  current_voltage = voltage;
  current_current = current;
  unsigned int v_dig = int(round(voltage * v_factor));
  float VLim = 4.75-(13750)*(float(current)/1000.0)/15000.0; //multiply by 10 000 to get a a large int value we can use in the arduino map function
  //Serial.println(VLim);
  VLim = VLim/1.181;
    //Serial.println(VLim);
  unsigned int i_dig = int((VLim/4.096)*4095.0);

  //unsigned int i_dig = map(int(VLim), 0, 40960, 0, 4095);//int(round(current*i_factor));
  //Serial.println("AKSHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHF");
  //Serial.println(i_dig);
  //Serial.println(v_dig);
  //Serial.println(i_dig);

  //write new values to mcp dac channels A and B with synchronous update enabled
  VIdac.analogWrite(Vdac, 0, 0, 1, v_dig);
  VIdac.analogWrite(Idac, 0, 0, 1, i_dig);
  digitalWrite(ldac, LOW);
  delay(2);
  digitalWrite(ldac, HIGH); //synchrinous update

  return;
}


//=============================================================================================
//=============================================================================================
void m1_switch(boolean state, boolean dir) {

  //first set the direction
  if (dir) {
    //Serial.println("Current flow A to B");
    digitalWrite(m1dir, LOW);
  } //current flow A to B
  else {
    digitalWrite(m1dir, HIGH);
  }

  //SLEEP MODE CONTROL AND PWM (ON OR OFF)
  if (state) {
    //Serial.println("Waking up and turning full on");
    digitalWrite(m1pwm, HIGH); //switch pwm first to make sure the outputs do what you want when awoken
    digitalWrite(m1slp, HIGH);
  }
  else {
    digitalWrite(m1slp, LOW); //switch sleep bit first to avoid the "outputs grounded" state when pwm goes low
    delay(1);                 //not sure how long it takes to go to sleep...
    digitalWrite(m1pwm, LOW);
  }

  return;
}
//=============================================================================================
//=============================================================================================
void m1_ground() {
  
  digitalWrite(m1pwm, LOW); //set outputs to ground
  digitalWrite(m1slp, HIGH); //wake up

  return;
}
//=============================================================================================
//                                Sensor Sampling
//=============================================================================================
void ds18(){

    previousDS_time = current_time;
    if (ds_flag) {
      start_ds_conv();
      ds_flag = false;
    }
    else {
      get_ds_temp();
      ds_flag = true;
    }
  return;
}

//=============================================================================================
//=============================================================================================
void get_elec() {

  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  //sample the two ina219 sensors on either side of the cell
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  //loadvoltage
  oe_voltage = busvoltage + (shuntvoltage / 1000); //still need to subtract the lowside transistor here for pulse reverse
  current_time = millis();
  
  ie_current = float(current_time); //temporary timer transfer
  oe_current_s = current_mA; //this is purely for realtiem logging
  oe_current[cRollingCount] = current_mA;
  cRollingCount++; //increment smoothing array position

  if(cRollingCount == 10 ){ //if 10 samples have been accumulated
    float smoothSum=0;
    for(int i=0; i < (smoothLen-1); i++){
      smoothSum+=oe_current[i];
    }

    //Serial.println(smoothSum/smoothLen);
    total_charge_transfer += ((smoothSum/1000.0)/smoothLen)*float((current_time-previous_accumulation)/1000.0);//add charge trasnferred since last accumulation
    previous_accumulation = current_time;
    cRollingCount=0;
    
  }
  


  return;
}

//=============================================================================================
//=============================================================================================
void start_ds_conv() {
  ds.reset();
  ds.select(sealed_addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  return;

}
void get_ds_temp() {
  byte i;
  byte present = 0;
  byte type_s = 0;
  byte data[12];
  float celsius, fahrenheit;
  present = ds.reset();
  ds.select(sealed_addr);
  ds.write(0xBE);         // Read Scratchpad

  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();

  }

  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;
  surf_temp = celsius;
  return;
}

void get_temp() {


  return;
}

//=============================================================================================
//=============================================================================================
void set_flow() {
  el_flow = 3.5;

  return;
}

//=============================================================================================
//                                Timer Interrupts
//=============================================================================================
//TC1 ch 0
void TC3_Handler()
{
  TC_GetStatus(TC1, 0);
  //digitalWrite(13, l = !l);
  iv_sample = true; //set flag for electrical parameter sample collection
  return;
}
//=============================================================================================
//=============================================================================================
void TC4_Handler()
{
  TC_GetStatus(TC1, 1);
  output_update_flag = true;
  digitalWrite(13, l = !l);
  return;
}
//=============================================================================================
//=============================================================================================
void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency) {
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk((uint32_t)irq);
  TC_Configure(tc, channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK4);
  uint32_t rc = VARIANT_MCK / 128 / frequency; //128 because we selected TIMER_CLOCK4 above
  TC_SetRA(tc, channel, rc / 2); //50% high, 50% low
  TC_SetRC(tc, channel, rc);
  TC_Start(tc, channel);
  tc->TC_CHANNEL[channel].TC_IER = TC_IER_CPCS;
  tc->TC_CHANNEL[channel].TC_IDR = ~TC_IER_CPCS;
  NVIC_EnableIRQ(irq);
}
void stopTimer(IRQn_Type irq) {
  NVIC_DisableIRQ(irq);
}

