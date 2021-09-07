void MainMenu() {
  if (mode == 0) {
    Stop();
    if (lcdcount > lcdratemultiplier) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Q: MAN");
      lcd.setCursor(8, 0);
      lcd.print("T: AIM");
      lcd.setCursor(0, 1);
      lcd.print("O: CON");
      lcd.setCursor(8, 1);
      lcd.print("X: PLAN");
      lcdcount = 0;
    }
    lcdcount++;
    if (ps2x.Button(PSB_SQUARE))
    {
      Manual();
      mode = 1;
    }

    if (ps2x.Button(PSB_TRIANGLE))
    {
      Aim();
      mode = 2;
    }

    if (ps2x.Button(PSB_CIRCLE))
    {
      Config();
      mode = 3;
    }

    if (ps2x.Button(PSB_CROSS))
    {
      Plan();
      mode = 4;
    }  
  }
  else if (mode == 1) {
    Manual();
  }
  else if (mode == 2) {
    Aim();
  }
  else if (mode == 3) {
    Config();
  }
  else if (mode == 4) {
    Plan();
  }
  else {
    mode = 0;
  }
}
