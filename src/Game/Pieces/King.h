#ifndef KING_H
#define KING_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class King : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_cell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    King(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = TKing;
};

#endif


