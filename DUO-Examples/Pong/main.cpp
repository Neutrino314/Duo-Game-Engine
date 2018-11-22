#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "source/DUO-Engine.h"
#include "source/userComponents.h"

class game : public DUO::runtime { //creating a subclass of the runtime class that allows it to be instantiated

public:

    game(std::string title, short w, short h) : DUO::runtime(title, w, h) {}; //constructor taking width, height and  a title as arguments then calling the super's constructor with those args
    virtual void setup() override {

        sceneVect[0]->getObject(0)->move(750, 100);
        sceneVect[0]->getObject(0)->addComponent(DUO::RENDERER, std::make_shared<DUO::paddleRenderer>(0, sceneVect[0]->getObject(0), 25, 150, 255, 255, 255));
        sceneVect[0]->getObject(0)->addComponent(DUO::BASE, std::make_shared<DUO::paddleController>(0, sceneVect[0]->getObject(0), SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, sceneVect[0]->getObject(0)->getTransform()));

        sceneVect[0]->addObject(new DUO::gameObject(1, mainRenderer));
        sceneVect[0]->getObject(1)->move(50, 100);
        sceneVect[0]->getObject(1)->addComponent(DUO::RENDERER, std::make_shared<DUO::paddleRenderer>(0, sceneVect[0]->getObject(1), 25, 150, 255, 0, 0));
        sceneVect[0]->getObject(1)->addComponent(DUO::BASE, std::make_shared<DUO::paddleController>(0, sceneVect[0]->getObject(1), SDL_SCANCODE_W, SDL_SCANCODE_S, sceneVect[0]->getObject(1)->getTransform()));

        sceneVect[0]->addObject(new DUO::gameObject(2, mainRenderer));
        sceneVect[0]->getObject(2)->move(400.0, 300.0);
        sceneVect[0]->getObject(2)->addComponent(DUO::BASE, std::make_shared<DUO::ballComponent>(0, sceneVect[0]->getObject(2), sceneVect[0]->getObject(2)->getTransform(), sceneVect[0]->getObject(1), sceneVect[0]->getObject(0)));
        sceneVect[0]->getObject(2)->addComponent(DUO::RENDERER, std::make_shared<DUO::ballRenderer>(0, sceneVect[0]->getObject(2), 25.0, 255, 255, 255));

    }; //a setup function called before the game loop starts

};

int main(int argc, char* args[]) {

    if (DUO::runtime::setupSDL() != 0) { //  

        return 1;

    }

    game* run = new game("Ping", 800, 600);

    run->start();

    delete run;
    run = nullptr;

    return 0;

};