 void Lengan(){
 if(ps2x.Button(PSB_R2) && ps2x.Button(PSB_SQUARE)){ //R2 + Kotak
    Serial.println("Tangan Turun");
    digitalWrite(relay4, LOW);
  }else{
    digitalWrite(relay4, HIGH);
  } 

   if(ps2x.Button(PSB_R2) && ps2x.Button(PSB_TRIANGLE)){ //R2 + Segitiga
    Serial.println("Tangan Naik");
    digitalWrite(relay5, LOW);
  }else{
    digitalWrite(relay5, HIGH);
  } 
 }
