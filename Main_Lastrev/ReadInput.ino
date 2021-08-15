void ReadInput (){
  pressureValue = analogRead(pressureInput); 
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  lcd.setCursor(0,0); 
  lcd.print("Pressure:"); 
  lcd.print(pressureValue, 1); 
  lcd.print("psi"); 
  lcd.print("  "); 
  
  digitalWrite(SS1, LOW);
  PosX = SPI.transfer(0);
  digitalWrite(SS1, HIGH);
  X += PosX;

  lcd.setCursor(0,1); 
  lcd.print("Encoder:"); 
  lcd.print(abs(X));
  lcd.print("  ");

  if(ps2x.Button(PSB_R1))
  {
    if(ps2x.Button(PSB_CROSS))
    {
      X = 0;
    }
  }
}
