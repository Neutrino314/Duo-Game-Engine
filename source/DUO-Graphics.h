#ifndef DUO_GRAPHICS
#define DUO_GRAPHICS

#include <SDL2/SDL.h>
#include "DUO-Maths.h"

namespace DUO {

    void floodScreen(SDL_Renderer* renderer, short r, short g, short b, short a);
    void drawVector(SDL_Renderer* renderer, DUO::vector* vect);

    void drawTriangle(short x1, short y1, short x2, short y2, short x3, short y3, short r, short g, short b, SDL_Renderer* renderer);
    void fillTriangle(short x1, short y1, short x2, short y2, short x3, short y3, short r, short g, short b, SDL_Renderer* renderer);

    void drawRect(short x, short y, double rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height);
    void fillRect(short x, short y, double rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height);

}

#endif