// #include <math.h>
// #include "Arduino.h"
// #include "tempature.h"
// #include "../display-board.h"
//
// /**
// part: Xinda KY-038 Temperature sensor module for Arduino
// http://www.arduinothai.com/product/162/digital-temperature-module-ky-028
// https://www.youtube.com/watch?v=SlgueuILkpI
// http://playground.arduino.cc/ComponentLib/Thermistor2
// **/
//
// sensorsTempatureClass::sensorsTempatureClass() {
//     // blue
//     sensorPin = A3;// select the input pin for the potentiometer
//     // yellow
//     sensorStatePin = 9;
// }
//
// void sensorsTempatureClass::setup() {
//     pinMode(sensorStatePin, INPUT);
// }
//
//
// void sensorsTempatureClass::activate() {
//     //do nothing
// }
//
// void sensorsTempatureClass::loop() {
//     sensorState = digitalRead(sensorStatePin);
//     if( sensorState == HIGH ) {
//         rawADC = analogRead(sensorPin);
//     } else {
//         rawADC = -1;
//     }
//     delay(200);
// }
//
// void sensorsTempatureClass::deactivate() {
//     //do nothing
// }
//
// double sensorsTempatureClass::getKelvin() {
//     // double temp = log(10000.0/((1024.0/rawADC-1)));
//     // return 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
//
//     double Temp;
//     Temp = log(10000.0*((1024.0/rawADC-1)));
//     // Temp =log(10000.0/(1024.0/rawADC-1)); // for pull-up configuration
//     Temp = 1 / (0.001129148 + 0.000234125 + (0.0000000876741 * Temp * Temp ) * Temp );
//     return Temp;
// }
//
// double sensorsTempatureClass::getCelcius() {
//     return getKelvin() - 273.15;
// }
//
// double sensorsTempatureClass::getFahrenheit() {
//     return ( getCelcius() * 9.0 / 5.0 ) + 32.0;
// }
//
// double Thermistor(int RawADC) {
//     double Temp;
//     Temp = log(10000.0*((1024.0/RawADC-1)));
//     Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
//     Temp = Temp - 273.15;            // Convert Kelvin to Celcius
//     //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
//     return Temp;
// }
//
// sensorsTempatureClass sensorsTempature = sensorsTempatureClass();
