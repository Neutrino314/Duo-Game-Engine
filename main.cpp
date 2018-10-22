#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "source/DUO-Engine.h"
#include <thread>

class game : public DUO::runtime {

public:

    game(std::string title, short w, short h) : DUO::runtime(title, w, h) {};
    void setup(){};
    void update(){};
    void draw(){};

};

int main(int argc, char* args[]) {

    if (DUO::runtime::setupSDL() != 0) {

        return 1;

    }

    game* run = new game("hi", 800, 600);

    run->start();

    delete run;
    run = nullptr;

    std::cout << "Huh, so it worked\n";

    return 0;

};