#ifndef BOARD_H
#define BOARD_H
#include "Enums.h"
#include "Cell.h"
#include <iostream>
#include <string>


class Cell;

class Board {
public:
    static const int boardSize = 8;
    Board();
    Board(string filename);
    Cell *getCell(int position);
    // Return true is the move is done succesfully
    // Check if the move is illegal (outside the bound, not possible with this
    // piece, ...)
    bool movePiece(int before, int after);
    bool hasWon(PlayerColor color);
    void printBoard();
    bool serialize(string filename);

private:

    Cell *m_board[boardSize * boardSize];
};

#endif
