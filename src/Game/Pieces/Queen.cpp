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

bool Queen::move(int new_pos) {
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


std::vector<int> *Queen::possibleMoves() {
    return 0;
}

