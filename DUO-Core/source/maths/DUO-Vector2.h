#pragma once
#include "DUO-Maths.h"

namespace DUO {

    class vector2 {

    public:

        float x;
        float y;

        vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y){}; //constructor that takes an x and y value as arguments

        float getMagnitude(); // retruns the magnitude of the vector2

        void setXComponent(float newX); // set's the x component

        void setYComponent(float newY); //sets the y component

        float getXComponent(); //returns the x component as a float

        float getYComponent(); //returns the y component as a float

        void increment(float xInc = 0.0f, float yInc = 0.0f); //increments the vectors components by a specified value

        void setVector(float xInc = 0.0f, float yInc = 0.0f);

        void rotateVector(float rotation = 0.0f); // rotates the vector2 by a specified amount in degrees 

        void print(); //prints the components of the vector2

        vector2 operator+(vector2& vect2); //overload of the + operator to add two vectors

        vector2 operator-(vector2& vect2); //subtracts 2 vectors and returns the new vector2

        vector2 operator*(float multiple); //multiplies two vectors

        float dot(vector2& vect); //function that performs the dot product on two vectors

        vector2 normal(); //method that returns a normal vector

    };

    vector2 addVector(vector2 v1, vector2 v2); // adds two vectors and returns a new vector2 as the product

};