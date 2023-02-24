#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Queen : public BasePiece {
public:
    Queen(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> possibleMoves();
};

#endif


