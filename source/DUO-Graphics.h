#ifndef DUO_GRAPHICS
#define DUO_GRAPHICS

#include <SDL2/SDL.h>

namespace DUO {

    void drawRect(short x, short y, signed short rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height);

}

#endif