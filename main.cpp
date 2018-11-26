#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "source/DUO-Engine.h"
#include "source/userComponents.h"

class game : public DUO::application { //creating a subclass of the application class that allows it to be instantiated

public:

    game(std::string title, short w, short h) : DUO::application(title, w, h) {}; //constructor taking width, height and  a title as arguments then calling the super's constructor with those args
    virtual void setup() override {

        application::sceneVect[0]->getObject(0)->addComponent(DUO::RENDERER, std::make_shared<DUO::spriteRenderer>("Pacman.png", 0, application::sceneVect[0]->getObject(0), 1.0, 1.0));

    }; //a setup function called before the game loop starts

};

int main(int argc, char* args[]) {

    if (DUO::application::setupSDL() != 0) { //  

        return 1;

    }

    game* run = new game("hi", 800, 600);

    run->start();

    delete run;
    run = nullptr;

    return 0;

};