#include "Rook.h"
#include "../Board.h"
#include "../Cell.h"

Rook::Rook(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TRook;
}


std::vector<int> Rook::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int cur_x = cur_cell % Board::boardSize;
    int cur_y = cur_cell / Board::boardSize;
    std::vector<int> candidates;

}
