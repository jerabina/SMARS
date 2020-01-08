# SMARS robot library

This library is used to control the SMARS robot

Method:
- **motorsBridge(int mAen, int mAdir, int mBen, int mBdir)** - direct control of motor bridge pins
- **motorsStop()** - stops both motors 
- **motorsForward(int speedSet)** - both motor go forward at set speed
- **motorsForward(int speedSetA, int speedSetB)** - goes forward each motor has its speed set
- **motorsBack(int speedSet)** - both motor go back at set speed
- **motorsBack(int speedSetA, int speedSetB)** - goes back each motor has its speed set
- **motorsRight(int speedSet)** - turns right at specified speed
- **motorsLeft(int speedSet)** - turns left at specified speed
- **sonar(unsigned int max_cm_distance=0)** - returns the distance from the utrasonic sensor in centimeters
- **led(uint8_t r, uint8_t g, uint8_t b)** - light the neopixel ice into the RGB color
- **servo(int value)** - turns the servo to the set angle
- **beepOn()** - turns on the buzzer
- **beepOff()** - turns off the buzzer
- **beepSuccess()** - pseudo melody well buzzer
- **beepDanger()** - pseudo tunes wrong on buzzer

[SMARS robot github releases](https://github.com/jerabina/SMARS/releases)