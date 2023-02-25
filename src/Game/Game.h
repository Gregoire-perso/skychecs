#ifndef GAME_H
#define GAME_H
#include "Enums.h"
#include <string>

class Game {
private:
    int m_turnNumber;
    PlayerColor m_currentPlayer;
    PlayerColor m_winner;
    Board *m_board;

public:
    Game();
    Game(int number);
    void save();
    bool move(int before, int after);
};


#endif


