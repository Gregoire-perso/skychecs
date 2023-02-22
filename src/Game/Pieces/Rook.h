#ifndef KING_H
#define KING_H
#include <vector>
#include "Cell.h"
#include "Board.h"

class Rook : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_currentCell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    Rook(Cell *cell, Board *board, PlayerColor color);
    ~Rook();
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = Rook;
}

#endif


