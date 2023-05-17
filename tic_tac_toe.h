#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


class TicTacToe {
    private:
        char possibles[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    public:
        bool endGame = false;
        int playerWins, computerWins, ties;

        void drawLine(char x, char y, char z, bool floor);

        void colorChar(char color);

        void show();

        void play();

        bool verifyEndGame();

        void computerPlay();

        void restart();
};

#endif
