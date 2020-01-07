void getSonarDistance() {
	// clears the trig pin
	digitalWrite(PIN_SONAR_TRIG, LOW);
	delayMicroseconds(2);
	// sets the trig pin on HIGH state for 10 micro seconds
	digitalWrite(PIN_SONAR_TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(PIN_SONAR_TRIG, LOW);
	// reads the echo pin, returns the sound wave travel time in microseconds
	sonarDuration = pulseIn(PIN_SONAR_ECHO, HIGH, 0.0343 * 400 * 2);
	// calculating the distance
		sonarDistance = sonarDuration * 0.0343 / 2;
	// prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(sonarDistance);
}