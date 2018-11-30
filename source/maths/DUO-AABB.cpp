#include "DUO-Maths.h"
#include "DUO-AABB.h"

DUO::AABB::AABB(double x, double y, double width, double height) {

    centre.setVector(x, y); //sets the new centre position

    dimensions.setVector(width / 2, height / 2); //sets the dimensions to half values to make internal calculations easier

}