#include <DUO-Engine.h>

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

#include "Editor.h"


int main() {

    if (DUO::application::setupSDL() != 0) {

        return 1;

    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL_SetRenderDrawBlendMode(DUO::application::mainRenderer, SDL_BLENDMODE_BLEND);

    return 0;

}
