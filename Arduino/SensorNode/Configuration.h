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
//high 548 
//#define Vdac 0
//#define Idac 1
//low 547
#define Vdac 1
#define Idac 0

#define smoothLen 10
//=============================================================================================
//                                      constants
//=============================================================================================
#define v_factor 99.55


//=============================================================================================
//                                      Flags
//=============================================================================================
volatile boolean iv_sample = false;
volatile boolean output_update_flag = false;
boolean scanning = false;
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
float oe_current[10];
float oe_current_s=0;
float ie_voltage = 2.1;
float ie_current = 15.67;
float surf_temp = 10.2;
float el_flow = 3.2;
float total_charge_transfer = 0.0; //dummy value this will be calculated on the pi side
float charge_target = 0;

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
float volt_sec=0; //rate of change of voltage during a forward voltage scan in V/s
float fwd_wait =0; //wait time in ms between forward and reverse pulses
float rev_wait=0; //wait time in ms between reverse and forward pulse
float fwd_pulse=0; //forward pulse duration
float rev_pulse=0; //reverse pulse duration

byte matterState=0;
boolean stateChange = false;


unsigned long current_time = 0;
unsigned long previousDS_time = 0;
unsigned long previousSER_time = 0;
unsigned long previous_accumulation=0;
unsigned long sample_time=0;
unsigned long session_start_time=0;
unsigned long log_rate = 250;

int cRollingCount = 0; //variable storing current smoothing array location

volatile boolean l;
boolean polishing = false;

