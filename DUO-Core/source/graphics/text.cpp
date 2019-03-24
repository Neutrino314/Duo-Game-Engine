#include "text.h"
#include <runtime/DUO-application.h>
#include <utils/stringUtils.h>

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

    SDL_Surface* lineSurface;

    checkFont(tempFont);

    std::vector<std::string> wordVect{DUO::split(text, ' ')};

    DUO::removeWhitespace(wordVect);

    std::vector<std::string> wrappedVect {""};

    SDL_Point wordSize{0, 0};

    SDL_Point textSize{0, 0}; //used to determine the final size of the resulting text block

    int maxLine = 0;

    for (const auto word : wordVect) {

        TTF_SizeText(tempFont, (wrappedVect.back() + " " + word).c_str(), &wordSize.x, &wordSize.y);
        //check width of word in pixels, height doesn't matter

        if (wordSize.x > lineLength) {
        //if the length of the current line + the new word exceeds the line length then a new line is started
            wrappedVect.emplace_back(word);

        }
        else
        {

            wrappedVect.back() += word + " ";

        }

    }

    for (auto line : wrappedVect) {

        TTF_SizeText(tempFont, line.c_str(), &maxLine, NULL);

            if (maxLine > textSize.x)
                textSize.x = maxLine;

    }

    textSize.y = wordSize.y * wrappedVect.size();

    SDL_Surface* textSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, textSize.x, textSize.y, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

    for(size_t i = 0; i < wrappedVect.size(); i++)
    {

        SDL_Rect tempRect {0, i * wordSize.y, 0, 0};

        if (! (lineSurface = TTF_RenderText_Blended(tempFont, wrappedVect[i].c_str(), props.colour)))
        {

        std::cout << "TTF surface error: " << TTF_GetError() << '\n';
        std::exit(2);

        }

        std::cout << wrappedVect[i] << std::endl;

        if (SDL_BlitSurface(lineSurface, NULL, textSurface, &tempRect) != 0) {

            std::cerr << SDL_GetError() << std::endl;
            std::exit(2);

        }

    }

    TTF_CloseFont(tempFont);
    tempFont = nullptr;

    SDL_FreeSurface(lineSurface);
    lineSurface = nullptr;

    SDL_Texture* retTexture = SDL_CreateTextureFromSurface(DUO::application::mainRenderer, textSurface);

    SDL_FreeSurface(textSurface);
    textSurface = nullptr;

    SDL_QueryTexture(retTexture, NULL, NULL, &renderRect.w, &renderRect.h);

    return retTexture;

}