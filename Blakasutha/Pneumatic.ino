void PneumaticAtas(){
if(ps2x.Button(PSB_L2)){ //Tangan Atas
  if(ps2x.Button(PSB_SQUARE)){
    Serial.println("Sudut 60 derajat");
    digitalWrite(relay4, HIGH);
  }

  if(ps2x.Button(PSB_TRIANGLE)){
    Serial.println("Sudut Vertikal");
    digitalWrite(relay4, LOW);
  }
 }
}

void PneumaticBawah(){
if(ps2x.Button(PSB_R2)){
 if(ps2x.Button(PSB_SQUARE)){ //R2 + Kotak
    Serial.println("Tangan Turun");
    digitalWrite(relay6, LOW);
  } 

   if(ps2x.Button(PSB_TRIANGLE)){ //R2 + Segitiga
    Serial.println("Tangan Naik");
    digitalWrite(relay6, HIGH);
  }

  if(ps2x.Button(PSB_CROSS)) {
    Serial.println("Motor memutar ke belakang");
    analogWrite(roller_pwm1, 100);
    analogWrite(roller_pwm2, 0);
  }else if (ps2x.Button(PSB_CIRCLE)){
    Serial.println("Motor memutar ke depan");
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 120);  
  }else{
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 0);}
 }
}

void Pelempar(){
if(ps2x.Button(PSB_L1)){
  if( ps2x.ButtonPressed(PSB_TRIANGLE)){ 
    //Serial.println("pelempar 1");
    digitalWrite(relay1, LOW);
    delay(Delay1[adjust1]);
  }else{
    digitalWrite(relay1, HIGH);
  } 
  
  if( ps2x.ButtonPressed(PSB_CIRCLE)){ 
    //Serial.println("pelempar 2");
    digitalWrite(relay2, LOW);
    delay(Delay2[adjust1]);
  }else{
    digitalWrite(relay2, HIGH);
  } 
  
  if ( ps2x.ButtonPressed(PSB_CROSS)) {
    //Serial.println("pelempar 3");
    digitalWrite(relay3, LOW);
    delay(Delay3[adjust1]);
  }else{
    digitalWrite(relay3, HIGH);
  }
 }
}

void Saving()
{
  Encoder = X;
  Tekanan = pressureValue;
}
