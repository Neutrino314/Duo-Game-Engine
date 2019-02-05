#include <DUO-Core/source/DUO-Engine.h>
#include <iostream>
#include <SDL2/SDL.h>

class movement : public DUO::userComponent
{

private:

    int xA;
    int yA;

public:

    movement(int ID, DUO::gameObject* obj = NULL) : userComponent(ID, obj)
    {}

    ~movement()
    {}

    virtual void setup() {

        std::cout << "setup\n";

    }

    virtual void load(DUO::gameObject* obj, std::size_t ID) override 
    {

        myObj = obj;
        myID = ID;

    }

    virtual void update() override {

        if (DUO::keyboard::isKeyDown(SDL_SCANCODE_A)) {

        xA = -8;

    } else if (DUO::keyboard::isKeyDown(SDL_SCANCODE_D)) {

        xA = 8;

    } else if (DUO::keyboard::isKeyUp(SDL_SCANCODE_A) && DUO::keyboard::isKeyUp(SDL_SCANCODE_D)) {

        xA = 0;

    }

    if (DUO::keyboard::isKeyDown(SDL_SCANCODE_W)) {

        yA = -8;

    } else if (DUO::keyboard::isKeyDown(SDL_SCANCODE_S)) {

        yA = 8;

    } else if (DUO::keyboard::isKeyUp(SDL_SCANCODE_W) && DUO::keyboard::isKeyUp(SDL_SCANCODE_S)) {

        yA = 0;

    }

        myObj->myVel.x = xA;
        myObj->myVel.y = yA;

    myObj->myTransform->pos.print();

    }

};

extern "C" DUO::userComponent* create_movement()
{

    return new movement(0);

}

extern "C" void destroy_movement(DUO::userComponent* u)
{

    delete u;

}