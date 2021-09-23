void Config(){ //testing konstanta
    if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  Serial.print(kfrl[adjust]);
  Serial.print(kfrr[adjust]);
  Serial.print(kbcr[adjust]);
  Serial.print(kbcl[adjust]);
  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("kfrl:");
    lcd.print(kfrl[adjust]);
    lcd.setCursor(8, 0);
    lcd.print("kfrr:");
    lcd.print(kfrr[adjust]);
    lcd.setCursor(0, 1);
    lcd.print("kbcr:");
    lcd.print(kbcr[adjust]);
    lcd.setCursor(8, 1);
    lcd.print("kbcl:");
    lcd.print(kbcl[adjust]);
    lcd.print(" ");
    lcd.print(adjust);
    lcdcount = 0;
  }
  lcdcount++;

    if(ps2x.Button(PSB_R2)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      kfrl[adjust] += 5; //forward left
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      kfrr[adjust] += 5; //forward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      kbcr[adjust] += 5; //backward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      kbcl[adjust] += 5; //backward left
    }
  }

  
    if(ps2x.Button(PSB_L2)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      kfrl[adjust] -= 5; //forward left
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      kfrr[adjust] -= 5; //forward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      kbcr[adjust] -= 5; //backward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      kbcl[adjust] -= 5; //backward left
    }
  }

      if(ps2x.Button(PSB_R1)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      adjust = 0; //forward left
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      adjust = 1; //forward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      adjust = 2; //backward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      adjust = 3; //backward left
    }
  }
  
  
  
}
