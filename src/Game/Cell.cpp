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
        case TKing:
            m_piece = new King(this, board, color);
            break;

        case TQueen:
            m_piece = new Queen(this, board, color);
            break;

        case TBishop:
            m_piece = new Bishop(this, board, color);
            break;

        case TKnight:
            m_piece = new Knight(this, board, color);
            break;

        case TRook:
            m_piece = new Rook(this, board, color);
            break;

        case TPawn:
            m_piece = new Pawn(this, board, color);
            break;

        default:
            // Throw error unknown type
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
    m_state = Busy;
}

