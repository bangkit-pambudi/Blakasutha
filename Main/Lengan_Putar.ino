void LenganPutar(){
if (ps2x.Button(PSB_L2) && ps2x.Button(PSB_SQUARE)) { //L2 + Kotak
    Serial.println("Motor memutar ke belakang");
    analogWrite(roller_pwm1, 60);
    analogWrite(roller_pwm2, 0);
  }else if (ps2x.Button(PSB_L2) && ps2x.Button(PSB_TRIANGLE)){ //L2 + Segitiga
    Serial.println("Motor memutar ke depan");
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 60);  
  } else {
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 0);}
}
