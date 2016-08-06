
#include "Arduino.h"
#include "blink.h"

blinkClass::blinkClass(){
    pin = 9; // brown
    pwmIndex = 0;
    powerLevel = new char[11];
    powerLevel[10] = '\0';
}

void blinkClass::setup(char *buff, char rows[][17]){
    buffer = buff;
    lcdRows = rows;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void blinkClass::loop() {
    //long pin on
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    digitalWrite(pin, LOW);
    delay(150);
    sprintf(lcdRows[0], "---Basic Blink--");
    sprintf(lcdRows[1], "                ");
    // lcdRows[1][0] = '\0';
    // sprintf(lcdRows[1], "                ");
    doubleBlink();
    delay(250);
}

void blinkClass::doubleBlink() {
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(100);               // wait for a second
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(100);               // wait for a second
}

void blinkClass::actionChange() {
    sprintf(lcdRows[0], "-----Blink------");
    sprintf(lcdRows[1], "--NEW ACTION !--");
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(50);               // wait for a second
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(150);               // wait for a second
}

void blinkClass::pwmBrightness() {
    sprintf(lcdRows[0], "---BLINK  PWM---");
    analogWrite(pin, map(pwmIndex, 0, 100, 0, 255));
    pwmIndex++;
    if( pwmIndex > 100 ) {
        pwmIndex = 0;
    }
    for(int i = 0, j = 0; i < 10; i++, j += 10 ) {
        powerLevel[i] = (j <= pwmIndex) ? i + '0' : ' ';
    }
    //remember terminating null char
    sprintf(lcdRows[1], "[%s]", powerLevel);
    delay(10);
}

blinkClass blink = blinkClass();
