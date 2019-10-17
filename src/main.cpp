// definice pinu
// motor A
#define PIN_MOTOR_A_EN 10
#define PIN_MOTOR_A_DIR 12
// motor B
#define PIN_MOTOR_B_EN 11
#define PIN_MOTOR_B_DIR 13

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
	/* chovani motor bridge
	EN  DIR    co dela motor
	0   0/1    motor stoji
	1    0     motor běží na jednu stranu
	1    1     motor běží na druhou stranu
	*/

	Serial.println("stop");
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, LOW);
	digitalWrite(PIN_MOTOR_A_DIR, LOW);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, LOW);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
	delay(1000);

	Serial.println("dopredu");
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, HIGH);
	digitalWrite(PIN_MOTOR_A_DIR, LOW);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, HIGH);
	delay(1000);

	Serial.println("dozadu");
	// motor A
	digitalWrite(PIN_MOTOR_A_EN, HIGH);
	digitalWrite(PIN_MOTOR_A_DIR, HIGH);
	// motor B
	digitalWrite(PIN_MOTOR_B_EN, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
	delay(1000);
}