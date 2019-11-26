void setup() {
	pinMode(PIN_MOTOR_A_EN, OUTPUT);
	pinMode(PIN_MOTOR_A_DIR, OUTPUT);
	pinMode(PIN_MOTOR_B_EN, OUTPUT);
	pinMode(PIN_MOTOR_B_DIR, OUTPUT);
	pinMode(PIN_BUZZER, OUTPUT);

	Serial.begin(9600);
	beepSuccess();
}

void loop() {
	if (Serial.available()) {
		inDat = Serial.read();
		switch(inDat) {
			case RMT_KEY_MOTORS_STOP:
 				motorsStop();
				break;
			case RMT_KEY_MOTORS_FORWARD:
				motorsForward(speed);
				break;
			case RMT_KEY_MOTORS_BACK:
				motorsBack(speed);
				break;
			case RMT_KEY_MOTORS_RIGHT:
				motorsRight(speed);
				break;
			case RMT_KEY_MOTORS_LEFT:
				motorsLeft(speed);
				break;

			case RMT_KEY_SPEED_UP:
				speed = speed + 10;
				break;
			case RMT_KEY_SPEED_DOWN:
				speed = speed - 10;
				break;
		}
		if (speed<  0) {
		  speed=0;
      beepDanger();
		}
		if (speed>255) {
		  speed=255;
      beepDanger();
		}
	}
}
