#include <Wire.h>

/***************************INCLUDES***************************************/
#include "Arduino.h"
//---custom---
#include "blink.h"
#include "display-board.h"
#include "sensors/ultrasonic.h"

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
int action = 0;
char switchState = 0;

/**************************SETUP*****************************/
void setup() {
    //setup USB serial communication
    Serial.begin(9600);  // Used to type in characters
    while (!Serial) {}
    Serial.println("Serial ready");

    //setup push pin
    pinMode(pushPin, INPUT);      // sets the digital pin 7 as input

    //setup modules
    blink.setup();
    displayBoard.setup();
    sensorsUltrasonic.setup();
}

/**************************LOOP***************************/
void loop() {
    int val;
    val = digitalRead(pushPin);   // read the input pin
    //wait until lifted up on button before switching action
    if( val == 1 ) {
        while( val == 1 ) {
            val = digitalRead(pushPin);   // read the input pin
            blink.actionChange();
        }
        action++;
    }

    switch(action) {
        case 0:
            blink.loop();
            break;

        case 1:
            displayBoard.loop();
            break;
        case 2:
            sensorsUltrasonic.loop();
            break;

        default:
            action = 0;
            break;
    }
}
