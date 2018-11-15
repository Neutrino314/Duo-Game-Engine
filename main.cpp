#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "source/DUO-Engine.h"

class game : public DUO::runtime { //creating a subclass of the runtime class that allows it to be instantiated

public:

    game(std::string title, short w, short h) : DUO::runtime(title, w, h) {}; //constructor taking width, height and  a title as arguments then calling the super's constructor with those args
    virtual void setup() override {

        sceneVect.push_back(new DUO::scene(0, mainRenderer));

        sceneVect[0]->getObject(0)->addComponent(DUO::RENDERER, std::make_shared<DUO::polygonRenderer>(0, sceneVect[0]->getObject(0), 100.0, 100.0, 255, 255, 255, 6));

        sceneVect[0]->getObject(0)->addComponent(DUO::BASE, std::make_shared<DUO::basicMovementComponent>(0, sceneVect[0]->getObject(0)));

    }; //a setup function called before the game loop starts

};

int main(int argc, char* args[]) {

    if (DUO::runtime::setupSDL() != 0) { //  

        return 1;

    }

    game* run = new game("hi", 800, 600);

    run->start();

    delete run;
    run = nullptr;

    std::cout << "Huh, so it worked\n";

    return 0;

};