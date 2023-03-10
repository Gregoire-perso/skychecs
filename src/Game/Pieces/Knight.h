#ifndef KNIGHT_H
#define KNIGHT_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Knight : public BasePiece {
public:
    Knight(Cell *cell, Board *board, PlayerColor color);
    std::vector<int> possibleMoves();
};

#endif


