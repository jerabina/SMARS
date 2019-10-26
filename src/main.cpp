#include <arduino.h>
// definice pinu
// motor A
#define PIN_MOTOR_A_EN 10
#define PIN_MOTOR_A_DIR 12
// motor B
#define PIN_MOTOR_B_EN 11
#define PIN_MOTOR_B_DIR 13

void vpred();
void vlevo();
void vpravo();
void vzad();
void stuj();

void setup() {
	// inicializace pinu
	// motor A
	pinMode(PIN_MOTOR_A_EN, OUTPUT);
	pinMode(PIN_MOTOR_A_DIR, OUTPUT);
	// motor B
	pinMode(PIN_MOTOR_B_EN, OUTPUT);
	pinMode(PIN_MOTOR_B_DIR, OUTPUT);
	Serial.begin(115200);
}

void loop() {
	vpred();
	delay(1000);
	vlevo();
	delay(800);
	vpravo();
	delay(800);
	vzad();
	delay(1000);
	stuj();
	delay(1000);
}

void vpred() {
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, HIGH);
	digitalWrite(PIN_MOTOR_A_DIR, HIGH);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
}

void vlevo() {
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, HIGH);
	digitalWrite(PIN_MOTOR_A_DIR, LOW);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
}

void vpravo() {
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, HIGH);
	digitalWrite(PIN_MOTOR_A_DIR, HIGH);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, HIGH);
}

void vzad() {
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, HIGH);
	digitalWrite(PIN_MOTOR_A_DIR, LOW);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, HIGH);
}

void stuj() {
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, LOW);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, LOW);
}