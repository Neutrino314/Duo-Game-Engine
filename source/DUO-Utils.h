#ifndef DUO_UTILS
#define DUO_UTILS

#include <ctime>

namespace DUO {

class timer {

private:

    std::clock_t start;

public:

    timer();

    short getElapsedTime();

};

};

#endif