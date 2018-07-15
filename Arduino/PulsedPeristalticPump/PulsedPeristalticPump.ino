#include <TimerOne.h>
#include <LiquidCrystal.h>

#define rotations 3
#define steps_rev 800
#define EN 2
#define DIR 3
#define PULSE 12
#define HALL 13

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel

int lcd_key     = 0;
int adc_key_in  = 0;

unsigned long lcdTim=0;
unsigned long pulseWidth=100000;
int rpm = 0;
int steprate =1000;

//================================================================================================
void setup() {
Serial.begin(115200);
Serial.println("RUNNING ONE ROTATION");

pinMode(EN, OUTPUT);
pinMode(DIR, OUTPUT);
pinMode(PULSE, OUTPUT);
//pinMode(HALL, INPUT_PULLUP); //open collector hall effect switch (N/O switch to gnd)

digitalWrite(EN, LOW);
digitalWrite(DIR, LOW);

lcd.begin(16, 2);               // start the library



}
//================================================================================================
void loop() {

  delay(100);
      if(millis() - lcdTim > 200){         // output a temperature value per 500ms 
             lcdTim = millis();
            lcd.clear();
            lcd.setCursor(0,0);
             lcd.print("SPEED: ");               
             lcd.print(rpm);             
             lcd.print(" rpm");              
     } 
     
   lcd_key = read_LCD_buttons();   // read the buttons
   switch (lcd_key){               // depending on which button was pushed, we perform an action

       case btnRIGHT:{             //  push button "RIGHT" and show the word on the screen
            rpm+=1;
            rpmUp();
            delay(200);
            break;
       }
       case btnLEFT:{
            rpm+=-1;
            if(rpm<0){rpm=0;}
            rpmDown();
            delay(200);
             break;
       }    
       case btnUP:{
            rpm+=10;
            rpmUp();
            delay(200);
             break;
       }
       case btnDOWN:{
            rpm+=-10;
            if(rpm<0){rpm=0;}
            rpmDown();
            delay(200);
             break;
       }
       case btnSELECT:{
            rpmStart();
             break;
       }
       case btnNONE:{

             break;
       }
   }
   
/*
    if(millis() - lcdTim > 100){         // output a temperature value per 500ms 
             lcdTim = millis();
             // print the results to the lcd
             lcd.setCursor(0, 0);
             lcd.print("Speed: ");               
             lcd.print(rpm);             
             lcd.print("  rpm");              
     } 
*/
}

//================================================================================================
int read_LCD_buttons(){               // read the buttons
    adc_key_in = analogRead(0);       // read the value from the sensor 

    // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
    // we add approx 50 to those values and check to see if we are close
    // We make this the 1st option for speed reasons since it will be the most likely result

    if (adc_key_in > 1000) return btnNONE; 

    // For V1.1 us this threshold
    if (adc_key_in < 50)   return btnRIGHT;  
    if (adc_key_in < 250)  return btnUP; 
    if (adc_key_in < 450)  return btnDOWN; 
    if (adc_key_in < 650)  return btnLEFT; 
    if (adc_key_in < 850)  return btnSELECT;  

   // For V1.0 comment the other threshold and use the one below:
   /*
     if (adc_key_in < 50)   return btnRIGHT;  
     if (adc_key_in < 195)  return btnUP; 
     if (adc_key_in < 380)  return btnDOWN; 
     if (adc_key_in < 555)  return btnLEFT; 
     if (adc_key_in < 790)  return btnSELECT;   
   */

    return btnNONE;                // when all others fail, return this.
}
//============================================================================
void rpmUp(){
Timer1.initialize(int(150000.0/float(rpm))); // 60mil/(rpm*stepsPerRev)

}
//============================================================================
void rpmDown(){
Timer1.initialize(int(150000.0/float(rpm))); //60mil/(rpm*stepsPerRev)
}
//============================================================================
void rpmStart(){

  Timer1.initialize(int(150000.0/float(rpm))); // 60mil/(rpm*stepsPerRev)
  Timer1.attachInterrupt(step_isr);

}
//============================================================================
void rpmStop(){
  Timer1.detachInterrupt();
  
}
//================================================================================================
void step_isr(void){
  digitalWrite(PULSE, digitalRead(PULSE) ^ 1); //switch pulse pin level this means the steprate is 1/2 timer interrupt rate
}

