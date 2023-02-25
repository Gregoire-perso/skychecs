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
    if (position < 0 || position >= boardSize * boardSize)
        return NULL;

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
    // Print the letters
    std::cout << "   ";
    for (int j = 0; j < boardSize; j++)
        std::cout << "| " << j << " ";

    std::cout << "|" << std::endl;

    for (int i = 0; i < boardSize; i++) {
        // Print the upper line
        // Print the space for the numbers
        std::cout << "---";
        for (int j = 0; j < boardSize; j++)
            std::cout << "|---";

        std::cout << "|" << std::endl;

        printf("%02d ", i * 8);

        for (int j = 0; j < boardSize; j++) {
            if (m_board[i * boardSize + j]->getPiece() == NULL)
                std::cout << "|   ";

            else
                std::cout << "| " << m_board[i * boardSize + j]->getPiece()->getType()
                    << " ";
        }

        std::cout << "|" << std::endl;
    }

    std::cout << "---";
    for (int j = 0; j < boardSize; j++)
        std::cout << "|---";

    std::cout << "|" << std::endl;
}
