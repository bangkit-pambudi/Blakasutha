//110-108 servo
//==================LIBRARY=========================
#include <Servo.h>
#include <Psx.h>                                         
#include <Wire.h> //allows communication over i2c devices
#include <LiquidCrystal_I2C.h> 


//==================INPUT===========================
//PSX
#define dataPin 22
#define cmndPin 24
#define attPin 26
#define clockPin 28
Psx Psx;
unsigned int data = 0;

//Pressure Sensor
const int pressureInput = A0; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds
float pressureValue = 0; //variable to store the value coming from the pressure transducer


//==================OUTPUT===========================
//Motor DC
#define pwm_kiri_atas1 2
#define pwm_kiri_atas2 3
#define pwm_kiri_bawah1 4
#define pwm_kiri_bawah2 5
#define pwm_kanan_bawah1 6
#define pwm_kanan_bawah2 7
#define pwm_kanan_atas1 8
#define pwm_kanan_atas2 9
const int pwm_speed = 220;

#define roller_pwm1 10
#define roller_pwm2 13


//LCD
LiquidCrystal_I2C lcd(0x3f, 16, 2); //sets the LCD I2C communication address; format(address, columns, rows)

//Pneumatic
#define relay1 49
#define relay2 51
#define relay3 47
#define relay4 46
#define relay5 45
#define relay6 44
#define relay7 43

//servo
#define p_servo1 38

#define p_servo3 42

#define p_servo5 48


Servo servo1, servo3, servo5;

//timing
int integral = 0;
int tmp_data = 0;

void setup()
{
  //PSX
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);  // Defines what each pin is used
                                                          // (Data Pin #, Cmnd Pin #, Att Pin #, Clk Pin #, Delay)
                                                          // Delay measures how long the clock remains at each state,
                                                          // measured in microseconds.
                                                          // too small delay may not work (under 5)

  //Pneumatic
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

  //Motor
  pinMode(pwm_kiri_atas1, OUTPUT);
  pinMode(pwm_kiri_atas2, OUTPUT);
  pinMode(pwm_kiri_bawah1, OUTPUT);
  pinMode(pwm_kiri_bawah2, OUTPUT);
  pinMode(pwm_kanan_bawah1, OUTPUT);
  pinMode(pwm_kanan_bawah2, OUTPUT);
  pinMode(pwm_kanan_atas1, OUTPUT);
  pinMode(pwm_kanan_atas2, OUTPUT);

  pinMode(roller_pwm1, OUTPUT);
  pinMode(roller_pwm2, OUTPUT);

  //Servo
  servo1.attach(p_servo1);
  servo3.attach(p_servo3);
  servo5.attach(p_servo5);
    
  servo1.write(90);
  servo3.write(90);
  servo5.write(90);
  
  
  Serial.begin(9600);

  //LCD
  lcd.init(); //initializes the LCD screen
  lcd.backlight();
}


//Kiri Atas
void reset_kiri_atas(){
  analogWrite(pwm_kiri_atas1, 0);
  analogWrite(pwm_kiri_atas2, 0);
}

void kiri_atas_cw(int pwm){
  reset_kiri_atas();
  analogWrite(pwm_kiri_atas1, 0);
  analogWrite(pwm_kiri_atas2, pwm);
}

void kiri_atas_acw(int pwm){
  reset_kiri_atas();
  analogWrite(pwm_kiri_atas1, pwm);
  analogWrite(pwm_kiri_atas2, 0);
}
//-----------------------------------------------

//Kiri Bawah
void reset_kiri_bawah(){
  analogWrite(pwm_kiri_bawah1, 0);
  analogWrite(pwm_kiri_bawah2, 0);
}

void kiri_bawah_cw(int pwm){
  reset_kiri_bawah();
  analogWrite(pwm_kiri_bawah1, 0);
  analogWrite(pwm_kiri_bawah2, pwm);
}

