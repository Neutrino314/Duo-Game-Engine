#include "DUO-Maths.h"
#include "DUO-AABB.h"

DUO::AABB::AABB(double x, double y, double width, double height) {

    centre.setVector(x, y); //sets the new centre position

    dimensions.setVector(width / 2, height / 2); //sets the dimensions to half values to make internal calculations easier

}

DUO::vector2 DUO::AABB::getCentre() {return centre;} //returns a copy of the AABB's centre

DUO::vector2 DUO::AABB::getDimensions() {return dimensions;} //returns a copy of the AABB's dimesnions (half values)

void DUO::AABB::move(double newX, double newY) {centre.setVector(newX, newY);} //moves the AABB to a new position

void DUO::AABB::setDimensions(double newWidth, double newHeight) {dimensions.setVector(newWidth / 2, newHeight / 2);} //sets the AABB's dimensions

bool DUO::AABB::pointInThis(DUO::vector2 point) {

    if (point.getXComponent() >= centre.getXComponent() - dimensions.getXComponent() && point.getXComponent() <= centre.getXComponent() + dimensions.getXComponent()) {
    //^-----checks whether the point's x coordinate is within the boxes

        if (point.getYComponent() >= centre.getYComponent() - dimensions.getYComponent() && point.getYComponent() <= centre.getYComponent() + dimensions.getYComponent()) {
        //^------checks whether the point's y coordinate is within the boxes

            return true;

        }

    }

    return false;

}

bool DUO::AABB::intersectsAABB(AABB box1) {

    DUO::vector2 boxCentre = box1.getCentre();
    DUO::vector2 boxDimensions = box1.getDimensions();

    if ((centre + dimensions).getXComponent() > (boxCentre - boxDimensions).getXComponent() && (centre - dimensions).getXComponent() < (boxCentre + boxDimensions).getXComponent()
        && (centre + dimensions).getYComponent() > (boxCentre - boxDimensions).getYComponent() && (centre - dimensions).getYComponent() < (boxCentre + boxDimensions).getYComponent()) {

            return true;

    }

    return false;

}