#ifndef KING_H
#define KING_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class King : public BasePiece {
public:
    King(Cell *cell, Board *board, PlayerColor color);
    std::vector<int> possibleMoves();
};

#endif


