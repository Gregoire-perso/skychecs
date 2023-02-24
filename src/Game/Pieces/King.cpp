#include "King.h"
#include "../Board.h"
#include "../Cell.h"
#include "../Utils.h"

King::King(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TKing;
}


std::vector<int> King::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int [cur_x, cur_y] = Utils::to_coord(cur_cell);
    std::vector<int> candidates;

    // Add in-board candidates
    if (cur_y - 1 >= 0) {
        candidates.push_back(Utils::to_raw(cur_x, cur_y - 1));

        if (cur_x - 1 >= 0)
            candidates.push_back(Utils::to_raw(cur_x - 1, cur_y - 1));

        if (cur_x + 1 < Board::boardSize)
            candidates.push_back(Utils::to_raw(cur_x + 1, cur_y - 1));
    }

    if (cur_y + 1 < Baord::boardSize) {
        candidates.push_back(Utils::to_raw(cur_x, cur_y + 1));

        if (cur_x - 1 >= 0)
            candidates.push_back(Utils::to_raw(cur_x - 1, cur_y + 1));

        if (cur_x + 1 < Board::boardSize)
            candidates.push_back(Utils::to_raw(cur_x + 1, cur_y + 1));
    }

    if (cur_x - 1 >= 0)
        candidates.push_back(Utils::to_raw(cur_x - 1, cur_y));

    if (cur_x + 1 < Board::boardSize)
        candidates.push_back(Utils::to_raw(cur_x + 1, cur_y));

    pruneCandidates(&candidates);

    // Check if the remaining candidates are in danger for the king (e.g. an
    // enemy piece can ate the king in the next position)
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
