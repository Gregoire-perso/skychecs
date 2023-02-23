#include "Knight.h"
#include "../Board.h"
#include "../Cell.h"

Knight::Knight(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TKnight;
}


std::vector<int> *Knight::possibleMoves() {
    return 0;
}
