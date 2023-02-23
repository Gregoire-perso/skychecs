#include "Bishop.h"
#include "../Board.h"
#include "../Cell.h"

Bishop::Bishop(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TBishop;
}


std::vector<int> *Bishop::possibleMoves() {
    return 0;
}
