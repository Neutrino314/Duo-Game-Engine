#include <DUO-Engine.h>
#include <memory>
#include <vector>

#include "panel.h"

void Editor::panel::update()
{

    SDL_Rect tempRect {m_position.x, m_position.y, m_dimensions.x, m_dimensions.y};

    SDL_SetRenderDrawColor(DUO::application::mainRenderer, m_panelColour.r, m_panelColour.g, m_panelColour.b, m_panelColour.a);

    SDL_RenderFillRect(DUO::application::mainRenderer, &tempRect);

    for (const auto& obj : m_objectVect)
    {

        obj->update();

    }

};