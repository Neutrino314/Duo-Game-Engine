#pragma once
#include "DUO-Engine.h"


namespace DUO {

    class ballComponent : public DUO::gameObjectComponent {

    private:

        DUO::vector velocity{0.0, 0.0};
        DUO::transformComponent* myTransform = NULL;
        DUO::vector score{0.0, 0.0};
        int timer{100};
        int waitTime{30};
        int maxScore{0};

        DUO::gameObject* paddle1;
        DUO::gameObject* paddle2;

    public:

        ballComponent(int newID, DUO::gameObject* newObject, DUO::transformComponent* newTransform, DUO::gameObject* newPaddle1, DUO::gameObject* newPaddle2);

        virtual void update() override;
        virtual void setup() override;

    };

    class ballRenderer :public DUO::renderComponent {

    private:

        int R, G, B;

    public:

        ballRenderer(int newID, DUO::gameObject* newObject, double radius, int r, int g, int b);

        virtual void update() override;

    };

    class paddleController : public DUO::gameObjectComponent {

    private:

        short yA{0};
        SDL_Scancode upKey;
        SDL_Scancode downKey;
        DUO::transformComponent* myTransform = NULL;

    public:

        paddleController(int newID, DUO::gameObject* newObject, SDL_Scancode newUp, SDL_Scancode newDown, DUO::transformComponent* newTransform);

        virtual void update() override;

    };

    class paddleRenderer : public DUO::renderComponent {

    private:

        int R, G, B;

    public:

        paddleRenderer(int newID, DUO::gameObject* newObject, double width, double height, int r, int g, int b);

        virtual void update() override;

    };
    
}

