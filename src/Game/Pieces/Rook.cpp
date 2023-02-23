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

bool Rook::move(int new_pos) {
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


std::vector<int> *Rook::possibleMoves() {
    return 0;
}

