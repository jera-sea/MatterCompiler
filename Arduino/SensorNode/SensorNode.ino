#include <SPI.h>
#include <MCP492X.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "Configuration.h"

Adafruit_INA219 ina219(0x40);

MCP492X VIdac(dac_cs);


//sense variables
float oe_voltage = 3.2;
float oe_current = 156.32;
float ie_voltage = 2.1;
float ie_current = 15.67;
float surf_temp=10.2;
float el_flow = 3.2;
float total_charge_transfer = 0.0; //dummy value this will be calculated on the pi side

//variables for potentiodynamic sweeps
float volt_step = 0.0;
float scan_limit = 0.0;

//power control variables
float current_voltage = 0.0; // this is the output voltage of the OPA regulator not the cell voltage
int current_current = 0;
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
  pinMode(13,OUTPUT);

//put the outputs to sleep and set PWM off to begin with
digitalWrite(m1slp, LOW);
digitalWrite(m2slp, LOW);
digitalWrite(m1pwm, LOW);
digitalWrite(m2pwm, LOW);
digitalWrite(m1dir, LOW);
digitalWrite(m2dir, LOW);
digitalWrite(ldac, HIGH);



  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;
    
  Serial.println("Hello!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  ina219.begin();
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  Serial.println("Measuring voltage and current with INA219 ...");

  //Sensor Sample Rates

  startTimer(TC1, 0, TC3_IRQn, 10); //TC1 channel 0, the IRQ for that channel and the desired frequency
  
  //digitalWrite(13, HIGH);
  // m1_switch(on, AtoB);

  VIdac.begin();

  fwd_voltage_scan(5.2, 23, true);
  //dacUp(7.63, 965);
}

//=============================================================================================
//=============================================================================================
//                                      START OF MAIN LOOP
//=============================================================================================
//=============================================================================================
void loop(void) 
{


  if(iv_sample){
    iv_sample = false;
    get_elec(); //sample electrical parameters
  }

  if(output_update_flag){
    scan_update();
    Serial.println(current_voltage);
  }

  
  //delay(2000);
  //send_sample();
 // m1_ground();
 //m1_switch(off, AtoB);

}

//=============================================================================================
//=============================================================================================
void send_sample(){
  Serial.println("sID");
  //Serial.print(oe_voltage + ',' + oe_current + ',' + ie_voltage + ',' + ie_current + ',' + surf_temp + ',' + el_flow + ',' + total_charge_transfer);
  Serial.print(oe_voltage);
 Serial.print(":");
 Serial.print(oe_current);
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
void fwd_voltage_scan(float scanRate, float target_v, boolean electrode){
  scan_limit = target_v;
  scan_dir=true; //set scan direction positive
  dacUp(0.0, 4000);
  if(electrode){ //outer electrode selected
    volt_step = scanRate/10;
    startTimer(TC1, 1, TC4_IRQn, 10);
    Serial.println("tc4 started, scanRate = "); Serial.println(volt_step);
  }
  return;
}
//=============================================================================================
//=============================================================================================
void scan_update(){
  output_update_flag=false;
  //Serial.println("SCAN UPDATE"); Serial.println(scan_limit);
  float new_voltage = current_voltage + volt_step;

  if(current_voltage>=scan_limit){
    scan_dir=false;
  }
  if(scan_dir){
    dacUp(new_voltage, 4000); //increase output voltage
  }
  else{
    new_voltage=current_voltage-volt_step;
    if(new_voltage<0.0){
      new_voltage=0.0;
      scan_complete = true;
      Serial.println("SCAN COMPLETE");
      stopTimer(TC4_IRQn); //stop scan update timer
    }
    dacUp(new_voltage, 4000); //decrease output voltage
  }

  return;
}

//=============================================================================================
//=============================================================================================
void dacUp(float voltage, int current){
  current_voltage = voltage;
  current_current = current;
  unsigned int v_dig = int(round(voltage*v_factor));
  unsigned int i_dig = map(current, 0, 5000, 4055, 0);//int(round(current*i_factor));
  //Serial.println(v_dig);
  //Serial.println(i_dig);

  VIdac.analogWrite(Vdac, 0, 0, 1, v_dig);
  VIdac.analogWrite(Idac, 0, 0, 1, i_dig);
  digitalWrite(ldac, LOW);
  delay(2);
  digitalWrite(ldac, HIGH);
  
  return;
}


//=============================================================================================
//=============================================================================================
void m1_switch(boolean state, boolean dir){

  //first set the direction
  if(dir){
    //Serial.println("Current flow A to B");
    digitalWrite(m1dir, LOW);} //current flow A to B
  else{
    digitalWrite(m1dir, HIGH);}

  //set pwm value and switch the sleep bit
  if(state){
    //Serial.println("Waking up and turning full on");
    digitalWrite(m1pwm, HIGH); //switch pwm first to make sure the outputs do what you want when awoken
    digitalWrite(m1slp, HIGH);
  }
  else{
    digitalWrite(m1slp, LOW); //switch sleep bit first to avoid the "outputs grounded" state when pwm goes low
    delay(1);                 //not sure how long it takes to go to sleep...
    digitalWrite(m1pwm, LOW);
  }

  return;
}
//=============================================================================================
//=============================================================================================
void m1_ground(){
  
  digitalWrite(m1pwm, LOW); //set outputs to ground
  digitalWrite(m1slp, HIGH); //wake up

  return;
}
//=============================================================================================
//                                Sensor Sampling
//=============================================================================================
void get_elec(){
  
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

  
  /*
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");
  */
  
  return;
}

//=============================================================================================
//=============================================================================================
void get_temp(){
  float dummy_temp = 10.0;
  //read temperatures here

  surf_temp = dummy_temp;

  return;
}

//=============================================================================================
//=============================================================================================
void set_flow(){
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
        iv_sample=true; //set flag for electrical parameter sample collection
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
        uint32_t rc = VARIANT_MCK/128/frequency; //128 because we selected TIMER_CLOCK4 above
        TC_SetRA(tc, channel, rc/2); //50% high, 50% low
        TC_SetRC(tc, channel, rc);
        TC_Start(tc, channel);
        tc->TC_CHANNEL[channel].TC_IER=TC_IER_CPCS;
        tc->TC_CHANNEL[channel].TC_IDR=~TC_IER_CPCS;
        NVIC_EnableIRQ(irq);
}
void stopTimer(IRQn_Type irq){
  NVIC_DisableIRQ(irq);
}

