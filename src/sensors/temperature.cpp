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

//todo delete
char* temperatureBuffer = new char[32];
char doubleTmp[6];

sensorsTemperatureClass::sensorsTemperatureClass() {
    // blue
    sensorPin = A3;// select the input pin for the potentiometer
    // yellow
    sensorStatePin = 9;
}

void sensorsTemperatureClass::setup() {
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
    delay(200);
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
