void getSonarDistance() {
  // Clears the trig pin
  digitalWrite(PIN_SONAR_TRIG, LOW);
  delayMicroseconds(2);
  // Sets the trig pin on HIGH state for 10 micro seconds
  digitalWrite(PIN_SONAR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_SONAR_TRIG, LOW);
  // Reads the echo pin, returns the sound wave travel time in microseconds
  sonarDuration = pulseIn(PIN_SONAR_ECHO, HIGH);
  // Calculating the distance
  sonarDistance = sonarDuration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(sonarDistance);
}
