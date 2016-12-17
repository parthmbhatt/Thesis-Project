// TITLE Screen function
void Screen0(){
    Button1State=digitalRead(Button1Pin);
    Button2State=digitalRead(Button2Pin);

    // Button1 is 'hear the intro'
    if(Button1State==HIGH){
      Serial.println("B");
      Screen=1;
      delay(500);
    }
    // Button2 is 'skip the intro'
    if(Button2State==HIGH){
      Serial.println("C");
      Screen=2;
      delay(500);
    }
}

