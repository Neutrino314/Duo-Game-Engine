#include <DUO-Core/source/DUO-Engine.h>
#include <typeinfo>
#include <iostream>
#include <SDL2/SDL.h>

class editor : public DUO::application {

public:

    editor(const char* title, int width, int height) : application(title, width, height) {}

    virtual void setup() {};

};


int main() {

    if (DUO::application::setupSDL() != 0) {

        return 1;

    }

    editor program("DUO Editor", 800, 600);

    program.start();

    return 0;

}