//**********************LIBRARY************************//
#include <PS2X_lib.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <SPI.h>


//*********************PEWAKTUAN***********************//
unsigned long currentmillis;
unsigned long prevmillis = 0;

//***********************INPUT************************//
//JOYSTIK
const int dataPin = 22;
const int cmndPin = 24;
const int attPin = 26;
const int clockPin = 28;
PS2X ps2x;
int error = 0;
int mode = 0;

//**********************OUTPUT************************//
// MOTOR
const int pwmkia1 = 2;
const int pwmkia2 = 3;
const int pwmkib1 = 4;
const int pwmkib2 = 5;
const int pwmkab1 = 6;
const int pwmkab2 = 7;
const int pwmkaa1 = 8;
const int pwmkaa2 = 9;
int pwmkia;
int pwmkib;
int pwmkab;
int pwmkaa;

void setup() {
  //JOYSTIK
  error = ps2x.config_gamepad(clockPin,cmndPin,attPin,dataPin, true, true); //GamePad(clock, command, attention, data, Pressures?, Rumble?)
  delay(500);

  //MOTOR
  pinMode(pwmkia1,OUTPUT);
  pinMode(pwmkia2,OUTPUT);
  pinMode(pwmkib1,OUTPUT);
  pinMode(pwmkib2,OUTPUT);
  pinMode(pwmkab1,OUTPUT);
  pinMode(pwmkab2,OUTPUT);
  pinMode(pwmkaa1,OUTPUT);
  pinMode(pwmkaa2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
