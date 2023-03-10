#include "Bishop.h"
#include "../Board.h"
#include "../Cell.h"
#include "../Utils.h"

Bishop::Bishop(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TBishop;
}


std::vector<int> Bishop::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    auto [cur_x, cur_y] = Utils::to_coord(cur_cell);
    std::vector<int> candidates;

    // North-West diagonal
    int x = cur_x - 1, y = cur_y - 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x--, y--));
    }

    // North-East diagonal
    x = cur_x + 1, y = cur_y - 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x++, y--));
    }

    // South-West diagonal
    x = cur_x - 1, y = cur_y + 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x--, y++));
    }

    // South-East diagonal
    x = cur_x + 1, y = cur_y + 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x++, y++));
    }

    pruneCandidates(&candidates);

    return candidates;
}
