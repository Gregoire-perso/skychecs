#ifndef ROOK_H
#define ROOK_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Rook : public BasePiece {
public:
    Rook(Cell *cell, Board *board, PlayerColor color);
    std::vector<int> possibleMoves();
};

#endif


