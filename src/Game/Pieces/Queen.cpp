#include "Queen.h"
#include "../Board.h"
#include "../Cell.h"

Queen::Queen(Cell *cell, Board *board, PlayerColor color) 
: BasePiece(cell, board, color) {
    m_type = TQueen;
}


std::vector<int> Queen::possibleMoves() {
    int cur_cell = m_cell->getPosition();
    int [cur_x, cur_y] = Utils::to_coord(cur_cell);
    std::vector<int> candidates;

    // North
    int x = cur_x, y = cur_y - 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x, y--));
    }

    // South
    int x = cur_x, y = cur_y + 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x, y++));
    }

    // East
    int x = cur_x + 1, y = cur_y;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x++, y));
    }

    // West
    int x = cur_x - 1, y = cur_y;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x--, y));
    }

    // North-West diagonal
    int x = cur_x - 1, y = cur_y - 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x--, y--));
    }

    // North-East diagonal
    int x = cur_x + 1, y = cur_y - 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x++, y--));
    }

    // South-West diagonal
    int x = cur_x - 1, y = cur_y + 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x--, y++));
    }

    // South-East diagonal
    int x = cur_x + 1, y = cur_y + 1;
    while (x >= 0 && x < Board::boardSize && 
           y >= 0 && y < Board::boardSize &&
           m_board->getCell(Utils::to_raw(x, y))->getState() != Busy) {
        candidates.push_back(Utils::to_raw(x++, y++));
    }

    pruneCandidates(&candidates);

    return candidates;
}
