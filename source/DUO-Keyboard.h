#pragma once

#include <SDL2/SDL.h>
#include <cstring>


namespace DUO {
    
    class keyboard {


    public:

        static const Uint8* curState;
        static bool prevState[322];
        static void update();

        static bool isKeyPressed(SDL_Scancode key);
        static bool isKeyDown(SDL_Scancode key);
        static bool isKeyUp(SDL_Scancode key);    

    };

} // DUO
