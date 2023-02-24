#ifndef BOARD_H
#define BOARD_H
#include "Enums.h"
#include "Cell.h"
#include <iostream>


class Cell;

class Board {
private:
    Cell *m_board[boardSize * boardSize];

public:
    static const int boardSize = 8;
    Board();
    Cell *getCell(int position);
    // Return true is the move is done succesfully
    // Check if the move is illegal (outside the bound, not possible with this
    // piece, ...)
    bool moveCell(int before, int after);
    bool hasWon(PlayerColor color);
    void printBoard();
};

#endif
