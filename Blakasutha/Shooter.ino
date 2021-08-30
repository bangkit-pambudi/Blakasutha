void Pelempar(){
if(ps2x.Button(PSB_L1)){
  if( ps2x.ButtonPressed(PSB_TRIANGLE)){ 
    Serial.println("pelempar 1");
    digitalWrite(relay1, LOW);
    delay(50);
  }else{
    digitalWrite(relay1, HIGH);
  } 
  
  if( ps2x.ButtonPressed(PSB_CIRCLE)){ 
    Serial.println("pelempar 2");
    digitalWrite(relay2, LOW);
    delay(50);
  }else{
    digitalWrite(relay2, HIGH);
  } 
  
  if ( ps2x.ButtonPressed(PSB_CROSS)) { 
    Serial.println("pelempar 3");
    digitalWrite(relay3, LOW);
    delay(50);
  }else{
    digitalWrite(relay3, HIGH);
  }
 }
}
