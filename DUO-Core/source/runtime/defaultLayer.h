#pragma once

#include <gameObject/DUO-Scene.h>
#include <gameObject/DUO-SceneManager.h>
#include <layers/Layer.h>

namespace DUO
{

class defaultLayer : public Layer
{

private:

public:

    defaultLayer() : Layer() {}

    virtual ~defaultLayer() override {};

    virtual void update() override;

    virtual void render(float interpolation) override;

};

} // DUO
