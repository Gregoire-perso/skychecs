#include "Queen.h"

Queen::Queen(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) { }

Queen::~Queen() : ~BasePiece() { }

bool Queen::checkMove(int new_pos) {

}

bool Queen::move(int new_pos) {
    if (checkMove(new_pos)) {
        Cell *next_cell = m_board->getCell(new_pos);
        if (next_cell->getState() == Busy && next_cell->getPiece()->color == m_color)
            return false;

        m_cell->setState(Free);
        m_cell = next_cell;
        m_cell->setState(this)

        return true;
    }

    else
        return false;
}


std::vector<int> *Queen::possibleMoves() {

}

