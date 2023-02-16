#include "Board.h"
#include "Cell.h"
#include "BasePiece.h"

using namespace Cell;

Board::Board() {
    for(int i = 0; i < m_boardSize * m_boardSize; i++) {
        m_board[i] = { i };
    }

    // Init pieces too
}

Cell& Board::getCell(int position) {
    return m_board[position];
}

bool Board::moveCell(int before, int after) {
    if (m_board[position].state != Busy) {
        return false;

    else
        return m_board[before].piece.move(after);
}

bool Board::hasWon(ColorPlayer color) {
    ColorPlayer other = color == White ? Black : White;
    for (Cell cell : m_board) {
        if (cell.piece.getColor() == other) {
            if (cell.piece.type == King) {
                if (cell.piece.possibleMove().size == 0)
                    return true;

            return false;
        }
    }

    return true;
}
