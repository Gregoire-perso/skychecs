#include "King.h"
#include "../Board.h"
#include "../Cell.h"

King::King(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TKing;
}


std::vector<int> King::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int cur_x = cur_cell % Board::boardSize;
    int cur_y = cur_cell / Board::boardSize;
    std::vector<int> candidates;

    // Add in board candidates
    if (cur_y - 1 >= 0) {
        candidates.push_back((cur_y - 1) * Baord::boardSize + cur_x);

        if (cur_x - 1 >= 0)
            candidates.push_back((cur_y - 1) * Baord::boardSize + cur_x - 1);

        if (cur_x + 1 < Board::boardSize)
            candidates.push_back((cur_y - 1) * Baord::boardSize + cur_x + 1);
    }

    if (cur_y + 1 < Baord::boardSize) {
        candidates.push_back((cur_y + 1) * Baord::boardSize + cur_x);

        if (cur_x - 1 >= 0)
            candidates.push_back((cur_y + 1) * Baord::boardSize + cur_x - 1);

        if (cur_x + 1 < Board::boardSize)
            candidates.push_back((cur_y + 1) * Baord::boardSize + cur_x + 1);
    }

    if (cur_x - 1 >= 0)
        candidates.push_back(cur_y * Baord::boardSize + cur_x - 1);

    if (cur_x + 1 < Board::boardSize)
        candidates.push_back(cur_y * Baord::boardSize + cur_x + 1);


    // Check if the candidates cells are busy or not
    for (std::vector<int>::iterator it = candidates.begin(), int i = 0;
            it != candidates.end(); ++it, i++) {
        Cell *cell = m_board->getCell(it);
        if (cell->getState() == Busy && cell->getPiece()->getColor() == m_color)
            candidates.erase(i);
    }

    for (int i = 0; i < Board::boardSize * Board::boardSize; i++) {
        Cell *cell = m_board->getCell(i);
        if (cell->getState() != Busy)
            continue;

        if (cell->getPiece()->getColor() == m_color)
            continue;

        for (int j : cell->getPiece()->possibleMoves()) {
            for (std::vector<int>::iterator it = candidates.begin(), int l = 0;
                it != candidates.end(); ++it, l++) {
                if (j == it)
                    candidates.erase(l)
            }
        }
    }

    return candidates;
}
