#ifndef BOARD_H
#define BOARD_H
#include "Enums.h"
#include "Cell.h"
#include <iostream>


class Cell;

class Board {
private:
    static const int m_boardSize = 8;
    Cell *m_board[m_boardSize * m_boardSize];

public:
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
