#include "Pawn.h"
#include "../Board.h"
#include "../Cell.h"

Pawn::Pawn(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TPawn;
}


std::vector<int> *Pawn::possibleMoves() {
    return 0;
}
