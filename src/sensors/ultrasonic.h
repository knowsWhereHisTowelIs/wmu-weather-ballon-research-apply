
#ifndef sensors_ultrasonic_h
    #define sensors_ultrasonic_h

    class sensorsUltrasonicClass {
        private:
            int trigPin;
            int echoPin;
        public:
            sensorsUltrasonicClass();
            void setup();
            void loop();
    };

    extern sensorsUltrasonicClass sensorsUltrasonic;
#endif
