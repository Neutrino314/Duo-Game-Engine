#include <functional>
#include <runtime/DUO-application.h>
#include <maths/DUO-Vector2.h>
#include <maths/DUO-AABB.h>
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include <SDL2/SDL.h>

namespace DUO {

// button componments

    class buttonComp : public DUO::gameObjectComponent {

    private:

        DUO::AABB myHitBox{0, 0, 10, 10};

        bool isPressed() {

            if (DUO::application::getEvent()->type == SDL_MOUSEBUTTONDOWN || DUO::application::getEvent()->type == SDL_MOUSEBUTTONUP) {

                if (myHitBox.pointInThis(DUO::application::getMousePos())) {

                    return true;

                }

            }

            return false;

        }

    public:

        virtual void update() override {



        };

    };


    
}