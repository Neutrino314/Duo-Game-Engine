#pragma once

#include <string>

#include <DUO-Engine.h>

#include <project/project.h>

namespace DUO
{

    class editor
    {

    private:

        DUO::project curProject();

        void startPage();

        void editProject();

    public:

        editor();

        void run();

    };

} // DUO
