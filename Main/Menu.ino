void Menu()
{  if (mode == 0) {
    if (lcdcount > lcdratemultiplier) {
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print(pressureValue); 
      lcd.setCursor(8,0); 
      lcd.print(pressureValue1);
      lcd.setCursor(0,1); 
      lcd.print(abs(X));
      lcd.setCursor(8,1); 
      lcd.print(pwm_tangan);
      lcdcount = 0;
    }
    lcdcount++;
 }
}
