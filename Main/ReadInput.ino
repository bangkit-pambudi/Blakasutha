void ReadInput (){
  //psx
  ps2x.read_gamepad(false, 0);

  //pneumatic sensor
  pressureValue = PressureSensor(analogRead(pressureInput)); 
  pressureValue1 = PressureSensor(analogRead(pressureInput1)); 

  mpu6050.update();
  headingDegrees = mpu6050.getAngleZ();
  driftDegrees += driftrate;
  C = headingDegrees - offsetDegrees - driftDegrees;

  if (C < 0)
    C += 360;
  if (C > 360)
    C -= 360;

  CalcCPID;
  
  //encoder
  digitalWrite(SS1, LOW);
  PosX = SPI.transfer(0);
  digitalWrite(SS1, HIGH);
  X += PosX;

  if(ps2x.Button(PSB_R1))
  {
    if(ps2x.Button(PSB_CROSS))
    {
      X = 0;
    }
        if(ps2x.ButtonPressed(PSB_CIRCLE))
    {
      if (pwm_tangan < 220){
        pwm_tangan += 10;
      }
    }
        if(ps2x.ButtonPressed(PSB_TRIANGLE))
    {
      if (pwm_tangan > 0){
        pwm_tangan -= 10;
      }
    }
  }
}

float PressureSensor(float pressure)
{
  pressure = ((pressure-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero);
  return pressure;
}
