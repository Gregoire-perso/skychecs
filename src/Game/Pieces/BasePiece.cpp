#include "BasePiece.h"
#include "../Board.h"
#include "../Cell.h"

BasePiece::BasePiece(Cell *cell, Board *board, PlayerColor color) {
    m_cell = cell;
    m_board = board;
    m_color = color;
}

BasePiece::~BasePiece() {
    m_cell->setState(Free);
}

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

// Remove candidates that point to a friendly busy cell
void BasePiece::pruneCandidates(std::vector<int> *candidates) {
    // Check if the candidates cells are busy or not
    for (std::vector<int>::iterator it = candidates->begin();
            it != candidates->end(); ++it) {
        Cell *cell = m_board->getCell(*it);
        if (cell->getState() == Busy && cell->getPiece()->getColor() == m_color)
            candidates->erase(it);
    }
}

