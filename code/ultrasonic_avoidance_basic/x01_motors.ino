
void motorsBridge(int mAen, int mAdir, int mBen, int mBdir) {
	analogWrite(PIN_MOTOR_A_EN, mAen);
	digitalWrite(PIN_MOTOR_A_DIR, mAdir);
	analogWrite(PIN_MOTOR_B_EN, mBen);
	digitalWrite(PIN_MOTOR_B_DIR, mBdir);
}

void motorsStop() {
	motorsBridge(0, LOW, 0, LOW);
}

void motorsForward(int speedSet) {
	motorsBridge(speedSet, HIGH, speedSet, LOW);
}

void motorsBack(int speedSet) {
	motorsBridge(speedSet, LOW, speedSet, HIGH);
}

void motorsRight(int speedSet) {
	motorsBridge(0, HIGH, speedSet, LOW);
}

void motorsLeft(int speedSet) {
	motorsBridge(speedSet, HIGH, 0, HIGH);
}
