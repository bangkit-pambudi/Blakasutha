void Aim(){
      if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AIM");
    lcd.setCursor(8, 0);
    lcd.print("Q:DATA");
    lcd.setCursor(0, 1);
    lcd.print("T:TEST");
    lcdcount = 0;
  }
  lcdcount++;
  
}
