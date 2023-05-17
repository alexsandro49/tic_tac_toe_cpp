#include <iostream>
#include <iomanip>
#include <ctime>

class TicTacToe {
    private:
        char possibles[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    public:
        bool endGame = false;
        int playerWins, computerWins, ties;

        void drawLine(char x, char y, char z, bool floor = false) {
            std::cout << "     |     |     \n";
            colorChar(x);
            std::cout << x << "\033[0m" << "  |";
            colorChar(y);
            std::cout << y << "\033[0m" << "  |";
            colorChar(z);
            std::cout << z << "\033[0m" << '\n';
            floor ? std::cout << "_____|_____|_____\n" : std::cout << "     |     |     \n";
        }

        void colorChar(char color) {
                if (color == 'X') { std::cout << "  " << "\033[1;34m"; } 
                else if (color == 'O') { std::cout << "  " << "\033[1;31m"; }
                else { std::cout << "  "; }
            }

        void show() {
            drawLine(possibles[0], possibles[1], possibles[2], true);
            drawLine(possibles[3], possibles[4], possibles[5], true);
            drawLine(possibles[6], possibles[7], possibles[8]);
            std::cout << "-----------------\n";
        }

        void play() {
            int x;
            bool validMove = false;

            do {
                std::cout << "\nESCOLHA ONDE JOGAR (1-9): ";
                std::cin >> x;

                switch (x) {
                    case 1:
                        if (possibles[0] == '1') { 
                            validMove = true; 
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 2:
                        if (possibles[1] == '2') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 3:
                        if (possibles[2] == '3') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 4:
                        if (possibles[3] == '4') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 5:
                        if (possibles[4] == '5') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 6:
                        if (possibles[5] == '6') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 7:
                        if (possibles[6] == '7') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 8:
                        if (possibles[7] == '8') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    case 9:
                        if (possibles[8] == '9') {
                            validMove = true;
                        } else {
                            std::cout << "\nJOGADA INVÁLIDA!\n";
                        }
                        break;
                    default:
                        std::cout << "\nJOGADA INVÁLIDA!\n";
                        break;
                }
            } while(!validMove);

            possibles[x-1] = 'X';
            endGame = verifyEndGame();
        }

        bool verifyEndGame() {    
            int counter = 0;
            for (int i = 0; i < 9; i++) {
                if (possibles[i] == 'X' || possibles[i] == 'O') {
                    counter++;
                }
            }
            if (counter == 9) {
                ties++; return true;
            }

            if ((possibles[0] == 'X' && possibles[1] == 'X' && possibles[2] == 'X') || (possibles[3] == 'X' && possibles[4] == 'X' && possibles[5] == 'X') || (possibles[6] == 'X' && possibles[7] == 'X' && possibles[8] == 'X'))
            { 
                playerWins++; return true;
            }
            else if ((possibles[0] == 'X' && possibles[3] == 'X' && possibles[6] == 'X') || (possibles[1] == 'X' && possibles[4] == 'X' && possibles[7] == 'X') || (possibles[2] == 'X' && possibles[5] == 'X' && possibles[8] == 'X'))
            {
                playerWins++; return true;
            }
            else if ((possibles[0] == 'X' && possibles[4] == 'X' && possibles[8] == 'X') || (possibles[2] == 'X' && possibles[4] == 'X' && possibles[6] == 'X'))
            {
                playerWins++; return true;
            }
            else if ((possibles[0] == 'O' && possibles[1] == 'O' && possibles[2] == 'O') || (possibles[3] == 'O' && possibles[4] == 'O' && possibles[5] == 'O') || (possibles[6] == 'O' && possibles[7] == 'O' && possibles[8] == 'O')) 
            {
                computerWins++; return true;
            }
            else if ((possibles[0] == 'O' && possibles[3] == 'O' && possibles[6] == 'O') || (possibles[1] == 'O' && possibles[4] == 'O' && possibles[7] == 'O') || (possibles[2] == 'O' && possibles[5] == 'O' && possibles[8] == 'O'))
            {
                computerWins++; return true;
            }
            else if ((possibles[0] == 'O' && possibles[4] == 'O' && possibles[8] == 'O') || (possibles[2] == 'O' && possibles[4] == 'O' && possibles[6] == 'O'))
            {
                computerWins++; return true;
            }
            else {
                return false;
            }
        }

        void computerPlay() {
            bool ok = false;
            int computerPlay;

            srand(time(0));


            for (int i = 0; i < 3; i++) {
                if ((possibles[0+3*i] != 'X' && possibles[0+3*i] != 'O') && possibles[1+3*i] == 'X' && possibles[2+3*i] == 'X') {
                    computerPlay = 0+3*i; ok = true; break;
                } else if (possibles[0+3*i] == 'X' && (possibles[1+3*i] != 'X' && possibles[1+3*i] != 'O') && possibles[2+3*i] == 'X') {
                    computerPlay = 1+3*i; ok = true; break;
                } else if (possibles[0+3*i] == 'X' && possibles[1+3*i] == 'X' && (possibles[2+3*i] != 'X' && possibles[2+3*i] != 'O')) {
                    computerPlay = 2+3*i; ok = true; break;
                }
            }

            if (!ok) {
                for (int i = 0; i < 3; i++) {
                    if ((possibles[0+i] != 'X' && possibles[0+i] != 'O') && possibles[3+i] == 'X' && possibles[6+i] == 'X') {
                        computerPlay = i+0; ok = true; break;
                    }
                    else if (possibles[0+i] == 'X' && (possibles[3+i] != 'X' && possibles[3+i] != 'O') && possibles[6+i] == 'X') {
                        computerPlay = i+3; ok = true; break;
                    }
                    else if (possibles[0+i] == 'X' && possibles[3+i] == 'X' && (possibles[6+i] != 'X' && possibles[6+i] != 'O')) {
                        computerPlay = i+6; ok = true; break;
                    }
                }
            }
            if (!ok) {
                for (int i = 0; i < 2; i++) {
                    if ((possibles[i] != 'X' && possibles[i] != 'O') && possibles[4] == 'X' && possibles[8-2*i] == 'X') {
                        computerPlay = 0+2*i; ok = true; break;
                    } else if (possibles[i] == 'X' && (possibles[4] != 'X' && possibles[4] != 'O') && possibles[8-2*i] == 'X') {
                        computerPlay = 4; ok = true; break;
                    } else if (possibles[i] == 'X' && possibles[4] == 'X' && (possibles[8-2*i] != 'X' && possibles[8-2*i] != 'O')) {
                        computerPlay = 8-2*i; ok = true; break;
                    }
                }
            }

            while (!ok) {
                int play = (rand() % 9) + 1;
                
                switch (play) {
                    case 1:
                        if (possibles[play-1] == '1') { ok = true; }
                        break;
                    case 2:
                        if (possibles[play-1] == '2') { ok = true; }
                        break;
                    case 3:
                        if (possibles[play-1] == '3') { ok = true; }
                        break;
                    case 4:
                        if (possibles[play-1] == '4') { ok = true; }
                        break;
                    case 5:
                        if (possibles[play-1] == '5') { ok = true; }
                        break;
                    case 6:
                        if (possibles[play-1] == '6') { ok = true; }
                        break;
                    case 7:
                        if (possibles[play-1] == '7') { ok = true; }
                        break;
                    case 8:
                        if (possibles[play-1] == '8') { ok = true; }
                        break;
                    case 9:
                        if (possibles[play-1] == '9') { ok = true; }
                        break;
                }
                computerPlay = play-1;
            }
            
            possibles[computerPlay] = 'O';
            endGame = verifyEndGame();
        }

        void restart() {
            for (int i = 49; i<58; i++) {
                possibles[i-49] = static_cast<char>(i);
            }
        }
};

void beginGame(TicTacToe game) {
    game.show();
    while (true) {
        game.play();
        game.show();
        if (game.endGame) {
            break;
        }
        game.computerPlay();
        game.show();
        if (game.endGame) {
            break;
        }
    }

    std::cout << std::setfill('-') << std::setw(30) << "\n";
    bool finish = false;
    int opc;
    while (true)
    {
        std::cout << "JOGAR NOVAMENTE?\n";
        std::cout << "1 - SIM\n" << "2 - NÃO\n" << ": ";
        std::cin >> opc;

        switch (opc) {
            case 1:
                game.restart();
                beginGame(game);
                break;
            case 2:
                std::cout << std::setfill('-') << std::setw(30) << "\n";
                std::cout << std::setfill('-') << std::setw(30) << "\n" ;
                std::cout << "PONTUAÇÃO JOGADOR: " << game.playerWins << '\n';
                std::cout << "PONTUAÇÃO COMPUTADOR: " << game.computerWins << '\n';
                std::cout << "EMPATES: " << game.ties << '\n';
                std::cout << std::setfill('-') << std::setw(30) << "\n";
                std::cout << std::setfill('-') << std::setw(30) << "\n";

                exit(0);
                break;
            default:
                std::cout << "OPÇÃO INVÁLIDA! POR FAVOR, TENTE NOVAMENTE.\n";
                break;
        }
    }
}

int main()
{
    std::cout << std::setfill('-') << std::setw(30) << "\n";
    std::cout << std::setfill('-') << std::setw(27) << "JOGO DA VELHA" << std::setfill('-')
    << std::setw(3) << '\n';
    std::cout << std::setfill('-') << std::setw(30) << "\n";

    TicTacToe game;

    beginGame(game);

    return 0;
}
