
#include "Arduino.h"
#include "blink.h"

void blinkFunc() {
    //long pin on
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);
    digitalWrite(13, LOW);
    delay(150);
}

blinkClass::blinkClass(){
    pin = 11;
}

void blinkClass::setup(){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}

void blinkClass::loop() {
    blinkFunc();
    doubleBlink();
    delay(500);
}

void blinkClass::doubleBlink() {
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(200);               // wait for a second
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(200);               // wait for a second
}

void blinkClass::actionChange() {
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(50);               // wait for a second
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(250);               // wait for a second
}

blinkClass blink = blinkClass();
