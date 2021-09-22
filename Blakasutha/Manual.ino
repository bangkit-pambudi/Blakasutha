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
    lcd.print(adjust1);
    lcd.setCursor(8, 1);
    lcd.print(pressureValue1);
    lcdcount = 0;
  }
  lcdcount++;

//  slowMove = ps2x.Button();
  
  PneumaticAtas();
  PneumaticBawah();
  Pelempar();
//  if (ps2x.ButtonPressed(PSB_R1)){
//      autonomus();  
//  }else {
//    MoveRobot();
//  }

void Konfigurasi()
{
  if(ps2x.Button(PSB_R1))
  {
    if(ps2x.Button(PSB_TRIANGLE))
    {
      adjust1 = 0;
    }

    if(ps2x.Button(PSB_CIRCLE))
    {
      adjust1 = 1;
    }
  }
}
