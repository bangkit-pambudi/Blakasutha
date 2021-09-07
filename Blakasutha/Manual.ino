void Manual(){
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MANUAL");
    lcd.setCursor(8, 0);
    lcd.print(pressureValue);
    lcd.setCursor(0, 1);
    lcd.print(pressureValue1);
    lcd.setCursor(8, 1);
    lcd.print(X);
    lcdcount = 0;
  }
  lcdcount++;

  PneumaticAtas();
  PneumaticBawah();
  Pelempar();
  MoveRobot();
  
}
