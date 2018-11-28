#define _USE_MATH_DEFINES //allows the use of the pi constant although not best practice
#include <cmath>
#include <iostream>
#include <iomanip>
#include "DUO-Maths.h"

double DUO::deg2Rad( double value ) {return value * ( M_PI / 180.0 );}; //converts a value in degrees to radians by multiplying by (pi / 180) and returning the value as a double

double DUO::vector2::getMagnitude() {return std::sqrt( std::pow( x, 2 ) + std::pow( y, 2 ) );} //returns the magnitude of the vector2 using the pythagorean theorem using the vector2's components

double DUO::vector2::getXComponent() {return x;}; // returns the vector2's x component

double DUO::vector2::getYComponent() {return y;}; // returns the vector2's y component

void DUO::vector2::setXComponent(double newX) {x = newX;}; //sets the x component to a new value

void DUO::vector2::setYComponent(double newY) {y = newY;}; //sets the y component to a new value

void DUO::vector2::rotateVector(double rotation) {

    double prevX = x; //store;s the current x value in a variable to be used in calculations
    double prevY = y; //store's the current y value in a variable to be used in calculations

    double rotationRads = deg2Rad(rotation); //converts the rotation angle to radians

    x = (prevX * std::cos(rotationRads) - prevY * std::sin(rotationRads)); //rotates the vector2 by applying a rotation matrix

    y = (prevX * std::sin(rotationRads) + prevY * std::cos(rotationRads));

};

void DUO::vector2::print() { 

    std::cout << getXComponent() << ", " << getYComponent() << std::endl; //prints the components of the vector2

};

DUO::vector2 DUO::addVector(DUO::vector2 v1, DUO::vector2 v2) {

    double xComp = v1.getXComponent() + v2.getXComponent(); // calculates the x component of the new vector2
    double yComp = v1.getYComponent() + v2.getYComponent(); // calculates the y component of the new vector2

    return vector2(xComp, yComp); // returns a vector2 with the new components

};

DUO::vector2 DUO::vector2::operator+(vector2& vect2) {return DUO::vector2(this->getXComponent() + vect2.getXComponent(), this->getYComponent() + vect2.getYComponent());}

DUO::vector2 DUO::vector2::operator-(vector2& vect2) {return DUO::vector2(this->getXComponent() - vect2.getXComponent(), this->getYComponent() - vect2.getYComponent());}

double DUO::vector2::dot(vector2& vect) {return (this->getXComponent() * vect.getXComponent()) + (this->getYComponent() * vect.getYComponent());}

void DUO::vector2::increment(double xInc, double yInc) {

    x += xInc; //increments the vectors components by the values passed as arguments
    y += yInc;

}

DUO::vector2 DUO::vector2::operator*(double multiple) {return DUO::vector2(this->getXComponent() * multiple, this->getYComponent() * multiple);}

void DUO::vector2::setVector(double xInc, double yInc) {

    x = xInc;
    y = yInc;

}