#ifndef DUO_UTILS
#define DUO_UTILS

#include <ctime>
#include <string>

namespace DUO {

class timer {

private:

    std::clock_t start;

public:

    timer();

    short getElapsedTime();

};

enum broadType {BASE, RENDERER, TRANSFORM, PHYSICS, USERDEFINED, UI};

struct compType {

    std::string name;

};

};

#endif