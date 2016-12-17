//Initialize Limit Switch variables
int LimitSwitchPin=4;
bool LimitFlag = LOW;

//Initialize buttons 1 & 2
int Button1Pin=2;
int Button2Pin=3; 
int Button1State=LOW;
int Button2State=LOW;

//Initialize motor control pins 1 & 2
int Motor1Pin=9;
int Motor2Pin=11;

int Motor1State=LOW;  //(do I need this?)
int Motor2State=LOW;

//Initialize Timing variables
unsigned long previousMillis=0;
const long MotorRunTime=24000;



// Initialize Wii Board readers
int analogPin1=0;
int analogPin2=1;
float ValA=0;
float ValB=0;

bool SuccessFlag=LOW;
int SuccessTimer=0;

//Initialize Top and Bottom Throesholds for load cell values
const int TopThreshold1=780;
const int BottomThreshold1=600;
const int TopThreshold2=500;
const int BottomThreshold2=400;


// Define Averaging function constants
const int numReadings=50;
int readingsA[numReadings];
int readingsB[numReadings];
int readIndex=0;
int totalA=0;
int totalB=0;
int averageB=0;
int averageA=0;

//initialize screen counter
int Screen=4;
int PrevScreen=Screen;




void setup()
{
  Serial.begin(9600);          //  setup serial

   pinMode(Button1Pin,INPUT);   // Define button pins as inputs
   pinMode(Button2Pin,INPUT);
  
   pinMode(Motor1Pin,OUTPUT);   // Define motor control pins as outputs
   pinMode(Motor2Pin,OUTPUT);


  pinMode(LimitSwitchPin,INPUT); //Define Limit Switch as input

                 //Completely retract the mechanism


  

// Fill the array with 0's
for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsA[thisReading] = 0;
    readingsB[thisReading] = 0;
  }
}
  


void loop()
{
  //Serial.println(Screen);


  ExtendArm();
  
 
}
 





//Motor Reset function
void ResetAngle(){
  int LimitSwitchState=digitalRead(LimitSwitchPin);
     if(LimitSwitchState==LOW && LimitFlag==LOW){
      RetractArm();
      Serial.println("Resetting");
      Serial.println(LimitFlag);
      delay(1000);
      LimitSwitchState=digitalRead(LimitSwitchPin);
      }
      if(LimitSwitchState==HIGH){
        Serial.println("ResetDone");
        LimitFlag=HIGH;
      }
}



//Motor Control Functions
void RetractArm(){
  digitalWrite(Motor1Pin,LOW);
  digitalWrite(Motor2Pin,HIGH);
}

void ExtendArm(){
  digitalWrite(Motor1Pin,HIGH);
  digitalWrite(Motor2Pin,LOW);
}

void StopArm(){
  digitalWrite(Motor1Pin,LOW);
  digitalWrite(Motor2Pin,LOW);
}

// TITLE Screen function
void Screen0(){
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);

    // Button1 is 'yes'
    if(Button1State==HIGH){
      Serial.println("B");
      Screen=1;
      delay(500);
    }
    // Button2 is 'No'
    if(Button2State==HIGH){
      Serial.println("C");
      Screen=2;
      delay(500);
    }
}

// INSTRUCTIONS screen function 
void Screen1(){
  Button1State=digitalRead(Button1Pin);
  Button2State=digitalRead(Button2Pin);

    // Button1 is 'next'
    if(Button1State==HIGH){
      Serial.println("C");
      Screen=2;
      delay(500);
    }
    // Button2 is 'next'
    if(Button2State==HIGH){
      Serial.println("C");
      Screen=2;
      delay(500);
    }
}

// CALIBRATE? question Function

  void Screen2(){
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);

    // Button1 is 'yes'
    if(Button1State==HIGH){
      Serial.println("D");
      Screen=3;
      delay(500);
    }
    // Button2 is 'No'
    if(Button2State==HIGH){
      Serial.println("E");
      Screen=4;
      delay(500);
    }
  }


//CALIBRATE Funtcion
  void Screen3(){
int Range = TopThreshold1-BottomThreshold1;
    if(digitalRead(LimitSwitchPin)==LOW){
    ResetAngle();
    }
    else if(digitalRead(LimitSwitchPin)==HIGH){
      LimitFlag=HIGH;
    }

    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);

   if(analogRead(analogPin1)>=(BottomThreshold1+0.1*Range)){
    ExtendArm();
    }
    else if(analogRead(analogPin1)<(BottomThreshold1+0.1*Range)){
    StopArm();
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);
                if((Button1State==HIGH) || (Button2State==HIGH)){
                  Serial.println("E");
                  Screen=4;
                  delay(500);
                  } 
    }
  
}

// GAME function
void Screen4(){
  if(SuccessFlag==LOW){
 ValA=(analogRead(analogPin1));
 ValB=(analogRead(analogPin2)); 

 average();
 ValA=map(analogRead(analogPin1),BottomThreshold1,TopThreshold1,860,0);
 ValB=map(analogRead(analogPin2),BottomThreshold2,TopThreshold2,860,0);
 // read the input pin
   
  Serial.print(ValA);
  Serial.print(" ");
  Serial.println(ValB);

  delay(50);
  if( (ValA < 496) &&(ValA>368) ) {
    SuccessTimer++;
    if(SuccessTimer>=208){
      SuccessFlag=HIGH;
      Screen=5;
       Serial.print("9999");
       Serial.print(" ");
       Serial.println("9999");
      }
  }
  }

  
  
}

// RESET/REPLAY option Function
void Screen5(){
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);
    

    // Button1 is 'Reset'
    if(Button1State==HIGH){
      Serial.println("A");
      Screen=0;
      delay(500);
    }
    // Button2 is 'Replay'
    if(Button2State==HIGH){
      Serial.println("C");
      Screen=2;
      delay(500);
    }
}


void average(){
 // subtract the last reading:
  totalA = totalA - readingsA[readIndex];
  totalB= totalB - readingsB[readIndex];
  // read from the sensor:
  readingsA[readIndex] = analogRead(analogPin1);
  readingsB[readIndex] = analogRead(analogPin2);
  // add the reading to the total:
  totalA = totalA + readingsA[readIndex];
  totalB = totalB + readingsB[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
ValA=totalA/numReadings;
ValB=totalB/numReadings;
}



