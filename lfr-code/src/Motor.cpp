#include <Motor.h>
#include <math.h>

Motor::Motor(int inp1, int inp2, int pwm, int offset) {
    this->inp1 = inp1;
    this->inp2 = inp2;
    this->pwm = pwm;
    this->offset = offset;

    pinMode(inp1, OUTPUT);
    pinMode(inp2, OUTPUT);
    pinMode(pwm, OUTPUT);
    pinMode(standby, OUTPUT);
}

void Motor::drive(int speed) {
    Serial.println("Driving at speed: " + String(speed));
    if (offset == -1) { speed = -speed; }
    if (speed > 0) { fwd(speed);}
    else if (speed < 0) { rev(abs(speed)); }
    else { brake(); }
}

void Motor::coast() {
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, LOW);
}

void Motor::brake() {
    digitalWrite(inp1, HIGH);
    digitalWrite(inp2, HIGH);
}

void Motor::fwd(int speed) {
    digitalWrite(inp1, HIGH);
    digitalWrite(inp2, LOW);
    analogWrite(pwm, speed);
}

void Motor::rev(int speed) {
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, HIGH);
    analogWrite(pwm, speed);
}