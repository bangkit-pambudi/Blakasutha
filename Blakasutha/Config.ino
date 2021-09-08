void Config(){ //testing konstanta
    if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(kfrl);
    lcd.setCursor(8, 0);
    lcd.print(kfrr);
    lcd.setCursor(0, 1);
    lcd.print(kbcr);
    lcd.setCursor(8, 1);
    lcd.print(kbcl);
    lcdcount = 0;
  }
  lcdcount++;

    if(ps2x.Button(PSB_R2)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      kfrl += 1; //forward left
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      kfrr += 1; //forward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      kbcr += 1; //backward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      kbcl += 1; //backward left
    }
  }

  
    if(ps2x.Button(PSB_L2)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      kfrl -= 1; //forward left
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      kfrr -= 1; //forward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      kbcr -= 1; //backward right
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      kbcl -= 1; //backward left
    }
  }
  
}
