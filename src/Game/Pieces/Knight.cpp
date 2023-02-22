#include "Knight.h"

Knight::Knight(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) { }

Knight::~Knight() : ~BasePiece() { }

bool Knight::checkMove(int new_pos) {

}

bool Knight::move(int new_pos) {
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


std::vector<int> *Knight::possibleMoves() {

}

