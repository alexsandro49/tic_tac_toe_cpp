#include <iostream>
#include <iomanip>
#include <ctime>
#include "tic_tac_toe.h"

void beginGame(TicTacToe game) {
    srand(time(0));
    int start = rand() % 2;
    game.show();
    while (true) {
        (start == 0) ? game.play() : game.computerPlay();
        game.show();
        if (game.endGame) {
            break;
        }
        (start == 1) ? game.play() : game.computerPlay();
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
