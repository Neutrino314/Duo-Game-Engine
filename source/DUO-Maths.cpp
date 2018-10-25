#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include "DUO-Maths.h"

double DUO::deg2Rad( double value ) {return value * ( M_PI / 180.0 );};

double DUO::vector::getMagnitude() {return std::sqrt( std::pow( x, 2 ) + std::pow( y, 2 ) );}

double DUO::vector::getXComponent() {return x;};

double DUO::vector::getYComponent() {return y;};

void DUO::vector::setXComponent(double newX) {x = newX;};

void DUO::vector::setYComponent(double newY) {y = newY;};

void DUO::vector::rotateVector(double rotation) {

    double prevX = x;
    double prevY = y;

    double rotationRads = deg2Rad(rotation);

    x = (prevX * std::cos(rotationRads) - prevY * std::sin(rotationRads));

    y = (prevX * std::sin(rotationRads) + prevY * std::cos(rotationRads));

    //std::cout << x << ", " << y << "\n";

};

void DUO::vector::print() {

    std::cout << getXComponent() << ", " << getYComponent() << std::endl;

};

DUO::vector DUO::addVector(DUO::vector v1, DUO::vector v2) {

    double xComp = v1.getXComponent() + v2.getXComponent();
    double yComp = v1.getYComponent() + v2.getYComponent();

    return vector(xComp, yComp);

};