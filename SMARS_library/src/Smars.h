/*
  Smars.h - SMARS library for making robot
  (c) 2020 - Lubos Jerabek (Jerabina) <robotika@lubosjerabek.cz>
*/
#ifndef SMARS_H
#define SMARS_H

#include "Arduino.h"
#include <Servo.h>
#include <NewPing.h>


// motors connections
#define PIN_MOTOR_A_EN 5
#define PIN_MOTOR_A_DIR 12
#define PIN_MOTOR_B_EN 11
#define PIN_MOTOR_B_DIR 13

// buzzer connections
#define PIN_BUZZER 4

// sonar connections
#define PIN_SONAR_TRIG 8
#define PIN_SONAR_ECHO 7
#define SONAR_MAX_DISTANCE 200

// servo connection
#define PIN_SERVO 9
#define SERVO_MIN_PULSE_WIDTH 600
#define SERVO_MAX_PULSE_WIDTH 2400

// analog connection
#define PIN_ANALOG0 14
#define PIN_ANALOG1 15
#define PIN_ANALOG2 16
#define PIN_ANALOG3 17
#define PIN_ANALOG4 18
#define PIN_ANALOG5 19

// remote application keys
// Arduino Remote LITE (default setting)
// left top button
#define RMT_KEY_UNKNOWN_6      '1'
#define RMT_KEY_UNKNOWN_7      '2'
// left cross button
#define RMT_KEY_MOTORS_STOP    '0'
#define RMT_KEY_MOTORS_FORWARD 'w'
#define RMT_KEY_MOTORS_BACK    's'
#define RMT_KEY_MOTORS_RIGHT   'd'
#define RMT_KEY_MOTORS_LEFT    'a'
// center button
#define RMT_KEY_UNKNOWN_1      '5'
#define RMT_KEY_UNKNOWN_2      'v'
#define RMT_KEY_UNKNOWN_3      'b'
// right top button
#define RMT_KEY_MODE_DOWN      '3'
#define RMT_KEY_MODE_UP        '4'
// right cross button
#define RMT_KEY_SPEED_UP       '^'
#define RMT_KEY_UNKNOWN_4      '['
#define RMT_KEY_UNKNOWN_5      'o'
#define RMT_KEY_SPEED_DOWN     'x'

class Smars {
	private:
		Servo *devServo;
		NewPing *devSonar;
	public:
		Smars();
		
		void motorsBridge(int mAen, int mAdir, int mBen, int mBdir);
		void motorsStop();
		void motorsForward(int speedSet);
		void motorsForward(int speedSetA, int speedSetB);
		void motorsBack(int speedSet);
		void motorsBack(int speedSetA, int speedSetB);
		void motorsRight(int speedSet);
		void motorsLeft(int speedSet);
		
		unsigned long sonar(unsigned int max_cm_distance=0);
		
		void servo(int value);
		
		void beepOn();
		void beepOff();
		void beepSuccess();
		void beepDanger();
};
#endif  // SMARS_H