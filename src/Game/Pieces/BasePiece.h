#ifndef BASE_PIECE_H
#define BASE_PIECE_H
#include <vector>
#include "../Enums.h"

class BasePiece {
protected: 
    Board *m_board;
    Cell *m_cell;
    virtual bool checkMove(int new_pos) = 0;
    PlayerColor m_color;

public:
    BasePiece(Cell *cell, Board *board, PlayerColor color);
    virtual ~BasePiece();
    Cell *getCell() { return m_cell; };
    virtual bool move(int new_pos) = 0;
    virtual std::vector<int> *possibleMoves() = 0;
    PlayerColor getColor() { return m_color; };
    const PieceType type = TKing;
};

#endif


