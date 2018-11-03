#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "source/DUO-Engine.h"

class game : public DUO::runtime { //creating a subclass of the runtime class that allows it to be instantiated

public:

    game(std::string title, short w, short h) : DUO::runtime(title, w, h) {}; //constructor taking width, height and  a title as arguments then calling the super's constructor with those args
    void setup(){}; //a setup function called before the game loop starts
    void update(){}; //all of the game logic takes place here
    void draw(){

        DUO::fillCircle(400, 300, 100, 200, 200, 255, mainRenderer);

    }; //all of the drawing is handled by this draw function

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