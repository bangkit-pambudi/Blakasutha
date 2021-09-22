void Plan(){
  if (ps2x.Button(PSB_START)) {
    mode = 0;
  }

  if (lcdcount > lcdratemultiplier) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PLAN");
    lcd.setCursor(8, 0);
    lcd.print(index);
    lcd.print(" : ");
    lcd.print(Auto[index]);
    lcd.setCursor(0, 1);
    lcdcount = 0;
  }
  lcdcount++;

    if(ps2x.ButtonPressed(PSB_PAD_UP))
  {
    index++;
  }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN))
  {
    index--;
  }
    if(ps2x.ButtonPressed(PSB_PAD_RIGHT))
  {
    Auto[index] += 10;
  }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT))
  {
    Auto[index] -= 10;
  }

  if(ps2x.ButtonPressed(PSB_TRIANGLE))
  {
    autonomus();
  }
}

void autonomus()
{
  
  digitalWrite(relay4, LOW);
  delay(Auto[0]);
  maju();
  delay(Auto[1]);
  Stop();
  delay(Auto[2]);
  digitalWrite(relay6, LOW);
  delay(Auto[3]);
  analogWrite(roller_pwm1, 100);
  analogWrite(roller_pwm2, 0);
  delay(Auto[4]);
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 0);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay6, HIGH);
  delay(Auto[6]);
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 120);
  delay(Auto[7]);
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 0);
}
