#include "DUO-Utils.h"
#include <ctime>

DUO::timer::timer() {

    start = clock();

};

short DUO::timer::getElapsedTime() {return static_cast<short>(clock() - start);};