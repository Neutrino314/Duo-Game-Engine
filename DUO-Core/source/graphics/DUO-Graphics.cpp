#include "DUO-Graphics.h"
#include <maths/DUO-Vector2.h> //provides the use of DUO::vector2
#include <utility> //used for std::swap
#include <cmath> //provides a set of maths functions including round and sqrt
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void DUO::floodScreen(SDL_Renderer* renderer, short r, short g, short b, short a) {

    SDL_SetRenderDrawColor(renderer, r, g, b, a); // sets the renderer's draw colour to the specified rgba values
    SDL_RenderClear(renderer); //clears the window and set's to the aforementioned colour

};

void DUO::drawVector(SDL_Renderer* renderer, DUO::vector2* vect) {

    //draws a line from the origin to the components of the vector using the SDL_Drawline function

    SDL_RenderDrawLine(renderer, 0, 0, static_cast<int>(vect->x), static_cast<int>(vect->y));

};

void DUO::drawTriangle(short x1, short y1, short x2, short y2, short x3, short y3, short r, short g, short b, SDL_Renderer* renderer) {

    SDL_Point pointArray[4]  = {{x1, y1}, {x2, y2}, {x3, y3}, {x1, y1}}; //creates a point array going clockwise

    SDL_SetRenderDrawColor(renderer, r, g, b, 255); //set's the renderers drawing colour

    SDL_RenderDrawLines(renderer,pointArray, 4); //draws the points previously specified in the array

};

void DUO::fillTopTriangle(float x1, float y1, float x2, float y2, float x3, float y3, short r, short g, short b, SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, r, g, b, 255); //sets the renderer's drawing colour

    /* This fill algorithm works by stepping through the triangle's height by 1 and then drawing a line in between the two sides of said triangle, 
       the x values of the points at which the line intersects both sides are calculated by the formula (dx / dy)
       by storing these values in two variables you then recieve an amount the x can be incremented by in order to achieve sides with the same slope.
       credit to the http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html#algo2 for the algorithm
    */

    float invSlope1{(x2 - x1) / (y2 - y1)}; //the amount that the x value must be increased in every time to achieve the correct slope of one side
    float invSlope2{(x2 - x3) / (y2 - y3)}; //the amount that the x value must be increased in every time to achieve the correct slope of one side

    float curX1{x2}; //this variable will hold the current x coordinate that is being used to step through the first side
    float curX2{x2}; //this variable will hold the current x coordinate that is being used to step through the second side

    for (int scanLine = y2; scanLine > y1; scanLine --) { //for loop running through the y values in the triangle from the highest to lowest

            SDL_RenderDrawLine(renderer, static_cast<int>(curX1), scanLine, static_cast<int>(curX2), scanLine); //draws a line from one side of the triangle to the other using the curX variables and scanLine

            curX1 -= invSlope1; //decrements curX1 by the first inverse slope (dx1) so that the line will have the same slope as specified
            curX2 -= invSlope2; //decrements curX2 by the second inverse slope (dx2) so that the line will have the same slope as specified

    }

    SDL_Point pointArray[4]  = {{static_cast<int>(std::round(x1)), static_cast<int>(std::round(y1))}, //creates an array of points based on the points specified in order to draw the outer triangle
                                {static_cast<int>(std::round(x2)), static_cast<int>(std::round(y2))}, 
                                {static_cast<int>(std::round(x3)), static_cast<int>(std::round(y3))}, 
                                {static_cast<int>(std::round(x1)), static_cast<int>(std::round(y1))}};

    SDL_RenderDrawLines(renderer, pointArray, 4); //draws the outer triangle using the point array and the SDL_RenderDrawLines functions

};

