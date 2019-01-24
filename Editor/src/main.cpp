#include <DUO-Core/source/DUO-Engine.h>
#include "CLI/CLI.h"

#include <vector>
#include <string>
#include <iostream>

class play : public DUO::application {

public:

    play(const char* title, int width, int height) : application(title, width, height) {}

};

int main() {

    if (DUO::application::setupSDL() != 0) {

        return 1;

    }

    play program("DUO Editor", 800, 600);

    DUO::sceneManager::loadScene("test.yaml", program.mainRenderer);

    program.start();

    return 0;

}