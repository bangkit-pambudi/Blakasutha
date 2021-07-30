void Shooter(){
if( ps2x.ButtonPressed(PSB_TRIANGLE)){ //R2 + Segitiga
    Serial.println("Lempar kecepatan 1");
    analogWrite(shooter_pwm1, 100);
    delay(300);
    analogWrite(shooter_pwm2, 0);
  } else if( ps2x.ButtonPressed(PSB_CIRCLE)){ //R2 + O
    Serial.println("Lempar kecepatan 2");
    analogWrite(shooter_pwm1, 180);
    delay(300);
    analogWrite(shooter_pwm2, 0);
  } else if ( ps2x.ButtonPressed(PSB_CROSS)) { //R2 + X
    Serial.println("Lempar kecepatan 3");
    analogWrite(shooter_pwm1, 210);
    delay(300);
    analogWrite(shooter_pwm2, 0);
  } else if (ps2x.Button(PSB_R2) && ps2x.Button(PSB_SQUARE)){ //R2 + Kotak
    Serial.println("Motor mutar ke belakang");
    analogWrite(shooter_pwm1, 0);
    analogWrite(shooter_pwm2, 40);
  } else {
    analogWrite(shooter_pwm1, 0);
    analogWrite(shooter_pwm2, 0);
  } 
}

void Pelempar(){
  if( ps2x.ButtonPressed(PSB_TRIANGLE)){ 
     Serial.println("pelempar 3");
    digitalWrite(relay1, LOW);
    delay(50);
  }else{
    digitalWrite(relay1, HIGH);
  } 
  if( ps2x.ButtonPressed(PSB_CIRCLE)){ 
     Serial.println("pelempar 3");
    digitalWrite(relay2, LOW);
    delay(100);
  }else{
    digitalWrite(relay2, HIGH);
  } 
  if ( ps2x.ButtonPressed(PSB_CROSS)) { 
   Serial.println("pelempar 3");
    digitalWrite(relay3, LOW);
    delay(100);
  }else{
    digitalWrite(relay3, HIGH);
  }
}
