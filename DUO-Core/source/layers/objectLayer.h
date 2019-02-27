#include "Layer.h"
#include <SDL2/SDL.h>
#include <gameObject/DUO-GameObject.h>
#include <vector>

#pragma once

namespace DUO
{
    

    class objectLayer : public DUO::Layer
    {

    private:

        std::vector<DUO::gameObject*> objVect;

    public:

        objectLayer();

        virtual ~objectLayer();

        virtual void render(float) override;

        void addObject(DUO::gameObject* obj);

    };


} // DUO

