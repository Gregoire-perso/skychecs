#ifndef CELL_H
#define CELL_H
#include "BasePiece.h"

// Free and Busy states are obvious
enum CellState { Free, Busy, PossibleMove };

class Cell {
private:
    int position;

public: 
    Cell(int position);
    int getPosition();
    CellState state;
    BasePiece piece;
}

#endif
