#pragma once

#include "DUO-Maths.h"

namespace DUO {

class component {

public:

    virtual void update();

};

class transform : public component {

public:

    DUO::vector position = DUO::vector(0.0, 0.0);
    double rotation;

};

}