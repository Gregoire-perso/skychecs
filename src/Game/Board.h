#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"

enum PlayerColor { White, Black };

class Board {
private:
    int boardSize = 8;
    Cell board[BOARDSIZE*BOARDSIZE];

public:
    Board();
    Cell getCell(int position);
    // Return true is the move is done succesfully
    // Check if the move is illegal (outside the bound, not possible with this
    // piece, ...)
    bool moveCell(int before, int after);
    bool hasWon(PlayerColor color);
};

#endif