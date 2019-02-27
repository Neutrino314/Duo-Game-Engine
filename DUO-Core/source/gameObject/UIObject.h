#include "DUO-GameObject.h"
#include <bitset>

#pragma once

namespace DUO
{

class UIObject
{

private:

    DUO::vector2 position{0.0f, 0.0f};

public:

    UIObject() {};

    ~UIObject() {};

    virtual void update() {};

};

enum class BUTTON_FLAGS { 

    HAS_IMAGE,
    HAS_TEXT

};

class button : UIObject
{

private:

public:


};

}