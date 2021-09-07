void MainMenu() {
  if (mode == 0) {
    MoveRobot(0, 0, 0);
//    analogWrite(PWMKIK, 0);
    if (lcdcount > lcdratemultiplier) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Q: MAN");
      lcd.setCursor(8, 0);
      lcd.print("T: PID");
      lcd.setCursor(0, 1);
      lcd.print("O: AUTO");
      lcd.setCursor(8, 1);
      lcd.print("X: VAL");
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
      AdjustPID();
      mode = 2;
    }

    if (ps2x.Button(PSB_CIRCLE))
    {
      Auto();
      mode = 3;
    }

    if (ps2x.Button(PSB_CROSS))
    {
      Value();
      mode = 4;
    }
  }
  else if (mode == 1) {
    Manual();
  }
  else if (mode == 2) {
    AdjustPID();
  }
  else if (mode == 3) {
    Auto();
  }
  else if (mode == 4) {
    Value();
  }
  else {
    mode = 0;
  }
}
