#include "DUO-Keyboard.h"
#include <SDL2/SDL.h>

const Uint8* DUO::keyboard::curState = SDL_GetKeyboardState(NULL);
bool DUO::keyboard::prevState[322] {false};

void DUO::keyboard::update() {

    for (int i = 0; i < 322; i++) {

        if (DUO::keyboard::curState[i] == true) {

            DUO::keyboard::prevState[i] = true;

        } else {

            DUO::keyboard::prevState[i] = false;

        }

    }

}

bool DUO::keyboard::isKeyPressed(SDL_Scancode key) {

    if (prevState[key] == false && curState[key] == true) {

        return true;

    } else {

        return false;

    }

}

bool DUO::keyboard::isKeyDown(SDL_Scancode key) {

    if (curState[key] == true) {

        return true;
        
    }

    return false;

}

bool DUO::keyboard::isKeyUp(SDL_Scancode key) {

    if (curState[key] == false) {

        return true;

    }

    return false;

}