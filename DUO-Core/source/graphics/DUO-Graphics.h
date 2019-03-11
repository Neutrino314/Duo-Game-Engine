#ifndef DUO_GRAPHICS
#define DUO_GRAPHICS

#include <SDL2/SDL.h>
#include <maths/DUO-Vector2.h>
#include <string>

namespace DUO {

    void floodScreen(SDL_Renderer* renderer, SDL_Color& color); //a rednerClear-ish type command that fills the window with a certain colour
    void drawVector(SDL_Renderer* renderer, DUO::vector2* vect); //draws a vector as a line from the origin taking a DUO::vector2 object and a renderer as arguments

    void drawTriangle(short x1, short y1, short x2, short y2, short x3, short y3, SDL_Color& color, SDL_Renderer* renderer); //a triangle draw function taking 3 sets of sequential points
    void fillTopTriangle(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Color& color, SDL_Renderer* renderer); // a triangle fill function that draws a trinagle with y of the 1 and 3 points being lower than the 2
    void fillBottomTriangle(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Color& color, SDL_Renderer* renderer); // a triangle fill function that draws a trinagle with y of the 1 and 3 points being higher than the 2
    void fillTriangle(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Color& color, SDL_Renderer* renderer); //a triangle fill function that fills any triangle

    void drawRect(short x, short y, float rotation, SDL_Color& color, SDL_Renderer* renderer, short width, short height); //draws a rectangle of a certain width, height rotation and position
    void fillRect(short x, short y, float rotation, SDL_Color& color, SDL_Renderer* renderer, short width, short height); //fills a rectangle of a certain width, height rotation and position

    void drawCircle(short x, short y, short radius, SDL_Color& color, SDL_Renderer* renderer); //draws a circle with a given radius
    void fillCircle(short x, short y, short radius, SDL_Color& color, SDL_Renderer* renderer); //fills a circle with a given radius

    void drawPolygon(short numberOfSides, short sideLength, short x, short y, SDL_Color& color, SDL_Renderer* renderer, float rotation);
    void fillPolygon(short numberOfSides, short sideLength, short x, short y, SDL_Color& color, SDL_Renderer* renderer, float rotation);
        
    SDL_Texture* loadImage(std::string path, SDL_Renderer* renderer);
    
}

#endif
