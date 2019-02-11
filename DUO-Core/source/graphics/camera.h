#pragma once

#include <gameObject/DUO-GameObject.h>
#include <gameObject/DUO-GameObjectComponent.h>
#include <gameObject/DUO-Scene.h>

#include <maths/DUO-Vector2.h>
#include <yaml/parser.h>

namespace DUO
{

class camera
{

private:

    bool hasTarget{false};
    int targetID{0};

    DUO::vector2 origin{0.0f, 0.0f};
    DUO::vector2 offset{0.0f, 0.0f};
    DUO::vector2 pos{0.0f, 0.0f};

    DUO::gameObject* myObj = NULL;

public:

    camera(bool targetIndicator = false);

    ~camera();

    int getTargetID();

    void setTargetID(int ID);

    void update();

    void setup();

    void loadTarget(DUO::gameObject* obj);

    void calculateOffset(float interpolation);

    DUO::vector2 getOffset() {return offset;}

    void setOrigin(DUO::vector2 newOrigin) {origin = newOrigin;}

};

}