#ifndef KING_H
#define KING_H
#include <vector>
#include "../Cell.h"
#include "../Board.h"

class King : public BasePiece {
protected: 
    Board *m_board;
    Cell *m_currentCell;
    bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    King(Cell *cell, Board *board, PlayerColor color);
    ~King();
    bool move(int new_pos);
    std::vector<int> *possibleMoves();
    const PieceType type = King;
}

#endif


