#include <Wire.h>
#include <Adafruit_INA219.h>
#include "Configuration.h"

Adafruit_INA219 ina219(0x40);


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

//put the outputs to sleep and set PWM off to begin with
digitalWrite(m1slp, LOW);
digitalWrite(m2slp, LOW);
digitalWrite(m1pwm, LOW);
digitalWrite(m2pwm, LOW);
digitalWrite(m1dir, LOW);
digitalWrite(m2dir, LOW);

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
  pinMode(13,OUTPUT);
  startTimer(TC1, 0, TC3_IRQn, 10); //TC1 channel 0, the IRQ for that channel and the desired frequency
  //digitalWrite(13, HIGH);
  m1_switch(on, AtoB);
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


  //delay(50);
  
 // m1_ground();
 //m1_switch(off, AtoB);

}

//=============================================================================================
//=============================================================================================
//                                   POWER CONTROL FUNCTIONS
//=============================================================================================
//=============================================================================================
void m1_switch(boolean state, boolean dir){

  //first set the direction
  if(dir){
    Serial.println("Current flow A to B");
    digitalWrite(m1dir, LOW);} //current flow A to B
  else{
    digitalWrite(m1dir, HIGH);}

  //set pwm value and switch the sleep bit
  if(state){
    Serial.println("Waking up and turning full on");
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
  
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");
  return;
}

//=============================================================================================
//                                Timer Interrupts
//=============================================================================================
//TC1 ch 0
void TC3_Handler()
{
        TC_GetStatus(TC1, 0);

        iv_sample=true; //set flag for electrical parameter sample collection
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