void kiri_bawah_acw(int pwm){
  reset_kiri_bawah();
  analogWrite(pwm_kiri_bawah1, pwm);
  analogWrite(pwm_kiri_bawah2, 0);
}
//-----------------------------------------------

//Kanan Bawah
void reset_kanan_bawah(){
  analogWrite(pwm_kanan_bawah1, 0);
  analogWrite(pwm_kanan_bawah2, 0);
}

void kanan_bawah_cw(int pwm){
  reset_kanan_bawah();
  analogWrite(pwm_kanan_bawah1, 0);
  analogWrite(pwm_kanan_bawah2, pwm);
}

void kanan_bawah_acw(int pwm){
  reset_kanan_bawah();
  analogWrite(pwm_kanan_bawah1, pwm);
  analogWrite(pwm_kanan_bawah2, 0);
}
//-----------------------------------------------

//Kanan Atas
void reset_kanan_atas(){
  analogWrite(pwm_kanan_atas1, 0);
  analogWrite(pwm_kanan_atas2, 0);
}

void kanan_atas_cw(int pwm){
  reset_kanan_atas();
  analogWrite(pwm_kanan_atas1, 0);
  analogWrite(pwm_kanan_atas2, pwm);
}

void kanan_atas_acw(int pwm){
  reset_kanan_atas();
  analogWrite(pwm_kanan_atas1, pwm);
  analogWrite(pwm_kanan_atas2, 0);
}

void check_integral( int data){
  if(data != tmp_data){
    tmp_data = data;
    integral = 0;
  }
}

