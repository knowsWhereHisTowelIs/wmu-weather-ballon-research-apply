
#ifndef display_board_h
    #define display_board_h

    class displayBoardClass {
        private:
            //ground - black
            //vcc - red
            //sda - yellow - analog 4 (data line)
            // int sda;
            //scl - blue - analog 5 ( clock line)
            // int scl;
        public:
            displayBoardClass();
            void setup();
            void loop();
    };

    extern displayBoardClass displayBoard;
#endif
