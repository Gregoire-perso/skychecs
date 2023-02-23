#include "Board.h"

Board::Board() {
    PieceType firstLine[] = { TRook, TKnight, TBishop, TQueen, TKing, TBishop, TKnight, TRook };
    
    int i;
    
    // Init black lines
    for(i = 0; i < m_boardSize; i++) {
        m_board[i] = new Cell(this, i, firstLine[i], Black);
    }

    for(; i < 2 * m_boardSize; i++) {
        m_board[i] = new Cell(this, i, TPawn, Black);
    }

    // Init empty lines
    for(; i < (m_boardSize - 2) * m_boardSize; i++) {
        m_board[i] = new Cell(this, i);
    }

    // Init white lines
    for(; i < (m_boardSize - 1) * m_boardSize; i++) {
        m_board[i] = new Cell(this, i, TPawn, White);
    }

    for(; i < m_boardSize * m_boardSize; i++) {
        m_board[i] = new Cell(this, i, firstLine[-(i - 63)], White);
    }
}

Cell *Board::getCell(int position) {
    return m_board[position];
}

bool Board::moveCell(int before, int after) {
    if (m_board[before]->getState() != Busy)
        return false;

    else
        return m_board[before]->getPiece()->move(after);
}

bool Board::hasWon(PlayerColor color) {
    PlayerColor other = color == White ? Black : White;
    for (Cell *cell : m_board) {
        if (cell->getPiece()->getColor() == other) {
            if (cell->getPiece()->type == TKing)
                if (cell->getPiece()->possibleMoves()->empty())
                    return true;

            return false;
        }
    }

    return true;
}

void Board::printBoard() {
    for (int i = 0; i < m_boardSize; i++) {
        for (int j = 0; j < m_boardSize; j++)
            std::cout << "|---";

        std::cout << "|" << std::endl;

        for (int j = 0; j < m_boardSize; j++) {
            if (m_board[i * m_boardSize + j]->getPiece() == NULL)
                std::cout << "|   ";

            else
                std::cout << "| " << m_board[i * m_boardSize + j]->getPiece()->type
                    << " ";
        }

        std::cout << "|" << std::endl;
    }

    for (int j = 0; j < m_boardSize; j++)
        std::cout << "|---";

    std::cout << "|" << std::endl;
}
