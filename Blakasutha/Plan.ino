void Plan(){
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PLAN");
    lcd.setCursor(8, 0);
    lcd.print("Q:DESTINY");
    lcd.setCursor(0, 1);
    lcd.print(X);
    lcdcount = 0;
  }
  lcdcount++;
  
}
