void Gripper(){
if(ps2x.Button(PSB_L2)){
   if(ps2x.Button(PSB_CIRCLE)){
    Serial.println("Servo elevator melepas panah");
    Serial.print(servo1.read());
    Serial.print("||");
    Serial.print(servo3.read());
    Serial.print("||");
    Serial.print(servo5.read());
    Serial.println("");
            
    if(servo1.read() > 0 ){
      servo1.write(servo1.read() - 2);
      servo3.write(servo3.read() - 2);
      servo5.write(servo5.read() - 2);
    }
   }
    
   if(ps2x.Button(PSB_CROSS)){
    Serial.println("Servo elevator menjepit panah");
    Serial.print(servo1.read());
    Serial.print("||");
    Serial.print(servo3.read());
    Serial.print("||");
    Serial.print(servo5.read());
    Serial.println("");
   
    if(servo1.read() < 180){
      servo1.write(servo1.read() + 2);
      servo3.write(servo3.read() + 2);
      servo5.write(servo5.read() + 2);
    }
  }

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
