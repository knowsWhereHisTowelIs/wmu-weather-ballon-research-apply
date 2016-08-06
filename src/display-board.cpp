
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
//LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin,BACKLIGHT_PIN,POSITIVE);
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
/*-----( Declare Variables )-----*/
//NONE

displayBoardClass::displayBoardClass() {
    //ground - black
    //vcc - red
    // A4 and A5 are arduinos analog pins
    //sda - yellow - analog 4 (data line)
    // int sda;
    //scl - blue - analog 5 ( clock line)
    // int scl;
    //row index for which row to read
    rowIndex = 0;
    //0-15 for which character in rows to read
    rowCharIndex = 0;
    hasDisplayChanged = 0;

    for( int i = 0; i < 2; i++ ) {
        for ( int j = 0; j < 16; j++ ) {
            rows[i][j] = ' ';
            previousRows[i][j] = ' ';
        }
    }
    rows[0][16] = '\0';
    rows[1][16] = '\0';

    previousRows[0][16] = '\0';
    previousRows[1][16] = '\0';
}

void displayBoardClass::setup(char *buff){
    buffer = buff;
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
}

void displayBoardClass::beforeLoop() {
    lcd.clear();
    sprintf(rows[0], "----- LCD! -----");
    sprintf(rows[1], "Ready for input!");
    Serial.println("LCD ready for input!");
    printRows();

    rowIndex = 0;
    rowCharIndex = 0;
    delay(1000);
    sprintf(rows[0], "                ");
    sprintf(rows[1], "                ");
    lcd.clear();
}

void displayBoardClass::loop() {
    // lcd.autoscroll();
    if( hasDisplayChanged == 1 ) {
        printRows();
        hasDisplayChanged = 0;
    }
    // when characters arrive over the serial port...
    if (Serial.available()) {
        // lcd.print("Waiting for serial message");
        delay(100); // wait a bit for the entire message to arrive
        // read all the available characters
        while (Serial.available() > 0) {
            // display each character to the LCD
            char c = Serial.read();
            if( rowCharIndex > 15 ) {
                rowCharIndex = 0;
                if( rowIndex == 1 ) {
                    for( int i = 0; i < 16; i ++ ) {
                        rows[0][i] = rows[1][i];
                        rows[1][i] = ' ';
                    }
                }
                rowIndex = 1;
            }

            rows[rowIndex][rowCharIndex] = c;
            rowCharIndex++;
            hasDisplayChanged = 1;
        }
    }
}

void displayBoardClass::afterLoop() {

}

void displayBoardClass::printRows() {
    hasDisplayChanged = 0;
    for(int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 16; j++ ) {
            if( rows[i][j] != previousRows[i][j] ) {
                hasDisplayChanged = 1;
                break;
            }
        }
        if( hasDisplayChanged == 1 ) {
            break;
        }
    }
    if( hasDisplayChanged == 1 ) {
        lcd.clear();
        for(int i = 0; i < 2; i++ ) {
            // lcd.setCursor(0, i);
            for( int j = 0; j < 16; j++ ) {
                // lcd.write(rows[i][j]);
                previousRows[i][j] = rows[i][j];
            }
        }
        lcd.print(rows[0]);
        lcd.setCursor(0,1);
        lcd.print(rows[1]);
        delay(100);
    }
}

displayBoardClass displayBoard = displayBoardClass();
