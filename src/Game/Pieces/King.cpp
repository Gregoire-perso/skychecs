#include "King.h"
#include "../Board.h"
#include "../Cell.h"

King::King(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TKing;
}


std::vector<int> *King::possibleMoves() {
    return 0;
}
