#include <SPI.h>
#include <MCP492X.h>
#include <Wire.h>
#include "Configuration.h"
#include "Waveforms.h"

MCP492X VIdac(dac_cs);

  /*1.42 = -0.5V
   * 1.58 = 0.5V
   * centred around 1.5V
   * formula
   * (Ain - 1.5)/0.16
   * 
   *
   */

//=============================================================================================
//=============================================================================================
//                                      SETUP
//=============================================================================================
//=============================================================================================

void setup(void)
{
  analogReadResolution(12);
  pinMode(ldac, OUTPUT);
  pinMode(A7, INPUT);

  //put the outputs to sleep and set PWM off to begin with

  digitalWrite(ldac, HIGH);

  Serial.begin(115200);

  uint32_t currentFrequency;


  VIdac.begin();
  delay(5);
  startTimer(TC1, 0, TC3_IRQn, updateRate); //TC1 channel 0, is update rate
  startTimer(TC1, 1, TC4_IRQn, sampleRate); //TC1 channel 1, is sample rate

  VIdac.analogWrite(0, 0, 0, 1, 0);
  VIdac.analogWrite(1, 0, 0, 1, 2048);
  digitalWrite(ldac, LOW);
  delay(2);
  digitalWrite(ldac, HIGH); //synchronous update
//  i_update(2); 
}

//=============================================================================================
//=============================================================================================
//                                      START OF MAIN LOOP
//=============================================================================================
//=============================================================================================
void loop(void)
{
  /*i_out=2048;
    VIdac.analogWrite(0, 0, 0, 1, 2048);
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  sampleV();
  */
    if (waveUpdate) {
      waveUpdate = false;
      i_sin();
 

     }

 /* 
fwd_pulse();

fwd_interval();

rev_pulse();
*/
      
  }
//=============================================================================================
//=============================================================================================
//                                      END OF MAIN LOOP
//=============================================================================================
//=============================================================================================
void fwd_sin(){
    VIdac.analogWrite(0, 0, 0, 1, 2048);//set current to 0 for interval period
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update

  float cell_v = get_avg();
  int array_cap=0;

  i_out=2048;
Serial.print("FWD : ");
  while((cell_v < fwd_limit) || array_cap < smoothArrayLen ){ //smoothArrayLen ){//======================================================================= forward pulse limit voltage
   array_cap++;
    if (waveUpdate) {
      waveUpdate = false;
      i_sin();
     }
      if(sampleFlag){ //sample at intervals set by timer overflow
        sampleFlag= false;
        sampleV();
         cell_v = get_avg();
         //cell_v = rolling_avg[cRollingCount];
         //Serial.println(cell_v);
      }
  }
  Serial.print("FWD : ");
 // Serial.println(cell_v);
  return;
}
//=============================================================================================
//                                   Pulse Functions
//=============================================================================================
void fwd_pulse(){
    VIdac.analogWrite(0, 0, 0, 1, 2048);//set current to 0 for interval period
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  //wait for lower threshold voltage
  float cell_v = get_avg();
  int array_cap=0;
  //delayMicroseconds(500);
  i_out=2048;
  //Serial.println("FWD PULSE");
  while((cell_v < fwd_limit) || array_cap < smoothArrayLen ){ //smoothArrayLen ){//======================================================================= forward pulse limit voltage
   array_cap++;
    if (waveUpdate) {
      waveUpdate = false;
      //i_inc();
      i_sin();
     }
      if(sampleFlag){ //sample at intervals set by timer overflow
        sampleFlag= false;
        sampleV();
         cell_v = get_avg();
         //cell_v = rolling_avg[cRollingCount];
         //Serial.println(cell_v);
      }
  }
  //Serial.print("FWD : ");
 // Serial.println(cell_v);
  return;
}
//=============================================================================================
//=============================================================================================
void fwd_interval(){
  VIdac.analogWrite(0, 0, 0, 1, 2048);//set current to 0 for interval period
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  //delayMicroseconds(5000);
  int array_cap=0;
  unsigned long interval_start = micros();
  unsigned long interval_timer = micros();
  while(((ocp > interval_limit) || (array_cap < smoothArrayLen)) && (interval_timer-interval_start) < 2500 ){
    array_cap++;
    interval_timer = micros();
      if(sampleFlag){ //sample at intervals set by timer overflow
        sampleFlag= false;
        sampleV();
         ocp = get_avg();
         //cell_v = rolling_avg[cRollingCount];
         //Serial.println(ocp);
      }
  }
 //Serial.print("INTERVAL: ");
  //Serial.println(ocp);
  return;  
}
//=============================================================================================
void rev_pulse(){
  i_out=2048;
 // Serial.print("REV : ");
  VIdac.analogWrite(0, 0, 0, 1, 2048);//set current to 0 for interval period
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  //wait for upper threshold voltage
  float cell_v = get_avg();
  //delayMicroseconds(500);
  int array_cap=0;
  while((cell_v > rev_limit) || (array_cap < smoothArrayLen)){ //smoothArrayLen){//======================================================================= forward pulse limit voltage
    array_cap++;
    if (waveUpdate) {
      waveUpdate = false;
      i_dec();
 
      //Serial.println(get_avg());
     }
      if(sampleFlag){ //sample at intervals set by timer overflow
        sampleFlag= false;
        sampleV();
         cell_v = get_avg();
         //cell_v = rolling_avg[cRollingCount];
         //Serial.println(cell_v);
      }
  }
  //Serial.print("REV : ");
  //Serial.println(cell_v);
  return;
}
  //=============================================================================================
