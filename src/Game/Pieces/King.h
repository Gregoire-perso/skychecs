#ifndef KING_H
#define KING_H
#include "BasePieces.h"
#include "Board.h"
#include "Cell.h"

class King: public BasePieces
{
private:
    bool checkMove(int new_pos);

public:
    King(int position, PlayerColor color) : BasePieces(position, color) {};
    Cell getCell();
    bool move(int new_pos);
    int *possibleMoves();
}

#endif


