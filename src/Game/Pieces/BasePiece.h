#ifndef BASE_PIECES_H
#define BASE_PIECES_H
#include <vector>
#include "Cell.h"
#include "Board.h"

enum PieceType: char { King = 'K', Queen = 'Q', Bishop = 'B', 
                       Knight = 'k', Rook = 'R', Pawn = 'P' }

class BasePiece {
protected: 
    Board *m_board;
    Cell *m_currentCell;
    virtual bool checkMove(int new_pos);
    PlayerColor m_color;

public:
    virtual BasePiece(Cell *cell, Board *board, PlayerColor color);
    virtual ~BasePiece();
    Cell getCell() { return current_cell };
    virtual bool move(int new_pos);
    virtual std::vector<int> *possibleMoves();
    PlayerColor getColor() { return color };
    const PieceType type;
}

#endif


