#pragma once

#include <SDL2/SDL.h>

namespace DUO
{
    
    class Layer
    {

    protected:

        bool m_visible{true};

    public:

        Layer() {};

        virtual ~Layer() {};

        virtual void update() {};

        virtual void render(float interpolation) {};

        inline bool isVisible() {return m_visible;}

        inline void setVisible(bool visibility) {m_visible = visibility;}

    };

} // DUO
