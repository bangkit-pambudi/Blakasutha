//**********************LIBRARY************************//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <SPI.h>
#include <PS2X_lib.h>

//**********************TIMINGS************************//
unsigned long currentmillis;
unsigned long prevmillis = 0;
int inputrate = 50;
int lcdratemultiplier = 3;
int lcdcount = 0;
float elapsedtime = (float)inputrate / 1000;

//***********************INPUTS************************//
//Voltmeter
float multiplier;
int VOLTMETER0 = A0;
int VOLTMETER1 = A1;
int VOLTMETER2 = A2;
int volt0;
int volt1;
int volt2;

//PS2
PS2X ps2x;
int error = 0;
int mode = 0;

//ENCODER
const int SS1 = 40;
const int SS2 = 41;
int16_t X = 0;
int16_t Y = 0;
int8_t PosX = 0;
int8_t PosY = 0;

//MPU
MPU6050 mpu6050(Wire);
float heading = 0;
float headingDegrees = 0;
float offsetDegrees = 0;
float driftDegrees = 0;
float driftrate = 0.02;
int C = 0;

//LIMIT SWITCH
const int LS1 = 30;
const int LS2 = 31;
const int LS3 = 32;
const int LS4 = 33;
const int LS5 = 34;
const int LS6 = 35;
int ls1 = LOW;
int ls2 = LOW;
int ls3 = LOW;
int ls4 = LOW;
int ls5 = LOW;
int ls6 = LOW;

//IR SENSOR
const int IR1 = 36;
const int IR2 = 37;
const int IR3 = 38;
const int IR4 = 39;
int ir1;

//*******************************OUTPUT********************************//
//MOTORS
int PWMFRL = 12;
int PWMFRR = 11;
int PWMBCL = 13;
int PWMBCR = 10;
int PWMKIK = 9;
int DIRFRL = 7;
int DIRFRR = 6;
int DIRBCL = 8;
int DIRBCR = 5;
int DIRKIK = 4;
int pwmfrr;
int pwmbcr;
int pwmfrl;
int pwmbcl;
int maxSpeed = 150;
int stickY = 0, stickX = 0, stickW = 0;
bool slowMove = false;
int kickflag = 0;

//PNEUMATICS
const int PN1 = 22;
const int PN2 = 23;
const int PN3 = 24;
const int PN4 = 25;
const int PN5 = 26;
const int PN6 = 27;
const int PN7 = 28;
const int PN8 = 29;
int countPN7 = 0;
int countPN8 = 0;
int isPN7 = LOW;
int isPN8 = LOW;

//LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

//PID & AUTO
int adjust;
float kfrr = 0.8;
float kfrl = 0.83;
float kbcr = 0.8;
float kbcl = 0.8;
float Cp = 2.5;
float Ci = 0.06;
float Cd = 0.1;
float Xp = 0.5;
float Xi = 0;
float Xd = 0;
float Yp = 0.5;
float Yi = 0;
float Yd = 0;
float proportional[] = {0, Xp, Yp, Cp};
float integral[] = {0, Xi, Yi, Ci};
float derivative[] = {0, Xd, Yd, Cd};
float setpointX = 0;
float setpointY = 0;
float setpointC = 0;
float lasterrorX = 0;
float lasterrorY = 0;
float lasterrorC = 0;
float errorX = 0;
float errorY = 0;
float errorC = 0;
float errorXi = 0;
float errorYi = 0;
float errorCi = 0;
float errorXd = 0;
float errorYd = 0;
float errorCd = 0;
float XPID = 0;
float YPID = 0;
float CPID = 0;
int field = 0; //0 BLUE, 1 RED
int state = 0; //0 NULL, 1 READY, 2 WAIT
int task = 0;
int prevtask = 0;
char *FIELD[] = {"FIELD", "BLUE", "RED"};
char *STATE[] = {" ", "READY", "WAIT"};
char *ADJUST[] = {"ADJUST", "X", "Y", "C"};
int firstenter = 0;

void setup() {
  //    Serial.begin(9600);

  //PS2
  error = ps2x.config_gamepad(43, 44, 42, 45, false, false); //GamePad(clock, command, attention, data, Pressures?, Rumble?)
  delay(500);

  //MPU
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  delay(500);
  //ENCODER
  pinMode (SS1, OUTPUT);
  pinMode (SS2, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS1, HIGH);
  digitalWrite(SS2, HIGH);
  delay(500);
  //LIMIT SWITCH
  pinMode(LS1, INPUT_PULLUP);
  pinMode(LS2, INPUT_PULLUP);
  pinMode(LS3, INPUT_PULLUP);
  pinMode(LS4, INPUT_PULLUP);
  pinMode(LS5, INPUT_PULLUP);
  pinMode(LS6, INPUT_PULLUP);
  delay(500);
  //MOTOR
  pinMode(PWMFRL, OUTPUT);
  pinMode(PWMFRR, OUTPUT);
  pinMode(PWMBCL, OUTPUT);
  pinMode(PWMBCR, OUTPUT);
  pinMode(PWMKIK, OUTPUT);
  pinMode(DIRFRL, OUTPUT);
  pinMode(DIRFRR, OUTPUT);
  pinMode(DIRBCL, OUTPUT);
  pinMode(DIRBCR, OUTPUT);
  pinMode(DIRKIK, OUTPUT);
  delay(500);
  //PNEUMATIC
  pinMode(PN1, OUTPUT);
  pinMode(PN2, OUTPUT);
  pinMode(PN3, OUTPUT);
  pinMode(PN4, OUTPUT);
  pinMode(PN5, OUTPUT);
  pinMode(PN6, OUTPUT);
  pinMode(PN7, OUTPUT);
  pinMode(PN8, OUTPUT);
  delay(500);
  //IR SENSOR
  pinMode(IR1, INPUT);

  //LASER
  pinMode(IR2, OUTPUT);
  digitalWrite(IR2, HIGH);

  //LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  currentmillis = millis();
  if (currentmillis - prevmillis >= inputrate) {
    MainMenu();
    ReadInput();
    prevmillis = currentmillis;
  }
}
