#ifndef CELL_H
#define CELL_H
#include "BasePiece.h"
#include "Board.h"

// Free and Busy states are obvious
enum CellState { Free, Busy };

class Cell {
private:
    int m_position;
    Board m_board;

public: 
    Cell(int position);
    Cell(int position, PieceType type);
    int getPosition();
    CellState state;
    BasePiece piece;
}

#endif
