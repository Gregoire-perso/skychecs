#ifndef UTILS_H
#define UTILS_H
#include "Board.h"
#include <exception>

namespace Utils
{

int to_raw(int x, int y);
std::pair<int, int> to_coord(int raw);
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


