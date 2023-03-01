#ifndef UTILS_H
#define UTILS_H
#include "Board.h"
#include <exception>

namespace Utils
{

inline int to_raw(int x, int y) {
    return y * Board::boardSize + x;
}

inline std::pair<int, int> to_coord(int raw) {
    return { raw % Board::boardSize, raw / Board::boardSize };
}

void print_vector(std::vector<int>);

class ImpossibleMove : public std::exception {
private:
    char *m_msg;

public:
    ImpossibleMove();
    ImpossibleMove(char *message);
    const char *what() { return m_msg; };
};

}

#endif


