# SMARS

## Hardware

I use Arduino UNO with modified FunduMoto shield. I swapped pins 5 and 10 to use the servo while driving motors using pwm

#define PIN_MOTOR_A_EN 5
#define PIN_MOTOR_A_DIR 12
#define PIN_MOTOR_B_EN 11
#define PIN_MOTOR_B_DIR 13
#define PIN_SERVO 9
#define PIN_BUZZER 4
#define PIN_SONAR_TRIG 8
#define PIN_SONAR_ECHO 7

## Software
- [Bluetooth rover](https://github.com/jerabina/SMARS/blob/master/bluetooth_rover/)
- [line follower digital](https://github.com/jerabina/SMARS/tree/master/line-follower_digital)
- [line follower digital easy](https://github.com/jerabina/SMARS/tree/master/line-follower_easy-digital)