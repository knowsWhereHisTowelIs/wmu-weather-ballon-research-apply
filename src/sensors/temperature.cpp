#include <math.h>
#include "Arduino.h"
#include "temperature.h"
/**
part: Xinda KY-038 Temperature sensor module for Arduino
resistance increases as it gets colder
http://www.arduinothai.com/product/162/digital-temperature-module-ky-028
https://www.youtube.com/watch?v=SlgueuILkpI
http://playground.arduino.cc/ComponentLib/Thermistor2
https://www.youtube.com/watch?v=9RO03TIiSDU&list=PLwnMi_b_qu7vx6f608858Q0LxaSahfXau&index=18
**/

sensorsTemperatureClass::sensorsTemperatureClass() {
    // blue
    sensorPin = A0;// select the input pin for the potentiometer
    // yellow
    sensorStatePin = 10;
}

void sensorsTemperatureClass::setup(char *buff, char rows[][17]){
    buffer = buff;
    lcdRows = rows;
    pinMode(sensorStatePin, INPUT);
}


void sensorsTemperatureClass::activate() {
    //do nothing
}

void sensorsTemperatureClass::loop() {
    sensorState = digitalRead(sensorStatePin);
    if( sensorState == HIGH ) {
        rawAnalog = analogRead(sensorPin);
    } else {
        rawAnalog = -1;
    }
    //print and limit ints to 3 chars
    sprintf(lcdRows[0], "--TEMP F:%03d--", ((int) getFahrenheit()) % 1000);
    sprintf(lcdRows[1], "---K:%03d C:%03d--", ((int) getKelvin()) % 1000, ((int) getCelcius()) % 1000);
    delay(100);
}

void sensorsTemperatureClass::deactivate() {
    //do nothing
}

double sensorsTemperatureClass::getKelvin() {
    double temp = log(10000.0/((1024.0/rawAnalog-1)));
    return 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
}

double sensorsTemperatureClass::getCelcius() {
    return getKelvin() - 273.15;
}

double sensorsTemperatureClass::getFahrenheit() {
    return ( getCelcius() * 9.0 / 5.0 ) + 32.0;
}

sensorsTemperatureClass sensorsTemperature = sensorsTemperatureClass();
