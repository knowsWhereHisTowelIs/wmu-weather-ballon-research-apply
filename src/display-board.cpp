
#include "Arduino.h"
// Get the LCD I2C Library here:
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>
#include "display-board.h"

/**
https://learn.sparkfun.com/tutorials/i2c
https://www.arduino.cc/en/Tutorial/MasterWriter
http://www.instructables.com/id/Arduino-Timer-Interrupts/?ALLSTEPS
https://www.arduino.cc/en/Tutorial/HelloWorld
https://arduino-info.wikispaces.com/LCD-Blue-I2C
Part: QAPASS 1602A
**/

/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// A FEW use address 0x3F
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
/*-----( Declare Variables )-----*/
//NONE

displayBoardClass::displayBoardClass() {
}

void displayBoardClass::setup() {
    Serial.println("Booting up hello world");
    lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

    // ------- Quick 3 blinks of backlight  -------------
    for(int i = 0; i < 2; i++) {
        lcd.backlight();
        delay(100);
        lcd.noBacklight();
        delay(100);
    }
    lcd.backlight(); // finish with backlight on

    //-------- Write characters on the display ------------------
    // Wait and then tell user they can start the Serial Monitor and type in characters to
    // Display. (Set Serial Monitor option to "No Line Ending")
    lcd.clear();
    lcd.setCursor(0,0); //Start at character 0 on line 0
    lcd.print("Use Serial Mon");
    lcd.setCursor(0,1);
    lcd.print("Type to display");
}

void displayBoardClass::loop() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LCD LOOP");
    // // when characters arrive over the serial port...
    // lcd.autoscroll();
    // if (Serial.available()) {
    //     // wait a bit for the entire message to arrive
    //     delay(100); //slow down if want to not wait for entire string
    //     // clear the screen
    //     //lcd.clear();
    //     // read all the available characters
    //     while (Serial.available() > 0) {
    //         // display each character to the LCD
    //         char c = Serial.read();
    //         lcd.write(c);
    //     }
    // }
}

displayBoardClass displayBoard = displayBoardClass();
