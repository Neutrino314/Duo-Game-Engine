#include <DUO-Engine.h>
#include <memory>
#include <vector>

#include "panel.h"

void Editor::panel::update()
{

    for (const auto& obj : objectVect)
    {

        obj->update();

    }

};