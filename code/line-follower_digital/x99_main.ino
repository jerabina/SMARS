float pTerm, iTerm, dTerm;
int error;
int previousError;
float kp = 11;
float ki = 0;
float kd = 11;
float output;
int integral, derivative;
int irSensors[] = {PIN_LINE_OUT1, PIN_LINE_OUT2, PIN_LINE_OUT3, PIN_LINE_OUT4, PIN_LINE_OUT5}; // IR sensor pins
int irReadings[5];
int motor1newSpeed;
int motor2newSpeed;
int motor2Speed = 120;
int motor1Speed = 120;
char data[100];

Tasker tasker;

void setup() {
	for (int pin = 0; pin < 5; pin++) {
		int pinNum = irSensors[pin];
		pinMode(pinNum, INPUT);
	}
	pinMode(PIN_MOTOR_A_EN, OUTPUT);
	pinMode(PIN_MOTOR_A_DIR, OUTPUT);
	pinMode(PIN_MOTOR_B_EN, OUTPUT);
	pinMode(PIN_MOTOR_B_DIR, OUTPUT);
	Serial.begin(115200);

	tasker.setInterval(taskDisplay, 200);

}

void loop() {
	tasker.loop();
	readIRSensors();
	calculateError();
	pidCalculations();
	changeMotorSpeed();
}

void readIRSensors() {
	// Read the IR sensors and put the readings in irReadings array
	for (int pin = 0; pin < 5; pin++) {
		int pinNum = irSensors[pin];
		irReadings[pin] = !digitalRead(pinNum);
	}
}

void calculateError() {
	error = (irReadings[0] * 4) + (irReadings[1] * 2) + (irReadings[2] * 0) + (irReadings[3] * -2) + (irReadings[4] * -4);
	if (error == 0 && irReadings[2] == 0 && previousError>0) {
		error = 10;
	} else if (error == 0 && irReadings[2] == 0 && previousError<0) {
		error = -10;
	}
}

void pidCalculations() {
	pTerm = kp * error;
	integral += error;
	iTerm = ki * integral;
	derivative = error - previousError;
	dTerm = kd * derivative;
	output = pTerm + iTerm + dTerm;
	previousError = error;
}

void changeMotorSpeed() {
	// Change motor speed of both motors accordingly
	motor2newSpeed = motor2Speed + output;
	motor1newSpeed = motor1Speed - output;
	// Constrain the new speed of motors to be between the range 0-255
	motor2newSpeed = constrain(motor2newSpeed, 0, 254);
	motor1newSpeed = constrain(motor1newSpeed, 0, 254);
	// Set new speed, and run motors in forward direction
	analogWrite(PIN_MOTOR_A_EN, motor2newSpeed);
	analogWrite(PIN_MOTOR_B_EN, motor1newSpeed);
	digitalWrite(PIN_MOTOR_A_DIR, HIGH);
	digitalWrite(PIN_MOTOR_B_DIR, LOW);
}

void taskDisplay() {
	sprintf(data, "Line:\t%d\t%d\t%d\t%d\t%d", irReadings[0], irReadings[1], irReadings[2], irReadings[3], irReadings[4]);
	Serial.println(data);
	
	sprintf(data, "Error:\t%d", error);
	Serial.println(data);
	
	sprintf(data, "Motors:\t%d\t%d\n", motor1newSpeed, motor2newSpeed);
	Serial.println(data);
}