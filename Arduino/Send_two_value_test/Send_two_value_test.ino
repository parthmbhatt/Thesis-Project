/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int ValA=0;
int ValB=100;
int i=1;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  if(ValA<100){
    ValA=ValA+i;
    ValB=ValB-i;
    i++;
  
  Serial.print(ValA);
  Serial.print(" ");
  Serial.println(ValB);
  delay(1);     
    }
    else if(ValA>=100){
    i=1;
    ValA=ValA-i;
    ValB=ValB+i;
    i++;  
  
  
  Serial.print(ValA);
  Serial.print(" ");
  Serial.println(ValB);
  delay(1);     
    }
}
  // print out the state of the button:
  



