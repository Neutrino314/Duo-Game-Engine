#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "DUO-Utils.h"

namespace DUO {class scene; class gameObjectComponent;}

namespace DUO {

    class gameObject {

    private:

        DUO::scene* myScene;
        int myID;
        int curID{0};
        int rendererID{1};
        std::vector<gameObjectComponent*> componentVector;

    public:

        gameObject(int newID, DUO::scene* newScene);

        void update();

        void draw(SDL_Renderer* renderer);

        std::vector<DUO::gameObjectComponent*> getComponents(DUO::componentTypes componentType);

        void addComponent(gameObjectComponent* newComponent);

        void removeComponent(int componentID);

    };

}