void loop()
{
  pressureValue = analogRead(pressureInput); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi
  lcd.setCursor(0,0); //sets cursor to column 0, row 0
  lcd.print("Pressure:"); //prints label
  lcd.print(pressureValue, 1); //prints pressure value to lcd screen, 1 digit on float
  lcd.print("psi"); //prints label after value
  lcd.print("  "); //to clear the display after large values or negatives
  
  data = Psx.read();
  
  if(integral < pwm_speed){
    integral+= 10;
  }
  Serial.println(data);

 

  if(data == 8704){ //L1 + X
    Serial.println("Servo elevator melepas panah");
    Serial.print(servo1.read());
    Serial.print("||");
    Serial.print(servo3.read());
    Serial.print("||");
    Serial.print(servo5.read());
    Serial.println("");
            
    if(servo1.read() > 0 ){
      servo1.write(servo1.read() - 2);
      servo2.write(servo2.read() - 2);
      servo3.write(servo3.read() - 2);
    }
  }

  if (data == 8448) { //L1 + Kotak
    Serial.println("Servo Elevator memutar ke belakang");
    digitalWrite(roller_pwm1, HIGH);
    digitalWrite(roller_pwm2, LOW);
  }else if (data == 10240){ //L1 + Segitiga
    Serial.println("Servo Elevator memutar ke depan");
    digitalWrite(roller_pwm1, LOW);
    digitalWrite(roller_pwm2, HIGH);  
  } else {
    digitalWrite(roller_pwm1, LOW);
    digitalWrite(roller_pwm2, LOW);}
  
  
  if(data == 9216){ //L1 + O
    Serial.println("Servo elevator menjepit panah");
    Serial.print(servo1.read());
    Serial.print("||");
    Serial.print(servo3.read());
    Serial.print("||");
    Serial.print(servo5.read());
    Serial.println("");
   
    if(servo1.read() < 180){
      servo1.write(servo1.read() + 2);
      servo3.write(servo3.read() + 2);
      servo5.write(servo5.read() + 2);
    }
  }


  if(data == 6144){ //R1 + Segitiga
    Serial.println("pelempar 1");
    digitalWrite(relay1, LOW);
  }else{
    digitalWrite(relay1, HIGH);
  }

  if(data == 5120){ //R1 + O
    Serial.println("pelempar 2");
    digitalWrite(relay2, LOW);
  }else{
    digitalWrite(relay2, HIGH);
  }

  if(data == 4608){ //R1 + X
    Serial.println("pelempar 3");
    digitalWrite(relay3, LOW);
  }else{
    digitalWrite(relay3, HIGH);
  } 

   if(data == 16640){ //R2 + Kotak
    Serial.println("Tangan Turun");
    digitalWrite(relay4, LOW);
  }else{
    digitalWrite(relay4, HIGH);
  } 

   if(data == 18432){ //R2 + Segitiga
    Serial.println("Tangan Naik");
    digitalWrite(relay5, LOW);
  }else{
    digitalWrite(relay5, HIGH);
  } 
  
  if(data == 17408){ //R2 + O
    Serial.println("Sudut ke posisi tembak");
    digitalWrite(relay6, LOW);
  }else{
    digitalWrite(relay6, HIGH);
  } 

  if(data == 16896){ //R2 + X
    Serial.println("Sudut ke posisi normal (lurus)");
    digitalWrite(relay7, LOW);
  }else{
    digitalWrite(relay7, HIGH);
  } 


  if(data == 8){
    Serial.println("Robot Maju");
    check_integral(data);
    kiri_atas_acw(integral + 10);
    kiri_bawah_acw(integral + 2);
    kanan_bawah_cw(integral + 5);
    kanan_atas_cw(integral - 2);
  }else
  if(data == 2){
    Serial.println("Robot Mundur");
    check_integral(data);
    kiri_atas_cw(integral);
    kiri_bawah_cw(integral + 7);
    kanan_bawah_acw(integral);
    kanan_atas_acw(integral);    
  }else
  if(data == 1){
    Serial.println("Robot Geser Kiri");
    check_integral(data);
    kiri_atas_cw(integral);
    kiri_bawah_acw(integral + 7);
    kanan_bawah_acw(integral + 5);
    kanan_atas_cw(integral); 
  }else
  if(data == 4){
    Serial.println("Robot Geser Kanan");
    check_integral(data);
    kiri_atas_acw(integral);
    kiri_bawah_cw(integral);
    kanan_bawah_cw(integral);
    kanan_atas_acw(integral); 
  }else
  if(data == 12){
    Serial.println("Robot Maju Serong Kanan");
    check_integral(data);
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    kanan_bawah_cw(integral);
    kiri_atas_acw(integral);
  }else
  if(data == 9){
    Serial.println("Robot Maju Serong Kiri");
    check_integral(data);
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    kiri_bawah_acw(integral);
    kanan_atas_cw(integral);
  }else
  if(data == 6){
    Serial.println("Robot Mundur Serong Kiri");
    check_integral(data);
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    kiri_bawah_cw(integral);
    kanan_atas_acw(integral);
  }else
  if(data == 3){
    Serial.println("Robot Mundur Serong Kanan");
    check_integral(data);
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    kanan_bawah_acw(integral);
    kiri_atas_cw(integral);
  }else
  if(data == 1024){
    Serial.println("Robot Putar Kanan");
    check_integral(data);
    kiri_atas_acw(pwm_speed - 170);
    kiri_bawah_acw(pwm_speed - 170);
    kanan_bawah_acw(pwm_speed - 170);
    kanan_atas_acw(pwm_speed - 170); 
  }else
  if(data == 256){
    Serial.println("Robot Putar Kiri");
    kiri_atas_cw(pwm_speed - 170);
    kiri_bawah_cw(pwm_speed - 170);
    kanan_bawah_cw(pwm_speed - 170);
    kanan_atas_cw(pwm_speed - 170);
  }else
  if(data == 512){
    Serial.println("Robot Putar Kanan");
    check_integral(data);
    kiri_atas_acw(integral);
    kiri_bawah_acw(integral);
    kanan_bawah_acw(integral);
    kanan_atas_acw(integral); 
  }else
  if(data == 2048){
    Serial.println("Robot Putar Kiri");
    check_integral(data);
    kiri_atas_cw(integral);
    kiri_bawah_cw(integral);
    kanan_bawah_cw(integral);
    kanan_atas_cw(integral);
  }else{
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    integral = 0;
  }
  delay(10);
}
