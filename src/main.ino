#include <Wire.h>

/***************************INCLUDES***************************************/
#include "Arduino.h"
//---custom---
#include "blink.h"
#include "display-board.h"
#include "sensors/ultrasonic.h"
#include "sensors/temperature.h"
#include "motors/servo.h"

/**
Accomplishments:
Serial communication both ways (shown in LCD)
LED blinking
Distance sensors
Switch sensing
LCD display
**/

// ---- main vars----------
int pushPin = 10;
int pushPinVal;
int action = 4;
char hasSwitchedAction = 0;
extern char *buffer = new char[32];

/**************************SETUP*****************************/
void setup() {
    //setup USB serial communication
    // The speed is measured in bits per second, also known as
    // "baud rate". 9600 is a very commonly used baud rate,
    // and will transfer about 10 characters per second.
    Serial.begin(9600);  // Used to type in characters
    while (!Serial) {}
    Serial.println("Serial ready");

    //setup push pin
    pinMode(pushPin, INPUT);      // sets the digital pin 7 as input

    //setup modules
    blink.setup();
    displayBoard.setup();
    sensorsUltrasonic.setup();
    sensorsTemperature.setup();
    motorsServo.setup();
}

/**************************LOOP***************************/
void loop() {
    pushPinVal = digitalRead(pushPin);   // read the input pin
    //wait until lifted up on button before switching action
    if( pushPinVal == 1 ) {
        while( pushPinVal == 1 ) {
            pushPinVal = digitalRead(pushPin);   // read the input pin
            blink.actionChange();
        }
        action++;
        sprintf(buffer, "Change of action to:%d", action);
        Serial.println(buffer);
        hasSwitchedAction = 1;
    } else {
        hasSwitchedAction = 0;
    }

    switch(action) {
        case 0:
        blink.loop();
        break;

        case 1:
        if( hasSwitchedAction == 1 ) {
            displayBoard.beforeLoop();
        }
        displayBoard.loop();
        break;

        case 2:
        if( hasSwitchedAction == 1 ) {
            displayBoard.afterLoop();
        }
        sensorsUltrasonic.loop();
        break;

        case 3:
        sensorsTemperature.loop();
        sprintf(displayBoard.rows[0], "TEMP F:%d", (int) sensorsTemperature.getFahrenheit());
        sprintf(displayBoard.rows[1], "K:%d C:%d", (int) sensorsTemperature.getKelvin(), (int) sensorsTemperature.getCelcius());
        displayBoard.printRows();
        break;

        case 4:
        if( hasSwitchedAction == 1 ) {
            motorsServo.beforeLoop();
        }
        motorsServo.knobLoop();
        break;

        case 5:
        if( hasSwitchedAction == 1 ) {
            motorsServo.afterLoop();
            motorsServo.beforeLoop();
        }
        motorsServo.sweepLoop();
        break;

        case 6:
        if( hasSwitchedAction == 1 ) {
            motorsServo.afterLoop();
        }
        break;

        default:
        action = 0;
        break;
    }
}
