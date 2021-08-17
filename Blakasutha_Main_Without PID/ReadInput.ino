void ReadInput (){

  //pneumatic sensor
  pressureValue = PressureSensor(analogRead(pressureInput)); 
  pressureValue1 = PressureSensor(analogRead(pressureInput1)); 
  
  digitalWrite(SS1, LOW);
  PosX = SPI.transfer(0);
  digitalWrite(SS1, HIGH);
  X += PosX;

  lcd.setCursor(0,0); 
  lcd.print(pressureValue); 
  lcd.setCursor(8,0); 
  lcd.print(pressureValue1);
  lcd.setCursor(0,1); 
  lcd.print(abs(X));
  lcd.setCursor(8,1); 
  lcd.print(pwm_tangan);

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
