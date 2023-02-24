#include "BasePiece.h"
#include "../Cell.h"

BasePiece::BasePiece(Cell *cell, Board *board, PlayerColor color) {
    m_cell = cell;
    m_board = board;
    m_color = color;
}

BasePiece::~BasePiece() {
    m_cell->setState(Free);
}

/*
 * Check if the King can move in to the next position
 * This function check if the given position is in its possible positions
 */
bool BasePiece::checkMove(int new_pos) {
    for (int i : possibleMoves())
        if (i == new_pos)
            return true;

    return false;
}


bool BasePiece::move(int new_pos) {
    if (checkMove(new_pos)) {
        Cell *next_cell = m_board->getCell(new_pos);

        m_cell->setState(Free);
        m_cell = next_cell;
        m_cell->setState((BasePiece*)this);

        return true;
    }

    else
        return false;
}
