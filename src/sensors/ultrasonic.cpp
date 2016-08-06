
#include "Arduino.h"
#include "ultrasonic.h"

/**
Part: HC SR04
**/

/*
http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/?ALLSTEPS
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

sensorsUltrasonicClass::sensorsUltrasonicClass() {
    // orange
    trigPin = 13;
    // yellow
    echoPin = 12;
}

void sensorsUltrasonicClass::setup(char *buff, char rows[][17]){
    buffer = buff;
    lcdRows = rows;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void sensorsUltrasonicClass::loop() {
    long duration, cm;
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    // convert the time into a distance
    cm = (duration/2) / 29.1;
    sprintf(lcdRows[0], "---ULTRASONIC---");
    //print and limit to 3 chars
    sprintf(lcdRows[1], "Dur:%03d CM:%03d", ((int) duration) % 1000, ((int) cm) % 1000);
    //also print more precisly to usb
    sprintf(buffer, "Duration:%ld cm:%ld", duration, cm);
    Serial.println(buffer);
    delay(250);
}

sensorsUltrasonicClass sensorsUltrasonic = sensorsUltrasonicClass();
