#include "Utils.h"
#include "Board.h"

namespace Utils
{

int to_raw(int x, int y) {
    return y * Board::boardSize + x;
}

std::pair<int, int> to_coord(int raw) {
    return { raw % Board::boardSize, raw / Board::boardSize };
}

void print_vector(std::vector<int> v) {
    for (int i : v)
        std::cout << i << std::endl;
}

ImpossibleMove::ImpossibleMove() : m_msg("This movement is impossible") {}

ImpossibleMove::ImpossibleMove(char *message) : m_msg(message) {}

}
