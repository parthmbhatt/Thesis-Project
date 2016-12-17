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


