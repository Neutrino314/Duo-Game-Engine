#include "DUO-Vector2.h"
#include <cmath>
#include <iostream>

float DUO::vector2::getMagnitude() {return std::sqrt( std::pow( x, 2 ) + std::pow( y, 2 ) );} //returns the magnitude of the vector2 using the pythagorean theorem using the vector2's components

float DUO::vector2::getXComponent() {return x;}; // returns the vector2's x component

float DUO::vector2::getYComponent() {return y;}; // returns the vector2's y component

void DUO::vector2::setXComponent(float newX) {x = newX;}; //sets the x component to a new value

void DUO::vector2::setYComponent(float newY) {y = newY;}; //sets the y component to a new value

void DUO::vector2::rotateVector(float rotation) {

    float prevX = x; //store;s the current x value in a variable to be used in calculations
    float prevY = y; //store's the current y value in a variable to be used in calculations

    float rotationRads = deg2Rad(rotation); //converts the rotation angle to radians

    x = (prevX * std::cos(rotationRads) - prevY * std::sin(rotationRads)); //rotates the vector2 by applying a rotation matrix

    y = (prevX * std::sin(rotationRads) + prevY * std::cos(rotationRads));

};

void DUO::vector2::print() { 

    std::cout << getXComponent() << ", " << getYComponent() << std::endl; //prints the components of the vector2

};

DUO::vector2 DUO::addVector(DUO::vector2 v1, DUO::vector2 v2) {

    float xComp = v1.getXComponent() + v2.getXComponent(); // calculates the x component of the new vector2
    float yComp = v1.getYComponent() + v2.getYComponent(); // calculates the y component of the new vector2

    return vector2(xComp, yComp); // returns a vector2 with the new components

};

DUO::vector2 DUO::vector2::operator+(vector2& vect2) {return DUO::vector2(this->getXComponent() + vect2.getXComponent(), this->getYComponent() + vect2.getYComponent());}

DUO::vector2 DUO::vector2::operator-(vector2& vect2) {return DUO::vector2(this->getXComponent() - vect2.getXComponent(), this->getYComponent() - vect2.getYComponent());}

float DUO::vector2::dot(vector2& vect) {return (this->getXComponent() * vect.getXComponent()) + (this->getYComponent() * vect.getYComponent());}

void DUO::vector2::increment(float xInc, float yInc) {

    x += xInc; //increments the vectors components by the values passed as arguments
    y += yInc;

}

DUO::vector2 DUO::vector2::operator*(float multiple) {return DUO::vector2(this->getXComponent() * multiple, this->getYComponent() * multiple);}

void DUO::vector2::setVector(float xInc, float yInc) {

    x = xInc;
    y = yInc;

}

DUO::vector2 DUO::vector2::normal() {return DUO::vector2(y, -x);}