 void Pelontar(){
 if(ps2x.Button(PSB_R2) && ps2x.Button(PSB_CIRCLE)){ //R2 + O
    Serial.println("Sudut ke posisi tembak");
    digitalWrite(relay6, LOW);
  }else{
    digitalWrite(relay6, HIGH);
  } 

  if(ps2x.Button(PSB_R2) && ps2x.Button(PSB_CROSS)){ //R2 + X
    Serial.println("Sudut ke posisi normal (lurus)");
    digitalWrite(relay7, LOW);
  }else{
    digitalWrite(relay7, HIGH);
  } 
 }
