#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Queen : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_cell;
    PlayerColor m_color;

public:
    Queen(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> possibleMoves();
    const PieceType type = TQueen;
};

#endif


