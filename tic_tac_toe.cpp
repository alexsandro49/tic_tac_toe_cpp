#include <iostream>
#include <ctime>
#include "tic_tac_toe.h"


void TicTacToe::drawLine(char i, char j, char k, int z, bool floor = false) {
    std::cout << "     |     |     \n";
    colorChar(i, 0+3*z);
    std::cout << i << "\033[0m" << "  |";
    colorChar(j, 1+3*z);
    std::cout << j << "\033[0m" << "  |";
    colorChar(k, 2+3*z);
    std::cout << k << "\033[0m" << '\n';
    floor ? std::cout << "_____|_____|_____\n" : std::cout << "     |     |     \n";
}

void TicTacToe::colorChar(char color, int pos) {
    if (endGame) {
        if (winnerPlay[pos] == 1) { 
            std::cout << "  " << "\033[1;33m"; return; 
        }
    }
    if (color == 'X') { std::cout << "  " << "\033[1;34m"; } 
    else if (color == 'O') { std::cout << "  " << "\033[1;31m"; }
    else { std::cout << "  "; }
}

void TicTacToe::show() {
    std::cout << '\n';
    drawLine(possibles[0], possibles[1], possibles[2], 0, true);
    drawLine(possibles[3], possibles[4], possibles[5], 1, true);
    drawLine(possibles[6], possibles[7], possibles[8], 2);
    std::cout << "\n-----------------\n";
}

void TicTacToe::play() {
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

bool TicTacToe::verifyEndGame() {
    auto winnerMarks = [&](int a, int b, int c) {
        winnerPlay[a]++;
        winnerPlay[b]++;
        winnerPlay[c]++;
    };

    int counter = 0;
    for (int i = 0; i < 9; i++) {
        if (possibles[i] == 'X' || possibles[i] == 'O') {
            counter++;
        }
    }
    if (counter == 9) {
        ties++; return true;
    }

    int x[3][9] = { {0, 1, 2, 3, 4, 5, 6, 7, 8}, {0, 3, 6, 1, 4, 7, 2, 5, 8}, {0, 4, 8, 2, 4, 6} };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2 && j == 2) {
                break;
            }
            
            if ((possibles[x[i][0+3*j]] == 'X' && possibles[x[i][1+3*j]] == 'X' && possibles[x[i][2+3*j]] == 'X') || (possibles[x[i][0+3*j]] == 'O' && possibles[x[i][1+3*j]] == 'O' && possibles[x[i][2+3*j]] == 'O')) {
                (possibles[0] == 'X') ? playerWins++ : computerWins++; 
                winnerMarks(x[i][0+3*j], x[i][1+3*j], x[i][2+3*j]);
                return true;
            }
        }     
    }
    return false;
}

void TicTacToe::computerPlay() {
    bool ok = false;
    int computerPlay;

    srand(time(0));

    for (int i = 0; i < 2; i++) {
        if ((possibles[i] != 'X' && possibles[i] != 'O') && possibles[4] == 'X' && possibles[8-2*i] == 'X') {
            computerPlay = 0+2*i; ok = true; break;
        } else if (possibles[i] == 'X' && (possibles[4] != 'X' && possibles[4] != 'O') && possibles[8-2*i] == 'X') {
            computerPlay = 4; ok = true; break;
        } else if (possibles[i] == 'X' && possibles[4] == 'X' && (possibles[8-2*i] != 'X' && possibles[8-2*i] != 'O')) {
            computerPlay = 8-2*i; ok = true; break;
        }
    }

    if (!ok) {
        for (int i = 0; i < 3; i++) {
            if ((possibles[0+3*i] != 'X' && possibles[0+3*i] != 'O') && possibles[1+3*i] == 'X' && possibles[2+3*i] == 'X') {
                computerPlay = 0+3*i; ok = true; break;
            } else if (possibles[0+3*i] == 'X' && (possibles[1+3*i] != 'X' && possibles[1+3*i] != 'O') && possibles[2+3*i] == 'X') {
                computerPlay = 1+3*i; ok = true; break;
            } else if (possibles[0+3*i] == 'X' && possibles[1+3*i] == 'X' && (possibles[2+3*i] != 'X' && possibles[2+3*i] != 'O')) {
                computerPlay = 2+3*i; ok = true; break;
            }
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

void TicTacToe::restart() {
    for (int i = 49; i<58; i++) {
        if (i < 58) {
            winnerPlay[i-49] = 0;
        }
        possibles[i-49] = static_cast<char>(i);
    }
    endGame = false;
}