void DUO::fillBottomTriangle(float x1, float y1, float x2, float y2, float x3, float y3, short r, short g, short b, SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, r, g, b, 255); //sets the renderer's drawing colour

    /* This fill algorithm works by stepping through the triangle's height by 1 and then drawing a line in between the two sides of said triangle, 
       the x values of the points at which the line intersects both sides are calculated by the formula (dx / dy)
       by storing these values in two variables you then recieve an amount the x can be incremented by in order to achieve sides with the same slope.
       credit to the http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html#algo2 for the algorithm
    */

    float invSlope1{(x2 - x1) / (y2 - y1)}; //the amount that the x value must be increased in every time to achieve the correct slope of one side
    float invSlope2{(x2 - x3) / (y2 - y3)}; //the amount that the x value must be increased in every time to achieve the correct slope of one side

    float curX1{x2}; //this variable will hold the current x coordinate that is being used to step through the first side
    float curX2{x2}; //decrements curX2 by the first inverse slope (dx2) so that the line will have the same slope as specified

    for (int scanLine = y2; scanLine < y1; scanLine ++) { //for loop running through the y values in the triangle from the lowest to highest

            SDL_RenderDrawLine(renderer, static_cast<int>(curX1), scanLine, static_cast<int>(curX2), scanLine);

            curX1 += invSlope1; //increments curX1 by the first inverse slope (dx1) so that the line will have the same slope as specified
            curX2 += invSlope2; //increments curX2 by the second inverse slope (dx2) so that the line will have the same slope as specified

    }

    SDL_Point pointArray[4]  = {{static_cast<int>(std::round(x1)), static_cast<int>(std::round(y1))}, //creates an array of points based on the points specified in order to draw the outer triangle
                                {static_cast<int>(std::round(x2)), static_cast<int>(std::round(y2))}, 
                                {static_cast<int>(std::round(x3)), static_cast<int>(std::round(y3))}, 
                                {static_cast<int>(std::round(x1)), static_cast<int>(std::round(y1))}};

    SDL_RenderDrawLines(renderer, pointArray, 4); //draws the outer triangle using the point array and the SDL_RenderDrawLines function

};

void DUO::fillTriangle(float x1, float y1, float x2, float y2, float x3, float y3, short r, short g, short b, SDL_Renderer* renderer) {

    //check out http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html#algo2 for the algorithm explained

    if (y1 == y3 && y2 > y1) { //if the base's y value is lesser than the other point then the fillTopTriangle function is called

        DUO::fillTopTriangle(x1, y1, x2, y2, x3, y3, r, g, b, renderer);

    } else if (y1 == y3 && y2 < y1) { //if the base's y value is greater than the other point then the fillBottomTriangle function is called

        DUO::fillBottomTriangle(x1, y1, x2, y2, x3, y3, r, g, b, renderer);

    } else {

        /*  if the triangle soesn't fall into either of the two previously mentioned cases then the triangle is broken up into a bottom triangle and a top triangle
            in order to do so the point with the middlemost y value  is used to calculate the x position at which the triangle's other side intersects it
        */


        DUO::vector2 pointVectors[] = {DUO::vector2(x1, y1), //creates an array of vectors whose components are based on the position variables passed as arguments
                                    DUO::vector2(x2, y2),
                                    DUO::vector2(x3, y3)};

        bool sortFinished {false}; // creates a boolean called sortFinished to be used to tell whether the sort has ended

        while (!sortFinished) { //while loop that runs while the sort hasn't finished

            for (int i = 0; i < 2; i ++) { //for loop that goes from 0 to 1

                if (pointVectors[0].y <= pointVectors[1].y && pointVectors[1].y <= pointVectors[2].y) { //if all of the vectors y components are larger than the first in an ascending order then the loop is broken and sortFinished is et to true

                    sortFinished = true;
                    break;

                }else if (pointVectors[i].y > pointVectors[i + 1].y) { //if the vector's y component is greater than the next element then swap those elements 

                    std::swap(pointVectors[i], pointVectors[i + 1]);
                    continue;

                } else if (pointVectors[i].y < pointVectors[i + 1].y) { //if the next element's y component is greater than the current element's then continue the for loop

                    continue;

                }
            }

        }

        //calculating the point at which the line intersects the other side:
        float x4{pointVectors[0].x + (((pointVectors[1].y - pointVectors[0].y) / (pointVectors[2].y - pointVectors[0].y) * (pointVectors[2].x - pointVectors[0].x)))};
        float y4 = pointVectors[1].y;

        //fills the two newly created triangles
        DUO::fillTopTriangle(pointVectors[1].x, pointVectors[1].y, pointVectors[2].x, pointVectors[2].y, x4, y4, r, g, b, renderer);
        DUO::fillBottomTriangle(x4, y4, pointVectors[0].x, pointVectors[0].y, pointVectors[1].x, pointVectors[1].y, r, g, b, renderer);

    }

};

