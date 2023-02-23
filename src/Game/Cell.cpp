#include "Cell.h"
#include <cstddef>

Cell::Cell(Board *board, int position) {
    m_board = board;
    m_position = position;
    m_state = Free;
    m_piece = NULL;
}

Cell::Cell(Board *board, int position, PieceType type, PlayerColor color) {
    m_board = board;
    m_position = position;
    m_state = Busy;
    switch(type) {
        default:
            // Throw error unknown type
            m_piece = new King(this, board, color);
            break;
    }
}

void Cell::setState(CellState state) {
    if (state == Free) {
        if (m_state == Busy)
            m_state = Free;

        m_piece = NULL;
    }

    else
        m_state = state;
}

void Cell::setState(BasePiece *piece) {
    if (m_state == Busy)
        delete m_piece;

    m_piece = piece;
}

