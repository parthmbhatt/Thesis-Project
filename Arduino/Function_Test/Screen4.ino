// GAME function
void Screen4(){
  if(SuccessFlag==LOW){
 //ValA=(analogRead(analogPin1))
 ValA=(map(hx711.read(),BottomThreshold1,TopThreshold1,1080,-220));
 //ValB=(analogRead(analogPin2)); 

// average();
 //ValA=map(ValA,BottomThreshold1,TopThreshold1,0,1080);
// ValB=map(ValB,BottomThreshold2,TopThreshold2,980,-220);
 // read the input pin
   
  Serial.print(ValA);
  Serial.print(" ");
  Serial.println(SuccessTimer);

  delay(0);
  if( (ValA <604) &&(ValA>476) ) {
    SuccessTimer++;
    if(SuccessTimer>=125){
      SuccessFlag=HIGH;
      Screen=5;
      delay(3000);
       Serial.print("9999");
       Serial.print(" ");
       Serial.println("9999");
      }
  }
  }

  
  
}

