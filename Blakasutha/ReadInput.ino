void ReadInput (){
  //PS2X Read
  ps2x.read_gamepad(false, vibrate);
  
  //pneumatic sensor
  pressureValue = PressureSensor(analogRead(pressureInput)); 
  pressureValue1 = PressureSensor(analogRead(pressureInput1)); 

  //Encoder SPI
  digitalWrite(SS1, LOW);
  PosX = SPI.transfer(0);
  digitalWrite(SS1, HIGH);
  X += PosX;
  
}

float PressureSensor(float pressure)
{
  pressure = ((pressure-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero);
  return pressure;
}
