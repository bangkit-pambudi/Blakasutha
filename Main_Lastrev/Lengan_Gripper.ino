void Lengan(){
if(ps2x.Button(PSB_R2)){
 if(ps2x.Button(PSB_SQUARE)){ //R2 + Kotak
    Serial.println("Tangan Turun");
    digitalWrite(relay6, LOW);
  }else{
    digitalWrite(relay6, HIGH);
  } 

   if(ps2x.Button(PSB_TRIANGLE)){ //R2 + Segitiga
    Serial.println("Tangan Naik");
    digitalWrite(relay7, LOW);
  }else{
    digitalWrite(relay7, HIGH);
  }

  if(ps2x.Button(PSB_CROSS)) {
    Serial.println("Motor memutar ke belakang");
    analogWrite(roller_pwm1, 60);
    analogWrite(roller_pwm2, 0);
  }else if (ps2x.Button(PSB_CIRCLE)){
    Serial.println("Motor memutar ke depan");
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 60);  
  }else{
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 0);}
}
}
