#ifndef DUO_MATHS
#define DUO_MATHS
#include <iomanip>

namespace DUO {

    double deg2Rad(double value);

    class vector {

    private:

        double x {0};
        double y {0};

    public:

        vector(double x, double y) : x(x), y(y){};

        double getMagnitude();

        void setXComponent(double newX);

        void setYComponent(double newY);

        double getXComponent();

        double getYComponent();

        void rotateVector(double rotation = 0.0);

        void setRotation(double rotation = 0.0);

        void print();

    };

    vector addVector(vector v1, vector v2);

};

#endif