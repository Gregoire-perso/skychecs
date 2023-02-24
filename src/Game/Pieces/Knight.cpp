#include "Knight.h"
#include "../Board.h"
#include "../Cell.h"
#include "../Utils.h"

Knight::Knight(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TKnight;
}


std::vector<int> Knight::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int [cur_x, cur_y] = Utils::to_coord(cur_cell);
    std::vector<int> candidates;

    if (cu_y - 2 >= 0) {
        if (cur_x - 1 >= 0)
            candidates.push_back(Utils::to_raw(cur_x - 1, cur_y - 2));

        if (cur_x + 1 < Baord::boardSize)
            candidates.push_back(Utils::to_raw(cur_x + 1, cur_y - 2));
    }

    if (cu_y - 1 >= 0) {
        if (cur_x - 2 >= 0)
            candidates.push_back(Utils::to_raw(cur_x - 2, cur_y - 1));

        if (cur_x + 2 < Baord::boardSize)
            candidates.push_back(Utils::to_raw(cur_x + 2, cur_y - 1));
    }

    if (cu_y + 1 < Board::boardSize) {
        if (cur_x - 2 >= 0)
            candidates.push_back(Utils::to_raw(cur_x - 2, cur_y + 1));

        if (cur_x + 2 < Baord::boardSize)
            candidates.push_back(Utils::to_raw(cur_x + 2, cur_y + 1));
    }

    if (cu_y + 2 < Board::boardSize) {
        if (cur_x - 1 >= 0)
            candidates.push_back(Utils::to_raw(cur_x - 1, cur_y + 2));

        if (cur_x + 1 < Baord::boardSize)
            candidates.push_back(Utils::to_raw(cur_x + 1, cur_y + 2));
    }

    pruneCandidates(&candidates);

    return candidates;
}
