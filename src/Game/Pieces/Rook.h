#ifndef ROOK_H
#define ROOK_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Rook : public BasePiece {
public:
    Rook(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> possibleMoves();
};

#endif


