#ifndef KING_H
#define KING_H
#include <vector>
#include "Cell.h"
#include "Board.h"

class Bishop : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_currentCell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    Bishop(Cell *cell, Board *board, PlayerColor color);
    ~Bishop();
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = Bishop;
}

#endif


