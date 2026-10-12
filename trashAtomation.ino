#include <ESP32Servo.h>

Servo servo;

#define PIN_TRIG 1
#define PIN_ECHO 3

void setup() {
  servo.attach(5);
  servo.write(90);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
}

void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  long time = pulseIn(PIN_ECHO, HIGH);
  
  float distance = time * 0.0343 / 2;

  if(distance <= 10){
    servo.write(90);
    delay(250);
    servo.write(0);
    delay(8000);
    servo.write(90);
    delay(250);
  }
}