void DUO::drawRect(short x, short y, float rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height) {

    DUO::vector2 vectorArray[] = {DUO::vector2(-(width / 2), -(height / 2)), //creates an array of vectors for each point of the rectangle starting in the top left going clockwise
                                 DUO::vector2(width / 2, -(height / 2)),
                                 DUO::vector2(width / 2, height / 2),
                                 DUO::vector2(-(width / 2), height / 2)};

    SDL_Point pointArray[5]; //creating an array of SDL_Points to be used later in the SDL_RenderDrawLines function

    for (int i = 0; i < 4; i++) { //for loop running from 0 to 3

        vectorArray[i].rotateVector(rotation); //rotates the current element of the vector array by the amount specified by the variable rotation

        //adds the current vector to the point array and adding the centre point values to each component before rounding and casting to an integer:
        pointArray[i] = {static_cast<int>(std::round(vectorArray[i].x)) + x, static_cast<int>(std::round(vectorArray[i].y)) + y};

    }

    pointArray[4] = pointArray[0]; //set's the last element of the point array equal to the first

    SDL_SetRenderDrawColor(renderer, r, g, b, 255); //sets the renderer's drawing colour

    SDL_RenderDrawLines(renderer, pointArray, 5); //draws the rectangle

};

void DUO::fillRect(short x, short y, float rotation, short r, short g, short b, SDL_Renderer* renderer, short width, short height) {

    DUO::vector2 vectorArray[] = {DUO::vector2(-(width / 2), -(height / 2)), //creates an array of vectors for each point of the rectangle starting in the top left going clockwise
                                 DUO::vector2(width / 2, -(height / 2)),
                                 DUO::vector2(width / 2, height / 2),
                                 DUO::vector2(-(width / 2), height / 2)};

    for (DUO::vector2 &element : vectorArray) { // a foreach loop running through each vector in the array by reference

        element.rotateVector(rotation); //rotates the vector
        element.increment(x, y); //increments the vector's components by the centre point

    }

    //separates the rectangle into two triangles and then fills them
    DUO::fillTriangle(vectorArray[0].x, vectorArray[0].y, vectorArray[1].x, vectorArray[1].y, vectorArray[2].x, vectorArray[2].y,  r, g, b, renderer);
    DUO::fillTriangle(vectorArray[0].x, vectorArray[0].y, vectorArray[3].x, vectorArray[3].y, vectorArray[2].x, vectorArray[2].y, r, g, b, renderer);

};


void DUO::drawCircle(short x, short y, short radius, short r, short g, short b, SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    int x0 = 0;
    int y0 = static_cast<int>(radius);
    int d = 3 - 2 * radius;

    if (!radius) return;

    while (y0 >= x0) {

        SDL_RenderDrawPoint(renderer, x - x0, y - y0);
        SDL_RenderDrawPoint(renderer, x - y0, y - x0);
        SDL_RenderDrawPoint(renderer, x + y0, y - x0);
        SDL_RenderDrawPoint(renderer, x + x0, y - y0);
        SDL_RenderDrawPoint(renderer, x - x0, y + y0);
        SDL_RenderDrawPoint(renderer, x - y0, y + x0);
        SDL_RenderDrawPoint(renderer, x + y0, y + x0);
        SDL_RenderDrawPoint(renderer, x + x0, y + y0);
        if (d < 0) d += 4 * x0++ + 6;
        else d += 4 * (x0++ - y0--) + 10;

    }

};

