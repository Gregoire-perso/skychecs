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
