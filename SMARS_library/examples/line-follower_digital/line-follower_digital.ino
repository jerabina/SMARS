/*
--------------------------------------------------------------------------------
SMARS robot firmware
(Screwless/Screwed Modular Assemblable Robotic System)
url: https://www.thingiverse.com/thing:2662828
--------------------------------------------------------------------------------
The robot monitors the line with six IR sensors and travels along it.

You need to have libraries installed: Servo, NewPing
--------------------------------------------------------------------------------
(c) 2019 - Lubos Jerabek <robotika@lubosjerabek.cz>
--------------------------------------------------------------------------------
*/

#include "Smars.h"

Smars robot;

float pTerm, iTerm, dTerm;
int error;
int previousError;
float kp = 11;
float ki = 0;
float kd = 11;
float output;
int integral, derivative;
int irSensors[] = {PIN_ANALOG0, PIN_ANALOG1, PIN_ANALOG2, PIN_ANALOG3, PIN_ANALOG4}; // IR sensor pins
int irReadings[5];
int motor1newSpeed;
int motor2newSpeed;
int motor2Speed = 120;
int motor1Speed = 120;
char data[100];

void setup() {
	for (int pin = 0; pin < 5; pin++) {
		int pinNum = irSensors[pin];
		pinMode(pinNum, INPUT);
	}
	robot.beepSuccess();
}

void loop() {
	// Read the IR sensors and put the readings in irReadings array
	for (int pin = 0; pin < 5; pin++) {
		int pinNum = irSensors[pin];
		irReadings[pin] = !digitalRead(pinNum);
	}

	// calculate error
	error = (irReadings[0] * 4) + (irReadings[1] * 2) + (irReadings[2] * 0) + (irReadings[3] * -2) + (irReadings[4] * -4);
	if (error == 0 && irReadings[2] == 0 && previousError>0) {
		error = 10;
	} else if (error == 0 && irReadings[2] == 0 && previousError<0) {
		error = -10;
	}

	// calculate PID
	pTerm = kp * error;
	integral += error;
	iTerm = ki * integral;
	derivative = error - previousError;
	dTerm = kd * derivative;
	output = pTerm + iTerm + dTerm;
	previousError = error;

	// Change motor speed of both motors accordingly
	motor2newSpeed = motor2Speed + output;
	motor1newSpeed = motor1Speed - output;
	// Constrain the new speed of motors to be between the range 0-255
	motor2newSpeed = constrain(motor2newSpeed, 0, 254);
	motor1newSpeed = constrain(motor1newSpeed, 0, 254);
	// Set new speed, and run motors in forward direction
	robot.motorsForward(motor2newSpeed, motor1newSpeed);
}