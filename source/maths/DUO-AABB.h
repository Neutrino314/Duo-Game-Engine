#pragma once

#include "DUO-Maths.h"

namespace DUO {

class AABB { //an AABB class

private:

    DUO::vector2 centre{0, 0}; //the AABB's centre point
    DUO::vector2 dimensions{1, 1}; //width and height half values

public:

    AABB(double x, double y, double width, double height); //the defaul constructor for the class

    void setDimensions(double newWidth, double newHeight); //sets the dimensions value

    DUO::vector2 getDimensions(); //gets the dimensions value

    void move(double newX, double newY); //moves the AABB to a new position

    DUO::vector2 getCentre();  // gets the coordinates of the AABB

    bool pointInThis(DUO::vector2 point); //tests whether a point is inside the AABB

    bool intersectsAABB(AABB box1); //tests whether this intersects with another AABB

};

}