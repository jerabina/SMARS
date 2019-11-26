int sensorLeft;
int sensorright;
int speed;

void setup() {
	speed = 100;
	pinMode(PIN_LINE_OUT2, INPUT);
	pinMode(PIN_LINE_OUT4, INPUT);

	pinMode(PIN_MOTOR_A_EN, OUTPUT);
	pinMode(PIN_MOTOR_A_DIR, OUTPUT);
	pinMode(PIN_MOTOR_B_EN, OUTPUT);
	pinMode(PIN_MOTOR_B_DIR, OUTPUT);
}

void loop() {
	// read sensors
	sensorLeft = digitalRead(PIN_LINE_OUT2);
	sensorright = digitalRead(PIN_LINE_OUT4);

	if (sensorLeft==0 && sensorright==1) {
		right(speed);

	} else if (sensorLeft==1 && sensorright==0) {
		left(speed);

	} else if (sensorLeft==0 && sensorright==0) {
		stop();

	} else {
		forward(speed);
	}
}

void forward(int speedSet) {                                                                                                                                                                 
	digitalWrite(PIN_MOTOR_A_DIR, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
	analogWrite(PIN_MOTOR_A_EN, speedSet);
	analogWrite(PIN_MOTOR_B_EN, speedSet);
}

void left(int speedSet) {
	digitalWrite(PIN_MOTOR_A_EN, LOW);
	analogWrite(PIN_MOTOR_B_EN, speedSet);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
}

void right(int speedSet) {
	analogWrite(PIN_MOTOR_A_EN, speedSet);
	digitalWrite(PIN_MOTOR_B_EN, LOW);
	digitalWrite(PIN_MOTOR_A_DIR, HIGH);
}

void backward(int speedSet) {
	digitalWrite(PIN_MOTOR_A_DIR, LOW);
	digitalWrite(PIN_MOTOR_B_DIR, HIGH);
	analogWrite(PIN_MOTOR_A_EN, speedSet);
	analogWrite(PIN_MOTOR_B_EN, speedSet);
}

void stop() {
	digitalWrite(PIN_MOTOR_A_EN, LOW);
	digitalWrite(PIN_MOTOR_B_EN, LOW);
}
