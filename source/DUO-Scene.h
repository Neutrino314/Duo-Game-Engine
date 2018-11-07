#pragma once

#include <vector>
#include <SDL2/SDL.h>

namespace DUO {

    class gameObject;

}

namespace DUO {

    class scene {

    private:

        std::vector<DUO::gameObject*> objectVect;
        int curID{0};

    };

}