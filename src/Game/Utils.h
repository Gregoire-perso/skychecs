#ifndef UTILS_H
#define UTILS_H
#include "Board.h"

namespace Utils
{

int to_raw(int x, int y) {
    return y * Board::boardSize + x;
}

std::pair<int, int> to_coord(int raw) {
    return { raw % Board::boardSize, raw / Board::boardSize };
}

}

#endif


