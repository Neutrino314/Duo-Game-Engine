#pragma once

#include <vector>
#include <SDL2/SDL.h>

namespace DUO {class gameObject;}

namespace DUO {

    class scene {

    private:

        std::vector<DUO::gameObject*> objectVect;
        int curID{0};
        int myID;
        SDL_Renderer* sceneRenderer;

    public:

        scene(int newID, SDL_Renderer* newRenderer);

        void update();

        void draw();

        void addObject(DUO::gameObject* newObject);

        void removeObject(int objectID);

    };

}