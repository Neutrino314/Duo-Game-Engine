#include "DUO-Graphics.h"
#include "DUO-Maths.h"
#include <cmath>
#include <iostream>
#include <SDL2/SDL.h>

void DUO::floodScreen(SDL_Renderer* renderer, short r, short g, short b, short a) {

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);

};

void DUO::drawVector(SDL_Renderer* renderer, DUO::vector* vect) {

    SDL_RenderDrawLine(renderer, 0, 0, static_cast<int>(vect->getXComponent()), static_cast<int>(vect->getYComponent()));

};

void DUO::drawTriangle(short x1, short y1, short x2, short y2, short x3, short y3, short r, short g, short b, SDL_Renderer* renderer) {

    SDL_Point pointArray[4]  = {{x1, y1}, {x2, y2}, {x3, y3}, {x1, y1}};

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_RenderDrawLines(renderer,pointArray, 4);

};

void DUO::fillTriangle(short x1, short y1, short x2, short y2, short x3, short y3, short r, short g, short b, SDL_Renderer* renderer) {

    

};

void DUO::drawRect(short x, short y, double rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height) {

    DUO::vector vectorArray[] = {DUO::vector(-(width / 2), -(height / 2)),
                                 DUO::vector(width / 2, -(height / 2)),
                                 DUO::vector(width / 2, height / 2),
                                 DUO::vector(-(width / 2), height / 2)};

    SDL_Point pointArray[5];

    for (int i = 0; i < 4; i++) {

        vectorArray[i].rotateVector(rotation);

        //std::cout << vectorArray[i].getXComponent() << ", " << vectorArray[i].getYComponent() << std::endl;

        pointArray[i] = {static_cast<int>(std::round(vectorArray[i].getXComponent())) + x, static_cast<int>(std::round(vectorArray[i].getYComponent())) + y};

        std::cout << pointArray[i].x << ", " << pointArray[i].y << std::endl;

    }

    pointArray[4] = pointArray[0];

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_RenderDrawLines(renderer, pointArray, 5);

    SDL_RenderDrawPoint(renderer, x, y);

};




