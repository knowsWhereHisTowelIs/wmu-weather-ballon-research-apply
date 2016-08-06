
#ifndef blink_h
    #define blink_h

    class blinkClass {
        private:
            int pin;
            int pwmIndex;
            char *powerLevel;
            //buffer for serial communication
            char *buffer;
            //what to display to lcd
            char (*lcdRows)[17];
        public:
            blinkClass();
            void doubleBlink();
            void setup(char *buff, char rows[][17]);
            // void setup(char *, char*[16]);
            // void setup(char *);
            // void setup(char*[2][16]);
            void loop();
            void actionChange();
            void pwmBrightness();
    };

    extern blinkClass blink;
#endif
