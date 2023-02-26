#ifndef PAWN_H
#define PAWN_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"
#include "Queen.h"

class Pawn : public BasePiece {
private:
    void m_promoteQueen();
    bool m_firstMove = true;

public:
    Pawn(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos) override;
    std::vector<int> possibleMoves();
};

#endif


