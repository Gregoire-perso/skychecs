#include "Cell.h"
#include "Board.h"
#include "BasePiece.h"

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
        case Pawn:
            m_piece = new Pawn(color);
            break;

        case Rook:
            m_piece = new Rook(color);
            break;

        case Knight:
            m_piece = new Knight(color);
            break;

        case Bishop:
            m_piece = new Bishop(color);
            break;

        case Queen:
            m_piece = new Queen(color);
            break;

        case King:
            m_piece = new King(color);
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
}

