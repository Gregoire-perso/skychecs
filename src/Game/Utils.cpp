#include "Utils.h"
#include "Board.h"

namespace Utils
{

void print_vector(std::vector<int> v) {
    for (int i : v)
        std::cout << i << std::endl;
}

ImpossibleMove::ImpossibleMove() : m_msg("This movement is impossible") {}

ImpossibleMove::ImpossibleMove(char *message) : m_msg(message) {}

}
