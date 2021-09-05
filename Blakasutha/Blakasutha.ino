//==============Library============
#include <PS2X_lib.h>  //PS2X
#include <Wire.h> //allows communication over i2c devices
#include <LiquidCrystal_I2C.h> //LCD I2C
#include <Servo.h>
#include <SPI.h>

//==============PIN==============
//**************Input************* 
//PS2X 
#define PS2_DAT        23  //14    
#define PS2_CMD        25  //15
#define PS2_SEL        27  //16
#define PS2_CLK        29  //17

PS2X ps2x; // create PS2 Controller Class
int error = 0;
byte type = 0;
byte vibrate = 0;
int mode = 0;
int Delay = 50;
int Pot = 0;

int pwm_tangan = 60;
//Pressure Sensor
const int pressureInput = A0; 
const int pressureInput1 = A1; 
const int pressureZero = 102.4; 
const int pressureMax = 921.6; 
const int pressuretransducermaxPSI = 100; 
const int sensorreadDelay = 250; 
float pressureValue = 0; 
float pressureValue1 = 0; 

//ENCODER
const int SS1 = 41;
int16_t X = 0;
int8_t PosX = 0;

//LCD
LiquidCrystal_I2C lcd(0x3f, 16, 2); //sets the LCD I2C communication address; format(address, columns, rows)

//LIMIT SWITCH
const int LS1 = 31;
const int LS2 = 33;
const int LS3 = 35;
const int LS4 = 37;
const int LS5 = 39;
int ls1 = LOW;
int ls2 = LOW;
int ls3 = LOW;
int ls4 = LOW;
int ls5 = LOW;


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

//Motor Window
#define roller_pwm1 10
#define roller_pwm2 11

//Pneumatic Shooter
#define relay1 48
#define relay2 44
#define relay3 46

//Pneumatic Atas
#define relay4 44
#define relay5 42

//Pneumatic Bawah
#define relay6 40
#define relay7 38

//**********************TIMINGS************************//
int integral = 0;
int tmp_data = 0;
unsigned long currentmillis;
unsigned long prevmillis = 0;
int inputrate = 50;
int lcdratemultiplier = 3;
int lcdcount = 0;
float elapsedtime = (float)inputrate / 1000;

void setup() {

  Serial.begin(57600);
  //PS2X
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

  //Encoder
  delay(300);
  pinMode (SS1, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS1, HIGH);
  
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

  //LIMIT SWITCH
  delay(300);
  pinMode(LS1, INPUT_PULLUP);
  pinMode(LS2, INPUT_PULLUP);
  pinMode(LS3, INPUT_PULLUP);
  pinMode(LS4, INPUT_PULLUP);
  pinMode(LS5, INPUT_PULLUP);

  //LCD
  lcd.init(); //initializes the LCD screen
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
