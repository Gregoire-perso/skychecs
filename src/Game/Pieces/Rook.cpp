#include "Rook.h"
#include "../Board.h"
#include "../Cell.h"

Rook::Rook(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TRook;
}

bool Rook::checkMove(int new_pos) {
    return true;
}


std::vector<int> *Rook::possibleMoves() {
    return 0;
}

