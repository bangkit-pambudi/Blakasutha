#include <SPI.h>

const int ENCODER_DT = 2;
const int ENCODER_CLOCK = 3;
volatile int a0;
volatile int c0;
volatile int8_t Count = 0;
bool Up;

void ISR0()
{
  int a = digitalRead(ENCODER_DT);
  int b = digitalRead(ENCODER_CLOCK);   
  if (a != a0) {                  
    a0 = a;
    if (b != c0) {
      c0 = b;
      Up = (a == b);
      Count = max(min((Count + (Up ? 1 : -1)), 127), -128);
      Serial.println(Count);
    }
  }
}

ISR (SPI_STC_vect)
{
  SPDR = Count;
  Count = 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_CLOCK, INPUT);
  attachInterrupt(0, ISR0, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
}
