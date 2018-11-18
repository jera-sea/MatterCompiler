#include <SPI.h>
#include <MCP492X.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "Configuration.h"
#include <OneWire.h>
#include "Waveforms.h"

MCP492X VIdac(dac_cs);

  //

//=============================================================================================
//=============================================================================================
//                                      SETUP
//=============================================================================================
//=============================================================================================

void setup(void)
{

  pinMode(ldac, OUTPUT);

  //put the outputs to sleep and set PWM off to begin with

  digitalWrite(ldac, HIGH);

  Serial.begin(115200);

  uint32_t currentFrequency;


  VIdac.begin();
  delay(5);
  startTimer(TC1, 0, TC3_IRQn, 100000); //TC1 channel 0, is sensor sample rate

  VIdac.analogWrite(0, 0, 0, 1, 0);
  VIdac.analogWrite(1, 0, 0, 1, 2000);
  digitalWrite(ldac, LOW);
  delay(2);
  digitalWrite(ldac, HIGH); //synchronous update
}

//=============================================================================================
//=============================================================================================
//                                      START OF MAIN LOOP
//=============================================================================================
//=============================================================================================
void loop(void)
{


  if (waveUpdate) {
    //Serial.println("SAMPLING");
    waveUpdate = false;
    pulse_update();
  }

  }
  //=============================================================================================
//=============================================================================================
void pulse_update() {
  //Serial.println("update");
  VIdac.analogWrite(0, 0, 0, 1, waveformsTable[0][wavePos]);
  digitalWrite(ldac, LOW);
  delayMicroseconds(2);
  digitalWrite(ldac, HIGH); //synchronous update
  wavePos++;
  if(wavePos == maxSamplesNum){  // Reset the counter to repeat the wave
    wavePos = 0;}
  return;
}
//=============================================================================================
//                                   Pulse state machine
//=============================================================================================

void state_machine(){
  stateChange=false;
  
  if(matterState>=4){matterState=0;}//rollover and continue from 0
 
  switch(matterState){
    case 0: //forward pulse
      state_duration(fwd_pulse);
      //set dac
      //apply power
      break;
    case 1: //waiting period forward->reverse
    state_duration(fwd_wait);
      //remove power
      break;
    case 2: //reverse pulse
    state_duration(rev_pulse);
      //set dac
      //apply power
      break;
    case 3: //waiting period reverse->forward
    state_duration(rev_wait);
      //remove power
      break;
  }

  
}

//=============================================================================================
//=============================================================================================
//                                   SERIAL COMMUNICATIONS
//=============================================================================================
//=============================================================================================
void receive_command() {
  String command = Serial.readStringUntil('\n');

  if (command.substring(0, command.indexOf(":")) == "SCANV") { //Start a voltage scan
    Serial.println("STARTING VOLTAGE SCAN");
    scanning = true; //initiate scan
    session_start_time=millis();
    fwd_voltage_scan(true);
    //startTimer(TC1, 0, TC3_IRQn, 50); //TC1 channel 0, is sensor sample rate
    log_rate = 200;
  }
  if (command.substring(0, command.indexOf(":")) == "SCANI") { //start a current scan
    session_start_time = millis();
    scanning = true; //initiate scan
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
    session_start_time = millis();
    startTimer(TC1, 0, TC3_IRQn, 50); //TC1 channel 0, is serial send timer and sensor sample rate set to 50Hz
    log_rate = 200;
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
  Serial.print(total_charge_transfer);
  Serial.print(":");
  Serial.println(sample_time);

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
  Serial.println("STARTING POLISH CYCLE, CHARGE LIMIT - ");
  Serial.println(charge_target);
  polishing = true;
  return;
}
//=============================================================================================
//=============================================================================================
void fwd_voltage_scan(boolean electrode) { //scanrate in volts per second electrode to scan (outer = true)
  scan_limit = max_voltage;
  scan_dir = true; //set scan direction positive
  dacUp(min_voltage, 500);

  if (electrode) { //outer electrode selected
    volt_step = volt_sec / 100;
    startTimer(TC1, 1, TC4_IRQn, 100); //start scan with an update rate of 100hz
  }
  return;
}


//=============================================================================================
//=============================================================================================
void dacUp(float voltage, int current) {
  current_voltage = voltage;
  current_current = current;
  unsigned int v_dig = int(round(voltage * v_factor));
  float VLim = 4.75-13750.0*(float(current)/1000.0)/15000.0;
  VLim = VLim/1.181; //correct for amplifier gain to obtain 4.75V-(0A) (close to 5V rail).
  //float VLim = 4.75-31600.0*(float(current)/1000.0)/5000.0;
  
  unsigned int i_dig = int((VLim/4.096)*4095.0);

  //unsigned int i_dig = map(int(VLim), 0, 40960, 0, 4095);//int(round(current*i_factor));
  //Serial.println("AKSHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHF");
  //Serial.println(i_dig);
  //Serial.println(v_dig);
  //Serial.println(i_dig);

  //write new values to mcp dac channels A and B with synchronous update enabled
  VIdac.analogWrite(0, 0, 0, 1, v_dig);
  VIdac.analogWrite(1, 0, 0, 1, i_dig);
  digitalWrite(ldac, LOW);
  delay(2);
  digitalWrite(ldac, HIGH); //synchronous update

  return;
}


//=============================================================================================
//=============================================================================================

//=============================================================================================
//=============================================================================================

//=============================================================================================
//                                Sensor Sampling
//=============================================================================================


//=============================================================================================
//                                Timer Interrupts
//=============================================================================================
//TC1 ch 0
void TC3_Handler()
{
  TC_GetStatus(TC1, 0);
  waveUpdate = true; //set flag for electrical parameter sample collection
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
//state_duration sets TC5 to rollover after given number of microseconds (around 1 usec accuracy)
//=============================================================================================
void state_duration(float u_sec){
  uint32_t freq = int(1000000.0/u_sec);
  startTimer(TC1, 2, TC5_IRQn, freq); //TC1 channel 2, is pulse state duration timer
  
}
//=============================================================================================
//=============================================================================================
void TC5_Handler()
{
  TC_GetStatus(TC1, 1);
  matterState+=1;
  stateChange=true;

  return;
}
//=============================================================================================
//startTimer and stopTimer functions written by nameless open source codera
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

