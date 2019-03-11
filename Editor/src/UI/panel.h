#include <DUO-Engine.h>
#include <bitset>
#include <memory>
#include <vector>

#pragma once

namespace Editor
{

    enum class PANEL_FLAGS
    {

        VISIBLE,
        ACTIVE

     };

    class panel
    {

    public:

        panel() {};

        virtual ~panel() {};

        virtual void update();

        void setColor(short r, short g, short b) {m_panelColour = {r, g, b, 255};}

        void resize(float x, float y) {m_dimensions.setVector(x, y);}

    protected:

        std::vector<std::unique_ptr<DUO::UIObject>> m_objectVect;

        std::bitset<2> m_panelMask;

        DUO::vector2 m_dimensions{1.0f, 1.0f};

        DUO::vector2 m_position{0.0f, 0.0f};

        SDL_Color m_panelColour {0, 0, 0, 255};

    };



}