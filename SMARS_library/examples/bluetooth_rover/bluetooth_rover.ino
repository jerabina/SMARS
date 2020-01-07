/*
--------------------------------------------------------------------------------
SMARS robot firmware
(Screwless/Screwed Modular Assemblable Robotic System)
url: https://www.thingiverse.com/thing:2662828
--------------------------------------------------------------------------------
The robot listens to the serial port for commands that come
via the Bluetooth module and drive like a remote control car

Android remote control: Arduino Remote LITE
url: https://play.google.com/store/apps/details?id=it.hieund.arduino_remote_lite

You need to have libraries installed: Servo, NewPing
--------------------------------------------------------------------------------
(c) 2019 - Lubos Jerabek <robotika@lubosjerabek.cz>
--------------------------------------------------------------------------------
*/

#include "Smars.h"

Smars robot;

int speed = 255;
int inDat;

void setup() {
	Serial.begin(9600);
	robot.beepSuccess();
}

void loop() {
	if (Serial.available()) {
		inDat = Serial.read();
		switch(inDat) {
			case RMT_KEY_MOTORS_STOP:
				robot.motorsStop();
				break;
			case RMT_KEY_MOTORS_FORWARD:
				robot.motorsForward(speed);
				break;
			case RMT_KEY_MOTORS_BACK:
				robot.motorsBack(speed);
				break;
			case RMT_KEY_MOTORS_RIGHT:
				robot.motorsRight(speed);
				break;
			case RMT_KEY_MOTORS_LEFT:
				robot.motorsLeft(speed);
				break;

			case RMT_KEY_SPEED_UP:
				speed = speed + 10;
				break;
			case RMT_KEY_SPEED_DOWN:
				speed = speed - 10;
				break;
		}
		if (speed<  0) {
			speed = 0;
			robot.beepDanger();
		}
		if (speed>255) {
			speed = 255;
			robot.beepDanger();
		}
	}
}