
#ifndef motors_servo_h
    #define motors_servo_h

    class motorsServoClass {
        private:
            int servoPin;
            //buffer for serial communication
            char *buffer;
            //what to display to lcd
            char (*lcdRows)[17];
        public:
            motorsServoClass();
            void setup(char *buff, char rows[][17]);
            void beforeLoop();
            void loop();
            void afterLoop();

            void knobLoop();
            void sweepLoop();
    };

    extern motorsServoClass motorsServo;
#endif
