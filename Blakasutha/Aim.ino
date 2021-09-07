void Aim(){
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Delay);
    lcd.setCursor(8, 0);
    lcd.print(Pot);
    lcd.setCursor(0, 1);
    lcd.print(pressureValue);
    lcd.setCursor(8, 1);
    lcd.print(X);
    lcdcount = 0;
  }
  lcdcount++;

  if(ps2x.Button(PSB_R1)){
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
      Delay += 10;  
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
      Delay -= 10;
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      Pot++;  
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      Pot--;
    }
  }

  if(ps2x.ButtonPressed(PSB_L2)){
    Serial.print(Tekanan);
    Serial.print(",");
    Serial.print(Encoder);
    Serial.print(",");
    Serial.print(Delay);
    Serial.print(",");
    Serial.println(Pot);
  }
  Pelempar();
  MoveRobot();
}

double regress(double x) {
  double terms[] = {
     4.11,
    -2.09,
     2.92
};
  double t = 1;
  double r = 0;
  for (double c : terms) {
    r += c * t;
    t *= x;
  }
  return r;
}
