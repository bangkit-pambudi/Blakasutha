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

  //Limit Switch
  ls1 = digitalRead(LS1);
  ls2 = digitalRead(LS2);
  ls3 = digitalRead(LS3);
  ls4 = digitalRead(LS4);
  ls5 = digitalRead(LS5);
  
}

float PressureSensor(float pressure)
{
  pressure = ((pressure-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero);
  return pressure;
}
