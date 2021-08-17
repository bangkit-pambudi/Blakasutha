void Value() {
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }
  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VALUE");
    lcd.setCursor(8, 0);
    lcd.print(C);
    lcd.setCursor(0, 1);
    lcd.print(X);
    lcd.setCursor(8, 1);
    lcd.print(Y);
    lcdcount = 0;
  }
  lcdcount++;

}
