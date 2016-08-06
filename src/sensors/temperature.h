
#ifndef sensors_temperature_h
    #define sensors_temperature_h

    class sensorsTemperatureClass {
        private:
            int rawAnalog;
            int sensorPin;
            int sensorState;
            int sensorStatePin; // maybe remove?
            double temp;
            //buffer for serial communication
            char *buffer;
            //what to display to lcd
            char (*lcdRows)[17];
        public:
            sensorsTemperatureClass();
            void setup(char *buff, char rows[][17]);
            void activate();
            void loop();
            void deactivate();
            double getCelcius();
            double getFahrenheit();
            double getKelvin();
    };

    extern sensorsTemperatureClass sensorsTemperature;
#endif
