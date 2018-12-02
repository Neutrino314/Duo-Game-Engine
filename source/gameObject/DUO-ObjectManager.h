#pragma once

#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-Utils.h"
#include <memory>
#include <typeinfo>

namespace DUO {

    class objectManager {

    public:

        template <typename T>
        static bool objectHasComp(DUO::gameObject* obj);

        static void addComp();

    };

}