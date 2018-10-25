#ifndef DUO_GRAPHICS
#define DUO_GRAPHICS

#include <SDL2/SDL.h>
#include "DUO-Maths.h"

namespace DUO {

    void floodScreen(SDL_Renderer* renderer, short r, short g, short b, short a);
    void drawVector(SDL_Renderer* renderer, DUO::vector* vect);
    void drawRect(short x, short y, double rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height);

}

#endif