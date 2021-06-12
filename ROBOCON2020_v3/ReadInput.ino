void ReadInput() {
  ps2x.read_gamepad(false, 0);

  mpu6050.update();
  headingDegrees = mpu6050.getAngleZ();
  driftDegrees += driftrate;
  C = headingDegrees - offsetDegrees - driftDegrees;

  if (C < 0)
    C += 360;
  if (C > 360)
    C -= 360;

  digitalWrite(SS1, LOW);
  PosX = SPI.transfer(0);
  digitalWrite(SS1, HIGH);
  X += PosX;

  digitalWrite(SS2, LOW);
  PosY = SPI.transfer(0);
  digitalWrite(SS2, HIGH);
  Y -= PosY;

  ir1 = digitalRead(IR1);
  
  ls1 = digitalRead(LS1);
  ls2 = digitalRead(LS2);
  ls3 = digitalRead(LS3);
  ls4 = digitalRead(LS4);
  ls5 = digitalRead(LS5);
  ls6 = digitalRead(LS6);

  if (ls1 == HIGH && ls2 == HIGH) {
    offsetDegrees = headingDegrees - 180;
    X = 0;
    setpointX = X;
  }

  if (ls3 == HIGH && ls4 == HIGH) {
    offsetDegrees = headingDegrees - 180;
    Y = 0;
    setpointY = Y;
  }

  if (ls5 == HIGH && ls6 == HIGH) {
    offsetDegrees = headingDegrees - 180;
    X = -520;
    setpointX = X;
  }
  //Serial.print(headingDegrees);
  //Serial.print("\t");
  //
  //Serial.print(X);
  //Serial.print("\t");
  //
  //Serial.println(Y);
}
