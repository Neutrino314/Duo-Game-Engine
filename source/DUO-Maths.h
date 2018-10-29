#ifndef DUO_MATHS
#define DUO_MATHS
#include <iomanip>

namespace DUO {

    double deg2Rad(double value);

    class vector {

    private:

        double x {0}; //private x component
        double y {0}; //private y component

    public:

        vector(double x, double y) : x(x), y(y){}; //constructor that takes an x and y value as arguments

        double getMagnitude(); // retruns the magnitude of the vector

        void setXComponent(double newX); // set's the x component

        void setYComponent(double newY); //sets the y component

        double getXComponent(); //returns the x component as a double

        double getYComponent(); //returns the y component as a double

        void increment(double xInc = 0.0, double yInc = 0.0); //increments the vectors components by a specified value

        void rotateVector(double rotation = 0.0); // rotates the vector by a specified amount in degrees 

        void print(); //prints the components of the vector

    };

    vector addVector(vector v1, vector v2); // adds two vectors and returns a new vector as the product

};

#endif