#ifndef BASE_PIECES_H
#define BASE_PIECES_H
#include <vector>
#include "Cell.h"

enum PieceType { King, Queen, Bishop, Knight, Rook, Pawn }

class BasePieces {
protected: 
    int position;
    Cell current_cell;
    virtual bool checkMove(int new_pos);
    PlayerColor color;

public:
    virtual BasePieces(int position, PlayerColor color);
    Cell getCell() { return current_cell };
    virtual bool move(int new_pos);
    std::vector<int> possibleMoves();
    PlayerColor getColor() { return color };
    virtual const PieceType type;
}

#endif


