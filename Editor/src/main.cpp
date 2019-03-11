#include <DUO-Engine.h>

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

#include "Editor.h"

class textLayer : public DUO::Layer
{

private:

    SDL_Texture* textTexture = NULL;
    SDL_Rect renderRect {400, 300, 0, 0};

public:

    textLayer(std::string newText) : Layer()
    {

        DUO::textProps props {};

        props.fontSize = 72;
        props.colour = {255, 255, 255, 255};

        textTexture = DUO::fontHandler::renderWrappedText("/usr/share/fonts/gnu-free/FreeSans.ttf", 72, renderRect, newText, props);

    };

    virtual void update() override {};

    virtual void render(float interpolation) override {

        SDL_RenderCopy(DUO::application::mainRenderer, textTexture, NULL, &renderRect);

    }

};

class play : public DUO::application {

public:

    play(const char* title, int width, int height) : application(title, width, height) {

        SDL_SetWindowResizable(getWin(), SDL_TRUE);

        layers.pushLayer(new textLayer("hi there"));

    }

};

int main() {

    if (DUO::application::setupSDL() != 0) {

        return 1;

    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL_SetRenderDrawBlendMode(DUO::application::mainRenderer, SDL_BLENDMODE_BLEND);

    play program("DUO Editor", 800, 600);

    program.start();

    return 0;

}
