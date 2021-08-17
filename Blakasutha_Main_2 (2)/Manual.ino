void Manual() {
  setpointC = C;

  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MANUAL");
    lcd.setCursor(8, 0);
    lcd.print(C);
    lcd.setCursor(0, 1);
    lcd.print(X);
    lcd.setCursor(8, 1);
    lcd.print(Y);
    lcdcount = 0;
  }
  lcdcount++;

  slowMove = ps2x.Button(PSB_R2);

  //ROBOT MOVEMENT VERTICAL Y
  if (!ps2x.Button(PSB_PAD_UP) && !ps2x.Button(PSB_PAD_DOWN)) { //set stick value to 0 if not pressed
    stickY = 0;
  }
  else {
    if (ps2x.Button(PSB_PAD_UP)) {        //will be TRUE as long as button is pressed
      stickY = maxSpeed;
    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
      stickY = -maxSpeed;
    }
  }

  //ROBOT MOVEMENT HORIZONTAL X
  if (!ps2x.Button(PSB_PAD_RIGHT) && !ps2x.Button(PSB_PAD_LEFT)) {
    stickX = 0;
  }

  else {
    if (ps2x.Button(PSB_PAD_RIGHT)) {
      stickX = maxSpeed;
    }
    if (ps2x.Button(PSB_PAD_LEFT)) {
      stickX = -maxSpeed;
    }
  }

  //ROBOT MOVEMENT FOR ROTATION W
  if (!ps2x.Button(PSB_L1) && !ps2x.Button(PSB_R1)) {
    stickW = 0;
  }
  else {
    if (ps2x.Button(PSB_R1)) {
      setpointC += 1;
    }
    if (ps2x.Button(PSB_L1)) {
      setpointC -= 1;;
    }
  }

  CalcCPID;

  if (ps2x.Button(PSB_TRIANGLE)) { //slide wall movement
    stickY = maxSpeed;
    stickX = (-maxSpeed / 2);
  }

  //KICKING MOTOR MOVEMENT
  if (ps2x.Button(PSB_SQUARE)) {
    digitalWrite(DIRKIK, HIGH);
    analogWrite(PWMKIK, 90);
  }
  else if (ps2x.Button(PSB_CROSS)) {
    digitalWrite(DIRKIK, LOW);
    analogWrite(PWMKIK, 90);
  }
  else {
    digitalWrite(DIRKIK, LOW);
    analogWrite(PWMKIK, 0);
  }

  if (ps2x.Button(PSB_CIRCLE)) {
    digitalWrite(PN7, HIGH);
  }
  else {
    digitalWrite(PN7, LOW);
  }
  if (ps2x.Button(PSB_L2)) {
    digitalWrite(PN8, HIGH);
  }
  else {
    digitalWrite(PN8, LOW);
  }

  MoveRobot(stickX, stickY, stickW);
}
