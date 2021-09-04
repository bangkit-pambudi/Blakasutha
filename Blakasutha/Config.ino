void Config(){
    if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CONFIG");
    lcd.setCursor(8, 0);
    lcd.print("Q:MOTOR");
    lcd.setCursor(0, 1);
    lcd.print("T:PID");
    lcdcount = 0;
  }
  lcdcount++;
  
}
