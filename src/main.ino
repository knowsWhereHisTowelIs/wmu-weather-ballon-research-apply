#include <Wire.h>

/***************************INCLUDES***************************************/
#include "Arduino.h"
//---custom---
#include "display-board.h"
#include "blink.h"
#include "sensors/ultrasonic.h"
#include "sensors/temperature.h"
#include "motors/servo.h"

/**
Accomplishments:
Serial communication both ways (shown in LCD)
LED blinking
LED PWM
temperature sensor
Distance sensor
Switch sensing
LCD display
Servo resist movement
Servo sweep
**/

// ---- main vars----------
int pushPin = 11;
int pushPinVal;
int action = 0;
char hasSwitchedAction = 0;
char *buffer = new char[32];

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
    // blink.setup(buffer);//, displayBoard.rows);
    // blink.test( (char **) displayBoard.rows);
    displayBoard.setup(buffer);
    blink.setup(buffer, displayBoard.rows);
    sensorsUltrasonic.setup(buffer, displayBoard.rows);
    sensorsTemperature.setup(buffer, displayBoard.rows);
    motorsServo.setup(buffer, displayBoard.rows);
}

/**************************LOOP***************************/
void loop() {
    pushPinVal = digitalRead(pushPin);   // read the input pin
    //wait until lifted up on button before switching action
    if( pushPinVal == 1 ) {
        while( pushPinVal == 1 ) {
            pushPinVal = digitalRead(pushPin);   // read the input pin
            blink.actionChange();
            displayBoard.printRows();
        }
        action++;
        sprintf(buffer, "Change of action to:%d", action);
        Serial.println(buffer);
        hasSwitchedAction = 1;
    } else {
        hasSwitchedAction = 0;
    }

    // Serial.println("\nBEFORE");
    // Serial.println(action);
    // Serial.println(displayBoard.rows[0]);
    // Serial.println(displayBoard.rows[1]);
    // delay(100);
    displayBoard.printRows();
    // Serial.println("AFTER\n");
    // delay(100);

    switch(action) {
        case 0:
        blink.loop();
        break;

        case 1:
        blink.pwmBrightness();
        break;

        case 2:
        if( hasSwitchedAction == 1 ) {
            displayBoard.beforeLoop();
        }
        displayBoard.loop();
        break;

        case 3:
        if( hasSwitchedAction == 1 ) {
            displayBoard.afterLoop();
        }
        sensorsUltrasonic.loop();
        break;

        case 4:
        sensorsTemperature.loop();
        break;

        case 5:
        if( hasSwitchedAction == 1 ) {
            motorsServo.beforeLoop();
        }
        motorsServo.knobLoop();
        break;

        case 6:
        if( hasSwitchedAction == 1 ) {
            motorsServo.afterLoop();
            motorsServo.beforeLoop();
        }
        motorsServo.sweepLoop();
        break;

        case 7:
        if( hasSwitchedAction == 1 ) {
            motorsServo.afterLoop();
        }
        break;

        default:
        sprintf(displayBoard.rows[0], "END OF ACTIONS");
        sprintf(displayBoard.rows[1], "Action = 0");
        Serial.println("Action = 0");
        delay(500);
        action = 0;
        break;
    }
}
