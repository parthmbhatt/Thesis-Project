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

