#pragma once

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

#include <unordered_map>
#include <string>

namespace DUO
{

struct textProps
{
    
    int fontSize{14};
    SDL_Color colour{0, 0, 0, 255};

};


class fontHandler
{

private:

    static bool checkFont(TTF_Font* font = NULL);

public:

    static SDL_Texture* renderText(std::string fontName, SDL_Rect& renderRect,const textProps& props = textProps(), std::string text = "");

    static SDL_Texture* renderWrappedText(std::string fontName, std::size_t lineLength, SDL_Rect& renderRect, std::string text = "", const textProps& props = textProps());

};

} // DUO
