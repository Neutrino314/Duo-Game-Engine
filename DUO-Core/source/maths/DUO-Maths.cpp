#define _USE_MATH_DEFINES //allows the use of the pi constant although not best practice
#include <cmath>
#include <iostream>
#include <iomanip>
#include "DUO-Maths.h"

double DUO::deg2Rad( double value ) {return value * ( M_PI / 180.0 );}; //converts a value in degrees to radians by multiplying by (pi / 180) and returning the value as a double

