#ifndef PAWN_H
#define PAWN_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Pawn : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_cell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    Pawn(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = TPawn;
};

#endif


