int analogPin1 = A4;     
int analogPin2 =A1;                      
float ValA = 0;    
float ValB= 0;      

const int numReadings=20;

int readingsA[numReadings];
int readingsB[numReadings];

int readIndex=0;

int totalA=0;
int totalB=0;

int averageB=0;
int averageA=0;
 
void setup()
{
  Serial.begin(9600);          //  setup serial

for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsA[thisReading] = 0;
    readingsB[thisReading] = 0;
  }
}
  


void loop()
{
 ValA=(analogRead(analogPin1));
 ValB=(analogRead(analogPin2)); 

 //average();
 //ValA=map(analogRead(analogPin1),600,780,860,0);
// ValB=map(analogRead(analogPin2),400,500,1500,500);
 // read the input pin
   
  Serial.print(ValA);
  Serial.print(" ");
  Serial.println(ValB);
  delay(1);
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
