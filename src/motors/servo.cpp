#include "Arduino.h"
#include <Servo.h>

#include "servo.h"

/**
Part:
orange: signal/blue
red: Vcc (+5V)
brown: ground
**/

Servo servo;
int position;

motorsServoClass::motorsServoClass() {
    // analog pin used to connect the potentiometer
    servoPin = 8;
}

void motorsServoClass::setup(char *buff, char rows[][17]){
    buffer = buff;
    lcdRows = rows;
}

void motorsServoClass::beforeLoop() {
    servo.attach(servoPin);
    // reads the value of the potentiometer (value between 0 and 1023)
    // scale it to use it with the servo (value between 0 and 180)
    position = map(analogRead(servoPin), 0, 1023, 0, 180);
}

void motorsServoClass::loop() {
    //do nothing
}

/**
Keep keep servo in same place
**/
void motorsServoClass::knobLoop() {
    sprintf(lcdRows[0], "---SERVO KNOB---");
    sprintf(lcdRows[1], "Resists Movement");
    // sets the servo position according to the scaled value
    servo.write(position);
    //wait for servo to get to new position
    delay(15);
}

/**
sweep
**/
void motorsServoClass::sweepLoop() {
    sprintf(lcdRows[0], "---SERVO Sweep--");
    sprintf(lcdRows[1], "Sweeps angles   ");
    // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    for (position = 0; position <= 180; position += 1) {
        servo.write(position);
        // waits 15ms for the servo to reach the position
        delay(15);
    }
    // goes from 180 degrees to 0 degrees
    for (position = 180; position >= 0; position -= 1) {
        servo.write(position);
        // waits 15ms for the servo to reach the position
        delay(15);
    }
}

void motorsServoClass::afterLoop() {
    servo.detach();
}

motorsServoClass motorsServo = motorsServoClass();
