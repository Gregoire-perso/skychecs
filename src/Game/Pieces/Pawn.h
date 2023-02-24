#ifndef PAWN_H
#define PAWN_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Pawn : public BasePiece {
public:
    Pawn(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> possibleMoves();
};

#endif


