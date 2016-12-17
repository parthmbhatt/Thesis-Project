// CALIBRATE? question Function
void Screen2(){
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);

    // Button1 is 'yes'
    if(Button1State==HIGH){
      Serial.println("D");
      Screen=3;
      LimitFlag=LOW;
      delay(500);
    }
    // Button2 is 'No'
    if(Button2State==HIGH){
      Serial.println("E");
      Screen=4;
      SuccessFlag=LOW;
      SuccessTimer=0;
      
      delay(500);
    }
  }

