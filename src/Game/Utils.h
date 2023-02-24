#ifndef UTILS_H
#define UTILS_H
#include "Board.h"

namespace Utils
{

int to_raw(int x, int y);

std::pair<int, int> to_coord(int raw);

}

#endif


