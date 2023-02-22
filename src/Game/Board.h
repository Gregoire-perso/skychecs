#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include "Pieces/BasePiece.h"

enum PlayerColor { White, Black };

class Board {
private:
    int m_boardSize = 8;
    Cell *m_board[boardSize * boardSize];

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
