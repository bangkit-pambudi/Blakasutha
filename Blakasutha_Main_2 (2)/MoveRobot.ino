void MoveRobot(int stickX, int stickY, int stickW) {
//  if(stickX !=0 || stickY != 0 || stickW != 0){
//    driftDegrees += driftrate;
//  }
  volt1 = analogRead(VOLTMETER1);
  multiplier = map(volt1, 720, 907, 1000, 791)/1000.0;

  int pwmfrr = 1 * (stickX - stickY + stickW);
  int pwmbcr = -1 * (stickX + stickY - stickW);
  int pwmfrl = -1 * (stickX + stickY + stickW);
  int pwmbcl = -1 * (stickX - stickY - stickW);

  digitalWrite(DIRFRL, determineDir(pwmfrl));   //Set motor direction
  digitalWrite(DIRFRR, determineDir(pwmfrr));
  digitalWrite(DIRBCL, determineDir(pwmbcl));
  digitalWrite(DIRBCR, determineDir(pwmbcr));

  pwmfrl = abs(pwmfrl);     //Set pwm value to positive
  if (pwmfrl > maxSpeed)    //Set motor maxSpeed
    pwmfrl = maxSpeed;

  pwmfrr = abs(pwmfrr);
  if (pwmfrr > maxSpeed)
    pwmfrr = maxSpeed;

  pwmbcl = abs(pwmbcl);
  if (pwmbcl > maxSpeed)
    pwmbcl = maxSpeed;

  pwmbcr = abs(pwmbcr);
  if (pwmbcr > maxSpeed)
    pwmbcr = maxSpeed;

  if (slowMove) {        //Motor move slow if R2 is pressed
    pwmfrl /= 4;
    pwmfrr /= 4;
    pwmbcl /= 4;
    pwmbcr /= 4;
  }
  //  Serial.print("FL: ");
  //  Serial.print(pwmfrl);
  //  Serial.print("   ");
  //  Serial.print("FR: ");
  //  Serial.print(pwmfrr);
  //  Serial.print("   ");
  //  Serial.print("BL: ");
  //  Serial.print(pwmbcl);
  //  Serial.print("   ");
  //  Serial.print("BR: ");
  //  Serial.print(pwmbcr);
  //  Serial.println("   ");
  analogWrite(PWMFRL, (kfrl * pwmfrl * multiplier));  //Set pwm value to motor
  analogWrite(PWMFRR, (kfrr * pwmfrr * multiplier));
  analogWrite(PWMBCL, (kbcl * pwmbcl * multiplier));
  analogWrite(PWMBCR, (kbcr * pwmbcr * multiplier));

}

int determineDir(int velocity) {  //Determine motor direction
  if (velocity >= 0)
    return HIGH;

  else
    return LOW;
}
