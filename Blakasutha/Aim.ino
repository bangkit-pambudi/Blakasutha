void Aim(){ //testing aim robot
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
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      Pot++;  
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
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
  if(ps2x.ButtonPressed(PSB_R2))
  {
    if(ps2x.ButtonPressed(PSB_PAD_UP)){
        X = 0;
        Delay = regress_4(pressureValue);
    }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
        X = 0;
        Delay = regress_2(pressureValue);
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
        X = 0;
        Delay = regress_1(pressureValue);
    }
  }

  Serial.println(Delay);
  
  Pelempar();
  //MoveRobot();
  //Stop();
}


double regress_4(double x) {
  double terms[] = {
    -4.569,
     1.813,
    -1.736
};
  
  double t = 1;
  double r = 0;
  for (double c : terms) {
    r += c * t;
    t *= x;
  }
  return r;
}

double regress_2(double x) {
  double terms[] = {
    -1.1461195242370218e+007,
     1.0779281696440135e+006,
    -3.7944196867966908e+004,
     5.9255845541379961e+002,
    -3.4641717499497831e+000
};
  
  double t = 1;
  double r = 0;
  for (double c : terms) {
    r += c * t;
    t *= x;
  }
  return r;
}

double regress_1(double x) {
  double terms[] = {
    -4.7894934899005498e+005,
     5.3961466330134543e+004,
    -2.2720411681854780e+003,
     4.2388752175912948e+001,
    -2.9571727552298488e-001
};
  
  double t = 1;
  double r = 0;
  for (double c : terms) {
    r += c * t;
    t *= x;
  }
  return r;
}
