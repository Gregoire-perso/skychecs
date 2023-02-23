#ifndef BASE_PIECE_H
#define BASE_PIECE_H
#include <vector>
#include "../Enums.h"

class BasePiece {
protected: 
    PieceType m_type;
    Board *m_board;
    Cell *m_cell;
    virtual bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    BasePiece(Cell *cell, Board *board, PlayerColor color);
    virtual ~BasePiece();
    Cell *getCell() { return m_cell; };
    virtual bool move(int new_pos);
    virtual std::vector<int> *possibleMoves() = 0;
    PlayerColor getColor() { return m_color; };
    PieceType getType() { return m_type; };
};

#endif


