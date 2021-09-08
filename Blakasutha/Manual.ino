void Manual(){ //testing manual
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
    lcd.print(pwm_tangan);
    lcd.setCursor(8, 1);
    lcd.print(X);
    lcdcount = 0;
  }
  lcdcount++;

  if(ps2x.Button(PSB_R1)){
    if(ps2x.ButtonPressed(PSB_CIRCLE)){
      pwm_tangan += 10;  
    }
    if(ps2x.ButtonPressed(PSB_TRIANGLE)){
      pwm_tangan -= 10;
    }
  }
  
  PneumaticAtas();
  PneumaticBawah();
  Pelempar();
  MoveRobot();
  
}
