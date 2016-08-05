
#ifndef sensors_temperature_h
    #define sensors_temperature_h

    class sensorsTemperatureClass {
        private:
            int rawAnalog;
            int sensorPin;
            int sensorState;
            int sensorStatePin; // maybe remove?
            double temp;
        public:
            sensorsTemperatureClass();
            void setup();
            void activate();
            void loop();
            void deactivate();
            double getCelcius();
            double getFahrenheit();
            double getKelvin();
    };

    extern sensorsTemperatureClass sensorsTemperature;
#endif
