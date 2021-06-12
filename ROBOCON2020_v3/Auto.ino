void Auto() {
  if (ps2x.Button(PSB_START)) {
    mode = 0;
    task = 0;
    field = 0;
    state = 0;
  }


  if (lcdcount > lcdratemultiplier) {
    if (ps2x.Button(PSB_R2)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(X);
      lcd.setCursor(8, 0);
      lcd.print(Y);
      lcd.setCursor(0, 1);
      lcd.print(setpointX);
      lcd.setCursor(8, 1);
      lcd.print(setpointY);
    }
    else if (ps2x.Button(PSB_R1)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(C);
      lcd.setCursor(0, 1);
      lcd.print(setpointC);
    }
    else if (ps2x.Button(PSB_L1)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(stickX);
      lcd.setCursor(8, 0);
      lcd.print(stickY);
      lcd.setCursor(0, 1);
      lcd.print(stickW);
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("AUTO");
      lcd.setCursor(8, 0);
      lcd.print(FIELD[field]);
      lcd.setCursor(0, 1);
      lcd.print(task);
      lcd.setCursor(8, 1);
      lcd.print(STATE[state]);
    }
    lcdcount = 0;
  }
  lcdcount++;

  if (ps2x.Button(PSB_CIRCLE)) {
    field = 1;
    state = 1;
  }

  if (ps2x.Button(PSB_SQUARE)) {
    field = 2;
    state = 1;
  }

  if (ps2x.Button(PSB_TRIANGLE)) {
    if ((field != 0) && (state == 1)) {
      task++;
      state = 2;
      firstenter = 0;
    }
  }

  if (ps2x.Button(PSB_CROSS)) {
    if ((field != 0) && (state == 1)) {
      task--;
      state = 2;
      firstenter = 0;
    }
  }

  if (task == 0) {
    MoveRobot(0, 0, 0);
  }

  if (task == 1) {
    if (field == 1) {
      if (firstenter == 0) {
        restartPID();
      }
      firstenter = 1;
      setpointY = -3;
      setpointC = 180;
      if (ps2x.Button(PSB_PAD_UP))
        setpointX = 0;
      if (ps2x.Button(PSB_PAD_RIGHT))
        setpointX = -200;
      if (ps2x.Button(PSB_PAD_DOWN))
        setpointX = -400;
        if (ps2x.Button(PSB_PAD_LEFT))
        setpointX = -600;
      CalcPID();
      MoveRobot(stickX, stickY, stickW);
      if (ls3 && ls4 && ls5 && ls6) {
        state = 1;
      }
      else {
        state = 2;
      }
    }
    else if (field == 2) {

    }
    else {

    }
  }

  if (task == 2) {
    if (field == 1) {
      if (firstenter == 0) {
        restartPID();
      }
      firstenter = 1;
      setpointX = -200;
      setpointY = 22;
      setpointC = C;
      CalcPID();
      MoveRobot(stickX, stickY, stickW);
      if (ls5 && ls6 && (Y > 20) && (Y < 25)) {
        state = 1;
      }
      else {
        state = 2;
      }
    }
    else if (field == 2) {

    }
    else {

    }
  }

  if (task == 3) {
    if (field == 1) {
      if (firstenter == 0) {
        restartPID();
      }
      firstenter = 1;
      setpointX = X;
      setpointY = Y;
      setpointC = C;
      CalcPID();
      digitalWrite(PN7, HIGH);
      MoveRobot(stickX, stickY, stickW);
      state = 1;
    }
    else if (field == 2) {

    }
    else {

    }
  }

  if (task == 4) {
    if (field == 1) {
      if (firstenter == 0) {
        restartPID();
      }
      firstenter = 1;
      setpointX = X;
      setpointY = Y;
      setpointC = 215;
      CalcPID();
      MoveRobot(stickX, stickY, stickW);
      if ((C > 213) && (C < 217)) {
        state = 1;
      }
      else {
        state = 2;
      }
    }
    else if (field == 2) {

    }
    else {

    }
  }

  if (task == 5) {
    if (field == 1) {
      if (firstenter == 0) {
        restartPID();
      }
      firstenter = 1;
      setpointX = X;
      setpointY = Y;
      setpointC = C;
      CalcPID();
      digitalWrite(PN8, HIGH);
      MoveRobot(stickX, stickY, stickW);
      state = 1;
    }
    else if (field == 2) {

    }
    else {

    }
  }

  if (task == 6) {
    if (field == 1) {
      if (firstenter == 0) {
        restartPID();
      }
      firstenter = 1;
      setpointX = X - 10;
      setpointY = Y - 20;
      setpointC = 180;
      CalcPID();
      MoveRobot(stickX, stickY, stickW);
      if (ls1 && ls4 && ls5 && ls6) {
        state = 1;
      }
      else {
        state = 2;
      }
    }
    else if (field == 2) {

    }
    else {

    }
  }
}
