#ifndef BASE_PIECES_H
#define BASE_PIECES_H
#include "Cell.h"

class BasePieces {
protected: 
    int position;
    Cell current_cell;
    virtual bool checkMove(int new_pos);
    PlayerColor color;

public:
    virtual BasePieces(int position, PlayerColor color);
    Cell getCell() { return current_cell };
    virtual bool move(int new_pos);
    virtual int *possibleMoves();
    PlayerColor getColor() { return color };
}

#endif