//=============================================================================================
void i_inc(){
  i_out+=iSlope;
  if(i_out>3072){
    i_out=3072;
  }
  VIdac.analogWrite(0, 0, 0, 1, i_out);
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  
  return;
}
//=============================================================================================
//=============================================================================================
void i_dec(){
  i_out-=iSlope;
  if(i_out<1024){
    i_out=1024;
  }
  VIdac.analogWrite(0, 0, 0, 1, i_out);
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  
  return;
}
//=============================================================================================
//=============================================================================================
void i_sin(){
  i_out+=iSlope;
  if(i_out>1800){
    i_out=0;
  }
  VIdac.analogWrite(0, 0, 0, 1, int((sin(float(i_out)/10.0)*1000.0)+2000.0));
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  
  return;
}
//=============================================================================================
//                                   Other functions
//=============================================================================================
void sampleV(){
  rolling_avg[cRollingCount] = -(float((analogRead(A7))*(3.3/4096.0))/0.1535-10.0); //input amplifier gain  = 0.1535
  cRollingCount += 1;
  if(cRollingCount >= smoothArrayLen){
    cRollingCount = 0;
  }
  //Serial.println(get_avg());
  //Serial.println(float((analogRead(A7))*(3.3/4096))/0.1535-10.0));
}
  //=============================================================================================
//=============================================================================================
float get_avg(){
  float sense_avg=0.0;
  for(int i=0; i < smoothArrayLen; i++){
    sense_avg += rolling_avg[i];
  }
  sense_avg=sense_avg/smoothLen;
  return(sense_avg);
}
  //=============================================================================================
//=============================================================================================
void wave_update() {
  //Serial.println("update");
  VIdac.analogWrite(0, 0, 0, 1, waveformsTable[1][wavePos]);
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update

  //Serial.println(waveformsTable[2][wavePos]);
 wavePos++;
  if(wavePos == maxSamplesNum){  // Reset the counter to repeat the wave
    wavePos = 0;}
  return;
}
//===============================================================================================
void square_wave(){

 if(on){
  VIdac.analogWrite(0, 0, 0, 1, 3015);// current output = (2015+x)/100
  on=false;
 }
 else{
  VIdac.analogWrite(0, 0, 0, 1, waveformsTable[1][wavePos]);// current output = (2005-x)/100
  on=true;
 }
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); //synchronous update
  return;
  
}

//=============================================================================================
//                                   
//=============================================================================================
void hold_volt(){
      current_voltage = analogRead(A7);
      if(current_voltage>1300){
        current_i+=-0.1;
        //i_update(current_i);
      }
        current_voltage = analogRead(A7);
      if(current_voltage<1300){
        current_i+=0.1;
        //i_update(current_i);
      }
  return;
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


    //startTimer(TC1, 0, TC3_IRQn, 50); //TC1 channel 0, is sensor sample rate

  }
  if (command.substring(0, command.indexOf(":")) == "SCANI") { //start a current scan

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
   // run_process(max_current, command.substring(command.indexOf(":") + 1).toFloat());

    startTimer(TC1, 0, TC3_IRQn, 50); //TC1 channel 0, is serial send timer and sensor sample rate set to 50Hz

  }
  return;

}
void send_sample() {
  /*Serial.print("data:");
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
  Serial.println(sample_time);*/

  return;
}

//=============================================================================================
//=============================================================================================
//=============================================================================================
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
  sampleFlag = true;
  //sampleV();
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
//startTimer and stopTimer functions were written by a nameless open source coder
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
