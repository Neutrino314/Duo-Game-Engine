#pragma once

#include <SDL2/SDL.h>
#include <vector>

namespace DUO {class scene; class gameObjectComponent;}

namespace DUO {

    class gameObject {

    private:

        DUO::scene* myScene;
        int myID;
        int curID{0};
        std::vector<gameObjectComponent*> componentVector;

    public:

        gameObject(int newID, DUO::scene* newScene);

        void update();

        void draw(SDL_Renderer* renderer);

        void addComponent(gameObjectComponent* newComponent);

        void removeComponent();

    };

}