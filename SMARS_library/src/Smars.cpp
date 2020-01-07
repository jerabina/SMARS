#include "Smars.h"

Smars::Smars() {
	pinMode(PIN_MOTOR_A_EN, OUTPUT);
	pinMode(PIN_MOTOR_A_DIR, OUTPUT);
	pinMode(PIN_MOTOR_B_EN, OUTPUT);
	pinMode(PIN_MOTOR_B_DIR, OUTPUT);
	
	pinMode(PIN_BUZZER, OUTPUT);

	pinMode(PIN_SONAR_TRIG, OUTPUT);
	pinMode(PIN_SONAR_ECHO, INPUT);

	pinMode(PIN_SERVO, OUTPUT);

	devSonar = new NewPing(PIN_SONAR_TRIG, PIN_SONAR_ECHO, SONAR_MAX_DISTANCE);
	devServo = new Servo;
	devServo->attach(PIN_SERVO, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
}

// motorsBridge
void Smars::motorsBridge(int mAen, int mAdir, int mBen, int mBdir) {
	analogWrite(PIN_MOTOR_A_EN, mAen);
	digitalWrite(PIN_MOTOR_A_DIR, mAdir);
	analogWrite(PIN_MOTOR_B_EN, mBen);
	digitalWrite(PIN_MOTOR_B_DIR, mBdir);
}
// stoping both motors
void Smars::motorsStop() {
	this->motorsBridge(0, LOW, 0, LOW);
}
// both motors forward
void Smars::motorsForward(int speedSet) {
	this->motorsBridge(speedSet, HIGH, speedSet, LOW);
}
// both motors forward, separete speed
void Smars::motorsForward(int speedSetA, int speedSetB) {
	this->motorsBridge(speedSetA, HIGH, speedSetB, LOW);
}
// both motors backward
void Smars::motorsBack(int speedSet) {
	this->motorsBridge(speedSet, LOW, speedSet, HIGH);
}
// both motors backward, separete speed
void Smars::motorsBack(int speedSetA, int speedSetB) {
	this->motorsBridge(speedSetA, LOW, speedSetB, HIGH);
}
// left motor run
void Smars::motorsRight(int speedSet) {
	this->motorsBridge(0, HIGH, speedSet, LOW);
}
// right motor run
void Smars::motorsLeft(int speedSet) {
	this->motorsBridge(speedSet, HIGH, 0, HIGH);
} 


// sonar send a ping, returns the distance in centimeters or 0 (zero) if no ping echo within set distance limit
unsigned long Smars::sonar(unsigned int max_cm_distance) {
	return this->devSonar->ping_cm(max_cm_distance = 0);
}


// Writes a value (angle) to the servo, controlling the shaft accordingly. 
void Smars::servo(int value) {
	this->devServo->write(value);
}


// enable buzzer
void Smars::beepOn() {
	digitalWrite(PIN_BUZZER, HIGH);
}
// disable buzzer
void Smars::beepOff() {
	digitalWrite(PIN_BUZZER, LOW);
}
// buzzer play success beeps
void Smars::beepSuccess() {
	digitalWrite(PIN_BUZZER, HIGH);
	delay(80);
	digitalWrite(PIN_BUZZER, LOW);
	delay(30);
	digitalWrite(PIN_BUZZER, HIGH);
	delay(80);
	digitalWrite(PIN_BUZZER, LOW);
}
// buzzer play danger beeps
void Smars::beepDanger() {
	digitalWrite(PIN_BUZZER, HIGH);
	delay(30);
	digitalWrite(PIN_BUZZER, LOW);
	delay(30);
	digitalWrite(PIN_BUZZER, HIGH);
	delay(30);
	digitalWrite(PIN_BUZZER, LOW);
	delay(30);
	digitalWrite(PIN_BUZZER, HIGH);
	delay(30);
	digitalWrite(PIN_BUZZER, LOW);
	delay(30);
	digitalWrite(PIN_BUZZER, HIGH);
	delay(30);
	digitalWrite(PIN_BUZZER, LOW);
}