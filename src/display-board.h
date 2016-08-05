
#ifndef display_board_h
    #define display_board_h

    class displayBoardClass {
        private:
            char rowIndex;
            char rowCharIndex;
            char hasDisplayChanged;
        public:
            char rows[2][16];
            displayBoardClass();
            void setup();
            void beforeLoop();
            void loop();
            void afterLoop();
            void printRows();
    };

    extern displayBoardClass displayBoard;
#endif
