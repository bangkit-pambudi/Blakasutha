//**********************TIMINGS************************//
unsigned long currentmillis;
unsigned long prevmillis = 0;
int inputrate = 50;
int lcdratemultiplier = 3;
int lcdcount = 0;
float elapsedtime = (float)inputrate / 1000;

#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
float heading = 0;
float headingDegrees = 0;
float offsetDegrees = 0;
float driftDegrees = 0;
float driftrate = 0.02;
int C = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  currentmillis = millis();
  if (currentmillis - prevmillis >= inputrate) {
  mpu6050.update();
  headingDegrees = mpu6050.getAngleZ();
  driftDegrees += driftrate;
  C = headingDegrees - offsetDegrees - driftDegrees;

  if (C < 0)
    C += 360;
  if (C > 360)
    C -= 360;
  Serial.print("\tangleZ : ");
  Serial.println(C);
   prevmillis = currentmillis;
  }  
}
