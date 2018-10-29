#define _USE_MATH_DEFINES //allows the use of the pi constant although not best practice
#include <cmath>
#include <iostream>
#include <iomanip>
#include "DUO-Maths.h"

double DUO::deg2Rad( double value ) {return value * ( M_PI / 180.0 );}; //converts a value in degrees to radians by multiplying by (pi / 180) and returning the value as a double

double DUO::vector::getMagnitude() {return std::sqrt( std::pow( x, 2 ) + std::pow( y, 2 ) );} //returns the magnitude of the vector using the pythagorean theorem using the vector's components

double DUO::vector::getXComponent() {return x;}; // returns the vector's x component

double DUO::vector::getYComponent() {return y;}; // returns the vector's y component

void DUO::vector::setXComponent(double newX) {x = newX;}; //sets the x component to a new value

void DUO::vector::setYComponent(double newY) {y = newY;}; //sets the y component to a new value

void DUO::vector::rotateVector(double rotation) {

    double prevX = x; //store;s the current x value in a variable to be used in calculations
    double prevY = y; //store's the current y value in a variable to be used in calculations

    double rotationRads = deg2Rad(rotation); //converts the rotation angle to radians

    x = (prevX * std::cos(rotationRads) - prevY * std::sin(rotationRads)); //rotates the vector by applying a rotation matrix

    y = (prevX * std::sin(rotationRads) + prevY * std::cos(rotationRads));

};

void DUO::vector::print() { 

    std::cout << getXComponent() << ", " << getYComponent() << std::endl; //prints the components of the vector

};

DUO::vector DUO::addVector(DUO::vector v1, DUO::vector v2) {

    double xComp = v1.getXComponent() + v2.getXComponent(); // calculates the x component of the new vector
    double yComp = v1.getYComponent() + v2.getYComponent(); // calculates the y component of the new vector

    return vector(xComp, yComp); // returns a vector with the new components

};

void DUO::vector::increment(double xInc, double yInc) {

    x += xInc; //increments the vectors components by the values passed as arguments
    y += yInc;

}