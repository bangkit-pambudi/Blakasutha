unsigned long previousMillis1 = 0;
unsigned long currentMillis1 = millis();

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
    autonomus1();
  }
}

void autonomus1()
{
  
  digitalWrite(relay4, HIGH);
  delay(Auto[0]);
  while (currentMillis1 - previousMillis1 < Auto[0]) {
    ReadInput();
    currentMillis1 = millis();
  }
  previousMillis1 = currentMillis1;
  maju();
  while (currentMillis1 - previousMillis1 < Auto[1]) {
    ReadInput();
    currentMillis1 = millis();
  }
  previousMillis1 = currentMillis1;
  Stop();
  while (currentMillis1 - previousMillis1 < Auto[2]) {
    ReadInput();
    currentMillis1 = millis();
  }
  previousMillis1 = currentMillis1;
  digitalWrite(relay4, LOW);
  while (currentMillis1 - previousMillis1 < Auto[3]) {
    ReadInput();
    currentMillis1 = millis();
  }
  previousMillis1 = currentMillis1;
  digitalWrite(relay6, LOW);
  analogWrite(roller_pwm1, 100);
  analogWrite(roller_pwm2, 0);
  while (currentMillis1 - previousMillis1 < Auto[4]) {
    ReadInput();
    currentMillis1 = millis();
  }
  previousMillis1 = currentMillis1;
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 0);
  digitalWrite(relay6, HIGH);
  while (currentMillis1 - previousMillis1 < Auto[6]) {
    ReadInput();
    currentMillis1 = millis();
  }
  previousMillis1 = currentMillis1;
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 180);
  while (currentMillis1 - previousMillis1 < Auto[7]) {
    ReadInput();
    currentMillis1 = millis();
  }
  
  previousMillis1 = currentMillis1;
  ls1 = digitalRead(LS1);
  while(ls1==LOW)
  {
    ls1 = digitalRead(LS1);
//    Serial.println("Kontol");
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 120);
    ReadInput();
  }
//  delay(Auto[5]);
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 0);
    
}

void autonomus2(){
  digitalWrite(relay6, LOW);
  analogWrite(roller_pwm1, 100);
  analogWrite(roller_pwm2, 0);
  delay(Auto[4]);
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 0);
  digitalWrite(relay6, HIGH);
  delay(Auto[6]);
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 180);
  //delay(Auto[7]);
  ls1 = digitalRead(LS1);
  while(ls1==LOW)
  {
    ls1 = digitalRead(LS1);
//    Serial.println("Kontol");
    analogWrite(roller_pwm1, 0);
    analogWrite(roller_pwm2, 120);
  }
  delay(Auto[5]);
  analogWrite(roller_pwm1, 0);
  analogWrite(roller_pwm2, 0);
}
