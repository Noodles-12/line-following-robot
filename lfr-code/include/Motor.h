#pragma once

#include "Arduino.h"

/* TB6612FNG Notes:
    inp1 & inp2 control direction of motor:
        - inp1 HIGH, inp2 LOW: forward (CC)
        - inp1 LOW, inp2 HIGH: reverse (CCW)
        - inp1 HIGH, inp2 HIGH: short/instant brake
        - inp1 LOW, inp2 LOW: coast brake (free run)

    pwm controls speed of motor (0-255)
*/
class Motor {
public:
    Motor(int inp1, int inp2, int pwm, int offset);
    void drive(int speed);

    void brake();

    void coast();

     // Used to switch for the motor to standby mode; if LOW, shuts down everything & disconnects motors, so usually HIGH 
    //void standby();

private:
    int inp1, inp2, pwm, offset, standby;

    void fwd(int speed);
    void rev(int speed);
};