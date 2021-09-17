void Aim(){ //testing aim robot
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(adjust1);
    lcd.setCursor(8, 0);
    lcd.print(Delay[0]);
    lcd.setCursor(0, 1);
    lcd.print(Delay[1]);
    lcd.setCursor(8, 1);
    lcd.print(Delay[2]);
    lcdcount = 0;
  }
  lcdcount++;

  if(ps2x.Button(PSB_R1)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      Delay[adjust1] += 5;  
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      Delay[adjust1] -= 5;
    }
  }

  if(ps2x.Button(PSB_R2)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      adjust1 = 0;  
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      adjust1 = 1;
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      adjust1 = 2;
    }
  }
  
  Pelempar();
  //MoveRobot();
  //Stop();
}
