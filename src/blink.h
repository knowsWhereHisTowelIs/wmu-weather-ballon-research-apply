
#ifndef blink_h
    #define blink_h

    void blinkFunc();

    class blinkClass {
        private:
            int pin;
        public:
            blinkClass();
            void doubleBlink();
            void setup();
            void loop();
            void actionChange();
    };

    extern blinkClass blink;
#endif
