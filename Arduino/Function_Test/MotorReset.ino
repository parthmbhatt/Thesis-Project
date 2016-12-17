//Motor Reset function
void ResetAngle(){
  int LimitSwitchState=digitalRead(LimitSwitchPin);
     if(LimitSwitchState==LOW && LimitFlag==LOW){
      RetractArm();
      Serial.println("Resetting");
      //Serial.println(LimitFlag);
      delay(1000);
      LimitSwitchState=digitalRead(LimitSwitchPin);
      }
      if(LimitSwitchState==HIGH){
        Serial.println("ResetDone");
        LimitFlag=HIGH;
      }
}

