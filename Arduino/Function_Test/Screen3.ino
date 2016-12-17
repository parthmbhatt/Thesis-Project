//CALIBRATE Funtcion
  void Screen3(){
long Range = TopThreshold1-BottomThreshold1;
    if(digitalRead(LimitSwitchPin)==LOW){
    ResetAngle();
    }
    else if(digitalRead(LimitSwitchPin)==HIGH){
      LimitFlag=HIGH;
    }

    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);

   if(hx711.read()>=(BottomThreshold1+0.1*Range)){
    ExtendArm();
    }
    else if(hx711.read()<(BottomThreshold1+0.1*Range)){
    StopArm();
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);
                if((Button1State==HIGH)){
                  Serial.println("E");
                  Screen=4;
                  SuccessFlag=LOW;
                  SuccessTimer=0;
                  delay(500);
                  } 

                  else if(Button2State==HIGH){
                    ResetAngle();
                    LimitFlag=0;
                  }
    }
  
}

