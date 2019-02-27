#include <DUO-Engine.h>
#include <bitset>
#include <memory>
#include <vector>

#pragma once

namespace Editor
{

    enum class PANEL_FLAGS
    {

        VISIBLE

     };

    class panel : DUO::gameObject
    {

    public:

        panel();

        ~panel() {};

        virtual void update();

    private:

        std::vector<std::unique_ptr<DUO::UIObject>> objectVect;

        DUO::vector2 dimensions{1.0f, 1.0f};

        DUO::vector2 position{0.0f, 0.0f};

    };



}