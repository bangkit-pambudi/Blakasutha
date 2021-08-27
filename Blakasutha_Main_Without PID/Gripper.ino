void Gripper(){
if(ps2x.Button(PSB_L2)){
  if(ps2x.Button(PSB_SQUARE)){
    Serial.println("Sudut 60 derajat");
    digitalWrite(relay4, LOW);
  }else{
    digitalWrite(relay4, HIGH);
  }

  if(ps2x.Button(PSB_TRIANGLE)){
    Serial.println("Sudut Vertikal");
    digitalWrite(relay5, LOW);
  }else{
    digitalWrite(relay5, HIGH);
  }
   
 }
}
