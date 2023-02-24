#include "Queen.h"
#include "../Board.h"
#include "../Cell.h"

Queen::Queen(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TQueen;
}


std::vector<int> Queen::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int cur_x = cur_cell % Board::boardSize;
    int cur_y = cur_cell / Board::boardSize;
    std::vector<int> candidates;

}
