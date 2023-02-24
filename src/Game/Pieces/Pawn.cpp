#include "Pawn.h"
#include "../Board.h"
#include "../Cell.h"

Pawn::Pawn(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TPawn;
}


std::vector<int> Pawn::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int cur_x = cur_cell % Board::boardSize;
    int cur_y = cur_cell / Board::boardSize;
    std::vector<int> candidates;

}
