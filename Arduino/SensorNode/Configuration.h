//=============================================================================================
//                                      Pin definitions
//=============================================================================================

#define m1flt 6
#define m2flt 12
#define m1slp 2 //when slp is low the outputs are in high impedance mode
#define m2slp 4
#define m1dir 7 //when dir is low current flows from A to B
#define m2dir 8
#define m1pwm 9 //when pwm is low both outputs are grounded
#define m2pwm 10
#define dac_cs 44
#define ldac 42
#define Vdac 0
#define Idac 1
//=============================================================================================
//                                      constants
//=============================================================================================
#define v_factor 99.55


//=============================================================================================
//                                      Flags
//=============================================================================================
volatile boolean iv_sample = false;
volatile boolean output_update_flag = false;
boolean scan_complete = true; //flipped to false to initiate a scan flipped to tru when scan complete
boolean scan_dir = true;
boolean ds_flag = true;



//=============================================================================================
//                                      word variables
//=============================================================================================

boolean on = true;
boolean off = false;
boolean AtoB = true;
boolean BtoA = false;

//=============================================================================================
//                                      Global Variables
//=============================================================================================


//sense variables
float oe_voltage = 3.2;
float oe_current = 156.32;
float ie_voltage = 2.1;
float ie_current = 15.67;
float surf_temp = 10.2;
float el_flow = 3.2;
float total_charge_transfer = 0.0; //dummy value this will be calculated on the pi side

//variables for potentiodynamic sweeps
float volt_step = 0.0;
float scan_limit = 0.0;

//power control variables
float current_voltage = 0.0; // this is the output voltage of the OPA regulator not the cell voltage
int current_current = 0;
float max_voltage=0;
float min_voltage=0;
float max_current=0;
float min_current=0;

unsigned long current_time = 0;
unsigned long previous_time = 0;

volatile boolean l;

