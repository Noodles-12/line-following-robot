#include <Arduino.h>
#include <Motor.h>

// Motor A pins
const int PWMA = 6;
const int AIN1 = 8;
const int AIN2 = 7;

// Motor B pins
const int PWMB = 5;
const int BIN1 = 3;
const int BIN2 = 4;

// Create motor objects
Motor motor1(AIN1, AIN2, PWMA, -1);
Motor motor2(BIN1, BIN2, PWMB, -1);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Run both motors forward
  motor1.drive(125);
  motor2.drive(125);
  delay(300);

  // Brake both motors
  motor1.brake();
  motor2.brake();
  delay(300);

  motor1.drive(-125);
  motor2.drive(-125);
  delay(300);

  motor1.brake();
  motor2.brake();
  delay(300);
}