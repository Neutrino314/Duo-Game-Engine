#pragma once
#include <vector>
#include "DUO-GameObject.h"

namespace DUO
{

class scene {

private:

    int curID{0};
    std::vector<DUO::gameObject*> objectVect;

public:

    void update();
    void draw();

    void addObject();
    void removeObject(int objectID);
    
};

} // DUO