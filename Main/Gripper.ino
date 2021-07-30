void Gripper(){
if(ps2x.Button(PSB_L1) && ps2x.Button(PSB_CROSS)){ //L1 + X
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
   if(ps2x.Button(PSB_L1) && ps2x.Button(PSB_CIRCLE)){ //L1 + O
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
}
