#include "defaultLayer.h"
#include <gameObject/DUO-Scene.h>
#include <gameObject/DUO-SceneManager.h>
#include <layers/Layer.h>

#include <SDL2/SDL.h>

void DUO::defaultLayer::update()
{

    DUO::sceneManager::curScene->update();

}

void DUO::defaultLayer::render(float interpolation)
{

    DUO::sceneManager::curScene->draw(interpolation);

}