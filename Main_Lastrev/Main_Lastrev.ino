//==============Library============
#include <PS2X_lib.h>  //PS2X
#include <Wire.h> //allows communication over i2c devices
#include <LiquidCrystal_I2C.h> //LCD I2C
#include <Servo.h>
#include <SPI.h>

//==============PIN==============
//**************Input************* 
//PS2X 
#define PS2_DAT        22  //14    
#define PS2_CMD        24  //15
#define PS2_SEL        26  //16
#define PS2_CLK        28  //17

PS2X ps2x; // create PS2 Controller Class
int error = 0;
byte type = 0;
byte vibrate = 0;
int nJoyX;

//Pressure Sensor
const int pressureInput = A0; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds
float pressureValue = 0; //variable to store the value coming from the pressure transducer

//ENCODER
const int SS1 = 41;
int16_t X = 0;
int8_t PosX = 0;

//LCD
LiquidCrystal_I2C lcd(0x3f, 16, 2); //sets the LCD I2C communication address; format(address, columns, rows)

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

void setup() {

  Serial.begin(57600);
  //PS2X
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

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

void loop() {
  // put your main code here, to run repeatedly:
  
  ps2x.read_gamepad(false, vibrate);
  
  nJoyX = ps2x.Analog(PSS_LX);
  nJoyX = map(nJoyX, 0, 255, -1023, 1023);
    
  if(integral < pwm_speed){
    integral+= 1;
  }
  //Serial.println(ps2x.Analog(PSS_RX));

  ReadInput();
  Gripper();
  Lengan();
  Pelempar();
  MoveRobot();
  delay(10);
}
