void setup() {
	pinMode(PIN_MOTOR_A_EN, OUTPUT);
	pinMode(PIN_MOTOR_A_DIR, OUTPUT);
	pinMode(PIN_MOTOR_B_EN, OUTPUT);
	pinMode(PIN_MOTOR_B_DIR, OUTPUT);
	pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_SONAR_TRIG, OUTPUT);
  pinMode(PIN_SONAR_ECHO, INPUT);

	Serial.begin(9600);
	beepSuccess();
}

void loop() {
	getSonarDistance();

  if (sonarDistance<10) {
    motorsStop();
    delay(2);
    motorsBack(150);
    delay(1000);
    motorsLeft(150);
    delay(1000);
    motorsStop();
        
  } else {
    motorsForward(speed);
  }
  delay(100);
}