void DUO::fillCircle(short x, short y, short radius, short r, short g, short b, SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    int x0 = 0;
    int y0 = static_cast<int>(radius);
    int d = 3 - 2 * radius;

    if (!radius) return;

    while (y0 >= x0) {

        SDL_RenderDrawLine(renderer, x - x0, y - y0, x + x0, y - y0);
        SDL_RenderDrawLine(renderer, x - y0, y - x0, x + y0, y - x0);
        SDL_RenderDrawLine(renderer, x - x0, y + y0, x + x0, y + y0);
        SDL_RenderDrawLine(renderer, x - y0, y + x0, x + y0, y + x0);
        if (d < 0) d += 4 * x0++ + 6;
        else d += 4 * (x0++ - y0--) + 10;

    }

}

void DUO::drawPolygon(short numberOfSides, short sideLength, short x, short y, short r, short g, short b, SDL_Renderer* renderer, float rotation) {
     
    DUO::vector2 vectorArray[numberOfSides];

     float centreAngle {static_cast<float>(360 / numberOfSides)};

     float cornerAngle = static_cast<int>(180 * (numberOfSides - 2) / numberOfSides);

     float halfLength{static_cast<float>(sideLength / 2)};

     vectorArray[0] = DUO::vector2(halfLength, static_cast<float>((std::tan(DUO::deg2Rad(cornerAngle / 2))) * halfLength));
     
     for (int i = 1; i < numberOfSides; i ++) {
     
         DUO::vector2 tempVect = vectorArray[i - 1];
     
         tempVect.rotateVector(centreAngle);
     
         vectorArray[i] = tempVect;        
     
     }
     
     for (int i = 0; i < numberOfSides; i ++) {vectorArray[i].rotateVector(rotation);}
     
     SDL_Point pointArray[numberOfSides + 1];
     
     for (int i = 0; i < numberOfSides; i ++) {
     
         pointArray[i] = {static_cast<int>(std::round(vectorArray[i].x + x)), static_cast<int>(std::round(vectorArray[i].y + y))};
     
     }
     
     pointArray[numberOfSides] = pointArray[0];
     SDL_SetRenderDrawColor(renderer, r, g, b, 255);
     SDL_RenderDrawLines(renderer, pointArray, numberOfSides + 1);
     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
     SDL_RenderDrawPoint(renderer, x, y);
 
};

 
 void DUO::fillPolygon(short numberOfSides, short sideLength, short x, short y, short r, short g, short b, SDL_Renderer* renderer, float rotation) {
     
     DUO::vector2 vectorArray[numberOfSides];
     
     float centreAngle {static_cast<float>(360 / numberOfSides)};
     
     float cornerAngle = static_cast<int>(180 * (numberOfSides - 2) / numberOfSides);
     
     float halfLength{static_cast<float>(sideLength / 2)};
     
     vectorArray[0] = DUO::vector2(halfLength, static_cast<float>((std::tan(DUO::deg2Rad(cornerAngle / 2))) * halfLength));
     
     for (int i = 1; i < numberOfSides; i ++) {
     
         DUO::vector2 tempVect = vectorArray[i - 1];
         tempVect.rotateVector(centreAngle);
         vectorArray[i] = tempVect;        
     
     }
     
     for (int i = 0; i < numberOfSides; i ++) {
        
        vectorArray[i].rotateVector(rotation);
        vectorArray[i].increment(static_cast<float>(x), static_cast<float>(y));
     
     }
     
     DUO::fillTriangle(x, y, std::round(vectorArray[0].x), std::round(vectorArray[0].y), std::round(vectorArray[numberOfSides - 1].x), std::round(vectorArray[numberOfSides - 1].y), r, g, b, renderer);
     
     for (int i = 1; i < numberOfSides; i++) {
     
         DUO::fillTriangle(x, y, std::round(vectorArray[i].x), std::round(vectorArray[i].y), std::round(vectorArray[i - 1].x), std::round(vectorArray[i - 1].y), r, g, b, renderer);
     
     }
 ;}

SDL_Texture* DUO::loadImage(std::string path, SDL_Renderer* renderer) {

    SDL_Surface* tempSurface = IMG_Load(path.c_str());

    SDL_Texture* returnTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

    SDL_FreeSurface(tempSurface);
    tempSurface = nullptr;

    return returnTexture;

}