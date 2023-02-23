#include "Bishop.h"
#include "../Board.h"
#include "../Cell.h"

Bishop::Bishop(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TBishop;
}

bool Bishop::checkMove(int new_pos) {
    return true;
}

bool Bishop::move(int new_pos) {
    if (checkMove(new_pos)) {
        Cell *next_cell = m_board->getCell(new_pos);
        if (next_cell->getState() == Busy && next_cell->getPiece()->getColor() == m_color)
            return false;

        m_cell->setState(Free);
        m_cell = next_cell;
        m_cell->setState((BasePiece*)this);

        return true;
    }

    else
        return false;
}


std::vector<int> *Bishop::possibleMoves() {
    return 0;
}

