#include "BasePiece.h"

BasePiece::BasePiece(Cell *cell, Board *board, PlayerColor color) {
    m_currentCell = cell;
    m_board = board;
    m_color = color;
}

BasePiece::~BasePiece() {
    m_currentCell->setState(Free);
}
