#include "Board.h"

Board::Board() {
    PieceType firstLine[] = { TRook, TKnight, TBishop, TQueen, TKing, TBishop, TKnight, TRook };
    
    int i;
    
    // Init black lines
    for(i = 0; i < boardSize; i++) {
        m_board[i] = new Cell(this, i, firstLine[i], Black);
    }

    for(; i < 2 * boardSize; i++) {
        m_board[i] = new Cell(this, i, TPawn, Black);
    }

    // Init empty lines
    for(; i < (boardSize - 2) * boardSize; i++) {
        m_board[i] = new Cell(this, i);
    }

    // Init white lines
    for(; i < (boardSize - 1) * boardSize; i++) {
        m_board[i] = new Cell(this, i, TPawn, White);
    }

    for(; i < boardSize * boardSize; i++) {
        m_board[i] = new Cell(this, i, firstLine[-(i - 63)], White);
    }
}

Cell *Board::getCell(int position) {
    return m_board[position];
}

bool Board::movePiece(int before, int after) {
    if (m_board[before]->getState() != Busy)
        return false;

    else
        return m_board[before]->getPiece()->move(after);
}

bool Board::hasWon(PlayerColor color) {
    PlayerColor other = color == White ? Black : White;
    for (Cell *cell : m_board) {
        if (cell->getPiece()->getColor() == other) {
            if (cell->getPiece()->getType() == TKing)
                if (cell->getPiece()->possibleMoves().empty())
                    return true;

            return false;
        }
    }

    return true;
}

void Board::printBoard() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++)
            std::cout << "|---";

        std::cout << "|" << std::endl;

        for (int j = 0; j < boardSize; j++) {
            if (m_board[i * boardSize + j]->getPiece() == NULL)
                std::cout << "|   ";

            else
                std::cout << "| " << m_board[i * boardSize + j]->getPiece()->getType()
                    << " ";
        }

        std::cout << "|" << std::endl;
    }

    for (int j = 0; j < boardSize; j++)
        std::cout << "|---";

    std::cout << "|" << std::endl;
}
