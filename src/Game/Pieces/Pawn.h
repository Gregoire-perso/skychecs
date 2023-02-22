#ifndef KING_H
#define KING_H
#include <vector>
#include "Cell.h"
#include "Board.h"

class Pawn : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_currentCell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    Pawn(Cell *cell, Board *board, PlayerColor color);
    ~Pawn();
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = Pawn;
}

#endif


