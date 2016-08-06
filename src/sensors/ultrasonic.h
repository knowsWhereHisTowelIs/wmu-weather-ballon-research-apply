
#ifndef sensors_ultrasonic_h
    #define sensors_ultrasonic_h

    class sensorsUltrasonicClass {
        private:
            int trigPin;
            int echoPin;
            //buffer for serial communication
            char *buffer;
            //what to display to lcd
            char (*lcdRows)[17];
        public:
            sensorsUltrasonicClass();
            void setup(char *buff, char rows[][17]);
            void loop();
    };

    extern sensorsUltrasonicClass sensorsUltrasonic;
#endif
