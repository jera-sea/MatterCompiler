//=============================================================================================
//                                      Pin definitions
//=============================================================================================


#define dac_cs 42
#define ldac 44
#define Vdac 0 /
#define Idac 1 //opposite of Vdac

#define smoothLen 5.0
#define smoothArrayLen 5

#define updateRate 1000
#define sampleRate 10000

#define iSlope 1 //rise time of current waveform in units of Amps/updateRate
#define v_factor 99.55

#define interval_limit 0.0
#define fwd_limit 1
#define rev_limit -0.5
//=============================================================================================
//                                      Flags
//=============================================================================================
volatile boolean sampleFlag = false;
volatile boolean waveUpdate = false;
boolean scanning = false;

boolean on = true;
boolean v_lim = true;
//=============================================================================================
//                                      Array Variables
//=============================================================================================
float rolling_avg[smoothArrayLen];
int cRollingCount = 0; //variable storing current smoothing array location
//=============================================================================================
//                                      Global Variables
//=============================================================================================
float current_i=0;
float ocp = 0;

//power control variables
float current_voltage = 0.0; // this is the output voltage of the OPA regulator not the cell voltage
int i_out = 0;
float max_voltage=0;
float min_voltage=0;
float max_current=0;
float min_current=0;
float volt_sec=0; //rate of change of voltage during a forward voltage scan in V/s
float fwd_wait =0; //wait time in ms between forward and reverse pulses
float rev_wait=0; //wait time in ms between reverse and forward pulse



volatile byte matterState=0;
volatile boolean stateChange = false;


unsigned long current_time = 0;
unsigned long previousSER_time = 0;
unsigned long previous_accumulation=0;
unsigned long sample_time=0;

int wavePos = 0;

volatile boolean l;
