#ifndef BISHOP_H
#define BISHOP_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Bishop : public BasePiece {
public:
    Bishop(Cell *cell, Board *board, PlayerColor color);
    std::vector<int> possibleMoves();
};

#endif


