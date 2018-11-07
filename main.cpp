#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "source/DUO-Engine.h"

class game : public DUO::runtime { //creating a subclass of the runtime class that allows it to be instantiated

public:

    game(std::string title, short w, short h) : DUO::runtime(title, w, h) {}; //constructor taking width, height and  a title as arguments then calling the super's constructor with those args
    virtual void setup(){

        sceneVect[0]->addObject(new DUO::gameObject(sceneVect[0]->curID, sceneVect[0]->sceneRenderer));
        sceneVect[0]->objectVect[0]->addComponent(new DUO::polygonRenderer(255, 255, 255, 4, 1, sceneVect[0]->objectVect[0], true, 100));

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