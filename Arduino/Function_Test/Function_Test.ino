#include <Q2HX711.h>
const byte hx711_data_pin = A2;
const byte hx711_clock_pin = A3;
Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);


//Initialize Limit Switch variables
int LimitSwitchPin=4;
bool LimitFlag = LOW;

//Initialize buttons 1 & 2
int Button1Pin=3; //WHITE BUTTON
int Button2Pin=2; //BLUE BUTTON
int Button1State=LOW;
int Button2State=LOW;

//Initialize motor control pins 1 & 2
int Motor1Pin=9;
int Motor2Pin=10;

int Motor1State=LOW;  //(do I need this?)
int Motor2State=LOW;

//Initialize Timing variables
unsigned long previousMillis=0;
const long MotorRunTime=24000;



// Initialize Wii Board readers
int analogPin1=A0;
int analogPin2=A1;
long ValA=0;
long ValB=0;

bool SuccessFlag=LOW;
int SuccessTimer=0;

//Initialize Top and Bottom Throesholds for load cell values
const long TopThreshold1=9420000;
const long BottomThreshold1=9340500;
//const int TopThreshold2=800;
//const int BottomThreshold2=660;


// Define Averaging function constants
const int numReadings=10;
long readingsA[numReadings];
int readingsB[numReadings];
long readIndex=0;
long totalA=0;
long totalB=0;
long averageB=0;
long averageA=0;

//initialize screen counter
int Screen=0;
int PrevScreen=Screen;




void setup()
{
  Serial.begin(9600);          //  setup serial

   pinMode(Button1Pin,INPUT);   // Define button pins as inputs
   pinMode(Button2Pin,INPUT);
  
   pinMode(Motor1Pin,OUTPUT);   // Define motor control pins as outputs
   pinMode(Motor2Pin,OUTPUT);


  pinMode(LimitSwitchPin,INPUT); //Define Limit Switch as input

   RetractArm();                 //Completely retract the mechanism


  

// Fill the array with 0's
for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsA[thisReading] = 0;
    readingsB[thisReading] = 0;
  }
}
  


void loop()
{
  //Serial.println(Screen);
Button1State=digitalRead(Button1Pin);
Button2State=digitalRead(Button2Pin);

  
  switch (Screen){
   
    //case 0 is the title screen
    case 0:
    {
      Screen0();
       break;
    }
//Screen1 is the instruction screen
    case 1:
    {
      Screen1();
       break;
    }
// Sceeen2 is the Calibrate question screen
    case 2:
    {
      Screen2();
       break;
    }
// Screen3 is the Calibration question Screen
    case 3:
    {
      Screen3();
       break;
    }
//Screen4 is the Game screen
    case 4:
    {
      Screen4();
       break;
    }
    
//Screen5 is the Reset/Replay screen
    case 5:
    {
      Screen5();
       break;
    }
 }
 
}

