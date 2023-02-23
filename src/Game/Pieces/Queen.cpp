#include "Queen.h"
#include "../Board.h"
#include "../Cell.h"

Queen::Queen(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TQueen;
}

bool Queen::checkMove(int new_pos) {
    return true;
}


std::vector<int> *Queen::possibleMoves() {
    return 0;
}

