#pragma once
#include "DUO-Maths.h"

namespace DUO {

    class vector2 {

    public:

        double x;
        double y;

        vector2(double x = 0.0, double y = 0.0) : x(x), y(y){}; //constructor that takes an x and y value as arguments

        double getMagnitude(); // retruns the magnitude of the vector2

        void setXComponent(double newX); // set's the x component

        void setYComponent(double newY); //sets the y component

        double getXComponent(); //returns the x component as a double

        double getYComponent(); //returns the y component as a double

        void increment(double xInc = 0.0, double yInc = 0.0); //increments the vectors components by a specified value

        void setVector(double xInc = 0.0, double yInc = 0.0);

        void rotateVector(double rotation = 0.0); // rotates the vector2 by a specified amount in degrees 

        void print(); //prints the components of the vector2

        vector2 operator+(vector2& vect2); //overload of the + operator to add two vectors

        vector2 operator-(vector2& vect2); //subtracts 2 vectors and returns the new vector2

        vector2 operator*(double multiple); //multiplies two vectors

        double dot(vector2& vect); //function that performs the dot product on two vectors

    };

    vector2 addVector(vector2 v1, vector2 v2); // adds two vectors and returns a new vector2 as the product

};