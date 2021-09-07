//==============Library============//
#include <PS2X_lib.h>  //PS2X
#include <Wire.h> //allows communication over i2c devices
#include <LiquidCrystal_I2C.h> //LCD I2C
#include <Servo.h>
#include <SPI.h>
#include <MPU6050_tockn.h>

//====================TIMINGS====================//
unsigned long currentmillis;
unsigned long prevmillis = 0;
int inputrate = 50;
int lcdratemultiplier = 3;
int lcdcount = 0;
float elapsedtime = (float)inputrate / 1000;

//==============PIN==============//
//**************Input************* 
//PS2X 
#define PS2_DAT        22  //14    
#define PS2_CMD        24  //15
#define PS2_SEL        26  //16
#define PS2_CLK        28  //17

PS2X ps2x; // create PS2 Controller Class
int error = 0;
int mode = 0;

//Pressure Sensor
const int pressureInput = A0; 
const int pressureInput1 = A1;
const int pressureZero = 102.4;
const int pressureMax = 921.6;
const int pressuretransducermaxPSI = 100; 
const int baudRate = 9600; 
const int sensorreadDelay = 250; 
float pressureValue = 0; 
float pressureValue1 = 0;

//ENCODER
const int SS1 = 41;
int16_t X = 0;
int8_t PosX = 0;

//LCD
LiquidCrystal_I2C lcd(0x3f, 16, 2);

//MPU
MPU6050 mpu6050(Wire);
float heading = 0;
float headingDegrees = 0;
float offsetDegrees = 0;
float driftDegrees = 0;
float driftrate = 0.02;
int C = 0;

//***************Output**************
//Motor DC
#define pwm_kiri_atas1 2
#define pwm_kiri_atas2 3
#define pwm_kiri_bawah1 4
#define pwm_kiri_bawah2 5
#define pwm_kanan_bawah1 6
#define pwm_kanan_bawah2 7
#define pwm_kanan_atas1 8
#define pwm_kanan_atas2 9
const int pwm_speed = 160;
int stickW = 0;

//Motor Window
#define roller_pwm1 10
#define roller_pwm2 11
int pwm_tangan = 60;

//Motor Pelontar
#define shooter_pwm1 13
#define shooter_pwm2 12

//Pneumatic
#define relay1 30
#define relay2 32
#define relay3 34
#define relay4 36
#define relay5 38
#define relay6 40
#define relay7 42

//servo
#define p_servo1 23
#define p_servo3 25
#define p_servo5 27

Servo servo1, servo3, servo5;

//timing
int integral = 0;
int tmp_data = 0;

//PID & AUTO
int adjust;
float kfrr = 0.8;
float kfrl = 0.83;
float kbcr = 0.8;
float kbcl = 0.8;
float Cp = 2.5;
float Ci = 0.06;
float Cd = 0.1;

float proportional[] = {0, Cp};
float integral1[] = {0, Ci};
float derivative[] = {0, Cd};
float setpointC = 0;
float lasterrorC = 0;
float errorC = 0;
float errorCi = 0;
float errorCd = 0;
float CPID = 0;

void setup() {

  Serial.begin(57600);
  //PS2X
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

  //MPU
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  delay(500);

  //Encoder
  pinMode (SS1, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS1, HIGH);
  delay(300);
  
  //Motor
  delay(300);
  pinMode(pwm_kiri_atas1, OUTPUT);
  pinMode(pwm_kiri_atas2, OUTPUT);
  pinMode(pwm_kiri_bawah1, OUTPUT);
  pinMode(pwm_kiri_bawah2, OUTPUT);
  pinMode(pwm_kanan_bawah1, OUTPUT);
  pinMode(pwm_kanan_bawah2, OUTPUT);
  pinMode(pwm_kanan_atas1, OUTPUT);
  pinMode(pwm_kanan_atas2, OUTPUT);

  //Motor Window
  delay(300);
  pinMode(roller_pwm1, OUTPUT);
  pinMode(roller_pwm2, OUTPUT);

  //Motor Pelontar
  delay(300);
  pinMode(shooter_pwm1, OUTPUT);
  pinMode(shooter_pwm2, OUTPUT);

  //Pneumatic
  delay(300);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);

  //Servo
  servo1.attach(p_servo1);
  servo3.attach(p_servo3);
  servo5.attach(p_servo5);
    
  servo1.write(90);
  servo3.write(90);
  servo5.write(90);

  //LCD
  lcd.init(); //initializes the LCD screen
  lcd.backlight();

}
int i;

void loop() {
  currentmillis = millis();
  if (currentmillis - prevmillis >= inputrate) {

    for(i = 0;i<=360;i++)
    {
      setpointC = i;
    }
     
    ReadInput();
    
    /*if(integral < pwm_speed){
      integral+= 5;
    }*/
    Serial.print(C);
    Serial.print(" || ");
    Serial.print(errorC);
    Serial.print(" || ");
    Serial.print(stickW);
    Serial.println(" ");

    //Gripper();
    //Lengan();
    //Pelempar();
    //MoveRobot();
    prevmillis = currentmillis;
    } 
}
