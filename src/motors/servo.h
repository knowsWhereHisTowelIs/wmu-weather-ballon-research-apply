
#ifndef motors_servo_h
    #define motors_servo_h

    class motorsServoClass {
        private:
            int servoPin;
        public:
            motorsServoClass();
            void setup();
            void beforeLoop();
            void loop();
            void afterLoop();

            void knobLoop();
            void sweepLoop();
    };

    extern motorsServoClass motorsServo;
#endif
