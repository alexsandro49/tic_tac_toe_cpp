#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


class TicTacToe {
    private:
        char possibles[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int winnerPlay[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    public:
        bool endGame = false;
        int playerWins = 0;
        int computerWins = 0;
        int ties = 0;

        void drawLine(char i, char j, char k, int z, bool floor);

        void colorChar(char color, int pos);

        void show();

        void play();

        bool verifyEndGame();

        void computerPlay();

        void restart();
};

#endif
