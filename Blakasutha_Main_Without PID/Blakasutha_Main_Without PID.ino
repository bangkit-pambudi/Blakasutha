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
int nJoyX;

int pwm_tangan;
//Pressure Sensor
const int pressureInput = A0; //select the analog input pin for the pressure transducer
const int pressureInput1 = A0; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds
float pressureValue = 0; //variable to store the value coming from the pressure transducer
float pressureValue1 = 0; //variable to store the value coming from the pressure transducer

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
#define relay1 40
#define relay2 42
#define relay3 44
#define relay4 46
#define relay5 48
#define relay6 50
#define relay7 52


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

  //LCD
  lcd.init(); //initializes the LCD screen
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  ps2x.read_gamepad(false, vibrate);
    
  if(integral < pwm_speed){
    integral+= 5;
  }
  //Serial.println(ps2x.Analog(PSS_RX));

  ReadInput();
  Gripper();
  Lengan();
  Pelempar();
  MoveRobot();
  delay(10);
}
