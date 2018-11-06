#pragma once 
#include <string>
#include "DUO-Maths.h"

namespace DUO {

class gameObjectComponent {

protected:

    int ID;
    std::string componentType = "Base";

public:

    virtual void setup();

    virtual void update();

};

class transform : public gameObjectComponent{

protected:

    DUO::vector position{0.0, 0.0};
    double rotation{0.0};
    DUO::vector dimensions{0.0, 0.0};

public:

    transform(double x, double y, double newRotation, double width, double height);

    void translate(double x, double y);

    void rotate(double newRotation);

    void resize(double newWidth = 0.0, double newHeight = 0.0);

    DUO::vector getPosition();
    DUO::vector getDimensions();

};

class polygonRenderer : public gameObjectComponent {

protected:

    short numberOfSides;
    short r;
    short g;
    short b;

};

class rectangleRenderer : public gameObjectComponent {};

}