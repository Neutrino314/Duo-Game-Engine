#include "text.h"
#include <runtime/DUO-application.h>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

#include <unordered_map>
#include <string>
#include <cstdlib>


bool DUO::fontHandler::checkFont(TTF_Font* font)
{

    if (!font)
    {

        std::cout << "TTF open font error: " << TTF_GetError() << '\n';
        std::exit(1);

    }

    return true;
}


SDL_Texture* DUO::fontHandler::renderText(std::string fontName, SDL_Rect& renderRect,const textProps& props, std::string text)
{

    TTF_Font* tempFont = TTF_OpenFont(fontName.c_str(), props.fontSize);

    checkFont(tempFont);

    TTF_SizeText(tempFont, text.c_str(), &renderRect.w, &renderRect.h);

    SDL_Surface* textSurface;

    if (! (textSurface = TTF_RenderText_Blended(tempFont, text.c_str(), props.colour)))
    {

        std::cout << "TTF surface error: " << TTF_GetError() << '\n';
        std::exit(2);

    }

    

    SDL_Texture* retTexture = SDL_CreateTextureFromSurface(application::mainRenderer, textSurface);

    TTF_CloseFont(tempFont);
    tempFont = nullptr;

    SDL_FreeSurface(textSurface);
    textSurface = nullptr;

    return retTexture;

}

SDL_Texture* DUO::fontHandler::renderWrappedText(std::string fontName, std::size_t lineLength, SDL_Rect& renderRect, std::string text, const textProps& props)
{

    TTF_Font* tempFont = TTF_OpenFont(fontName.c_str(), props.fontSize);

    checkFont(tempFont);

    SDL_Surface* textSurface;

    if (! (textSurface = TTF_RenderText_Blended_Wrapped(tempFont, text.c_str(), props.colour, lineLength)))
    {

        std::cout << "TTF surface error: " << TTF_GetError() << '\n';
        std::exit(2);

    }

    SDL_Texture* retTexture = SDL_CreateTextureFromSurface(application::mainRenderer, textSurface);

    SDL_QueryTexture(retTexture, NULL, NULL, &renderRect.w, &renderRect.h);

    TTF_CloseFont(tempFont);
    tempFont = nullptr;

    SDL_FreeSurface(textSurface);
    textSurface = nullptr;

    return retTexture;

}