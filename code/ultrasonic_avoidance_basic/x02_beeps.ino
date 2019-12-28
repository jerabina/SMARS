void beepSuccess() {
	digitalWrite(PIN_BUZZER, HIGH);
	delay(80);
	digitalWrite(PIN_BUZZER, LOW);
	delay(30);
	digitalWrite(PIN_BUZZER, HIGH);
	delay(80);
	digitalWrite(PIN_BUZZER, LOW);
}
 
void beepDanger() {
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
