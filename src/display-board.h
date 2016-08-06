
#ifndef display_board_h
    #define display_board_h

    class displayBoardClass {
        private:
            char rowIndex;
            char rowCharIndex;
            char hasDisplayChanged;
            char previousRows[2][17];
            //buffer for serial communication
            char *buffer;
        public:
            char rows[2][17];
            displayBoardClass();
            void setup(char *buff);
            void beforeLoop();
            void loop();
            void afterLoop();
            void printRows();
    };

    extern displayBoardClass displayBoard;
#endif
