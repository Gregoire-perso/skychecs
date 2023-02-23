#ifndef ROOK_H
#define ROOK_H
#include <vector>
#include "BasePiece.h"
#include "../Enums.h"

class Rook : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_cell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    Rook(Cell *cell, Board *board, PlayerColor color);
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = TRook;
};

#endif


