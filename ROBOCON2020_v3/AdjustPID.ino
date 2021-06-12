void AdjustPID() {
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }
  if (lcdcount > lcdratemultiplier) {
    if (adjust == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(kfrl * 1000);
      lcd.setCursor(8, 0);
      lcd.print(kfrr * 1000);
      lcd.setCursor(0, 1);
      lcd.print(kbcl * 1000);
      lcd.setCursor(8, 1);
      lcd.print(kbcr * 1000);
    }
    else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(ADJUST[adjust]);
    lcd.setCursor(8, 0);
    lcd.print(proportional[adjust] * 1000);
    lcd.setCursor(0, 1);
    lcd.print(integral[adjust] * 1000);
    lcd.setCursor(8, 1);
    lcd.print(derivative[adjust] * 1000);
    lcdcount = 0;
    }
  }
  lcdcount++;

  if (ps2x.Button(PSB_TRIANGLE)) {
    adjust = 0;
  }

  if (ps2x.Button(PSB_CROSS)) {
    adjust = 1;
  }

  if (ps2x.Button(PSB_CIRCLE)) {
    adjust = 2;
  }

  if (ps2x.Button(PSB_SQUARE)) {
    adjust = 3;
  }

  if (ps2x.Button(PSB_R1) && ps2x.Button(PSB_PAD_UP)) {
    if (adjust == 0) {
      kbcr += 0.001;
    }
    else if (adjust == 1) {
      Xp += 0.001;
      proportional[adjust] = Xp;
    }
    else if (adjust == 2) {
      Yp += 0.001;
      proportional[adjust] = Yp;
    }
    else if (adjust == 3) {
      Cp += 0.001;
      proportional[adjust] = Cp;
    }
  }

  if (ps2x.Button(PSB_R1) && ps2x.Button(PSB_PAD_DOWN)) {
    if (adjust == 0) {
      kbcr -= 0.001;
    }
    else if (adjust == 1) {
      Xp -= 0.001;
      proportional[adjust] = Xp;
    }
    else if (adjust == 2) {
      Yp -= 0.001;
      proportional[adjust] = Yp;
    }
    else if (adjust == 3) {
      Cp -= 0.001;
      proportional[adjust] = Cp;
    }
  }

  if (ps2x.Button(PSB_R2) && ps2x.Button(PSB_PAD_UP)) {
    if (adjust == 0) {
      kfrr += 0.001;
    }
    else if (adjust == 1) {
      Xi += 0.001;
      integral[adjust] = Xi;
    }
    else if (adjust == 2) {
      Yi += 0.001;
      integral[adjust] = Yi;
    }
    else if (adjust == 3) {
      Ci += 0.001;
      integral[adjust] = Ci;
    }
  }

  if (ps2x.Button(PSB_R2) && ps2x.Button(PSB_PAD_DOWN)) {
    if (adjust == 0) {
      kfrr -= 0.001;
    }
    else if (adjust == 1) {
      Xi -= 0.001;
      integral[adjust] = Xi;
    }
    else if (adjust == 2) {
      Yi -= 0.001;
      integral[adjust] = Yi;
    }
    else if (adjust == 3) {
      Ci -= 0.001;
      integral[adjust] = Ci;
    }
  }

  if (ps2x.Button(PSB_L2) && ps2x.Button(PSB_PAD_UP)) {
    if (adjust == 0) {
      kfrl += 0.001;
    }
    else if (adjust == 1) {
      Xd += 0.001;
      derivative[adjust] = Xd;
    }
    else if (adjust == 2) {
      Yd += 0.001;
      derivative[adjust] = Yd;
    }
    else if (adjust == 3) {
      Cd += 0.001;
      derivative[adjust] = Cd;
    }
  }

  if (ps2x.Button(PSB_L2) && ps2x.Button(PSB_PAD_DOWN)) {
    if (adjust == 0) {
      kfrl -= 0.001;
    }
    else if (adjust == 1) {
      Xd -= 0.001;
      derivative[adjust] = Xd;
    }
    else if (adjust == 2) {
      Yd -= 0.001;
      derivative[adjust] = Yd;
    }
    else if (adjust == 3) {
      Cd -= 0.001;
      derivative[adjust] = Cd;
    }
  }
  
  if (ps2x.Button(PSB_L1) && ps2x.Button(PSB_PAD_UP)) {
    if (adjust == 0) {
      kbcl += 0.001;
    }
  }
  
  if (ps2x.Button(PSB_L1) && ps2x.Button(PSB_PAD_DOWN)) {
    if (adjust == 0) {
      kbcl -= 0.001;
    }
  }
}
