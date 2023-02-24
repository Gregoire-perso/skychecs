#include "Pawn.h"
#include "../Board.h"
#include "../Cell.h"
#include "../Utils.h"

Pawn::Pawn(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TPawn;
}

void Pawn::promoteQueen() {

}

bool Pawn::move(int new_pos) {
    if (BasePiece::move(new_pos)) {
        int cur_pos = m_cell->getPosition();
        int cur_y = cur_cell / Board::boardSize;

        if (cur_y == 0 || cur_y == Board::boardSize)
            promoteQueen();

        return true;
    }
    
    else
        return false;
}

std::vector<int> Pawn::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int [cur_x, cur_y] = Utils::to_coord(cur_cell);
    std::vector<int> candidates;

    int step;
    if (m_color == Black)
        step = 1;

    else
        step = -1;

    if (cur_y + step < 0 || cur_y + step > Board::boardSize) {
        // Test the cell in front of the pawn
        Cell *cell = m_board->getCell((cur_y + step) * Board::boardSize + cur_x);
        candidates.push_back(Utils::to_raw(cur_x, cur_y + step));

        // Test the cell in diagonal
        if (cur_x - 1 >= 0) {
            *cell = m_board->getCell((cur_y + step) * Board::boardSize + cur_x - 1);
            if (cell->getState() == Busy && cell->getPiece()->getColor() != m_color)
                candidates.push_back(Utils::to_raw(cur_x - 1, cur_y + step));
        }

        if (cur_x + 1 < Board::boardSize) {
            *cell = m_board->getCell((cur_y + step) * Board::boardSize + cur_x + 1);
            if (cell->getState() == Busy && cell->getPiece()->getColor() != m_color)
                candidates.push_back(Utils::to_raw(cur_x + 1, cur_y + step));
        }
    }

    pruneCandidates(&candidates);

    return candidates;
}
