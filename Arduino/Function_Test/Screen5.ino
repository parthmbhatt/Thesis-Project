// RESET/REPLAY option Function
void Screen5(){
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);
    

    // Button2 is 'Reset'
    if(Button2State==HIGH){
      Serial.println("A");
      Screen=0;
      delay(500);
    }
    // Button1 is 'Replay'
    if(Button1State==HIGH){
      Serial.println("C");
      Screen=2;
      delay(500);
    }
}

