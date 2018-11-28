#include "DUO-Engine.h"
#include "userComponents.h"
#include <stdio.h>
#include <iostream>

DUO::ballComponent::ballComponent(int newID, DUO::gameObject* newObject, DUO::transformComponent* newTransform, DUO::gameObject* newPaddle1, DUO::gameObject* newPaddle2) : 
    gameObjectComponent(newID, newObject), myTransform(newTransform), paddle1(newPaddle1), paddle2(newPaddle2) {

        myType = DUO::BASE;
        velocity.setVector(8, 0);

}

void DUO::ballComponent::setup() {

    std::cout << "Enter the maximum score: ";
    std::cin >> maxScore;

}

void DUO::ballComponent::update() {

    //collision code-----------------------------------------------------------------------

    if (myTransform->getPosition().getYComponent() - 25 <= 0) {

        velocity.setYComponent(4.0);

    } else if (myTransform->getPosition().getYComponent() + 25 >= 600) {

        velocity.setYComponent(-4.0);

    }

    //paddle 1------------------------------------------------------------------------------------------------------

    if (myTransform->getPosition().getXComponent() < 400) {

        if (myTransform->getPosition().getYComponent() + 25 > paddle1->getTransform()->getPosition().getYComponent() - 75 && myTransform->getPosition().getYComponent()  + 25 < paddle1->getTransform()->getPosition().getYComponent()) {


            if (myTransform->getPosition().getXComponent() - 25 < paddle1->getTransform()->getPosition().getXComponent() + 25 && myTransform->getPosition().getXComponent() - 25 > paddle1->getTransform()->getPosition().getXComponent()) {

                velocity.setVector(8, -4);

            }
            
        } else if (myTransform->getPosition().getYComponent() - 25 > paddle1->getTransform()->getPosition().getYComponent() && myTransform->getPosition().getYComponent() < paddle1->getTransform()->getPosition().getYComponent() + 75) {

            if (myTransform->getPosition().getXComponent() - 25 < paddle1->getTransform()->getPosition().getXComponent() + 25 && myTransform->getPosition().getXComponent() - 25 > paddle1->getTransform()->getPosition().getXComponent()) {

                velocity.setVector(8, 4);

            }
            
        }

        if (myTransform->getPosition().getYComponent() - 25 > paddle1->getTransform()->getPosition().getYComponent() - 50 && myTransform->getPosition().getYComponent() + 25 < paddle1->getTransform()->getPosition().getYComponent() + 50) {

            if (myTransform->getPosition().getXComponent() - 25 < paddle1->getTransform()->getPosition().getXComponent() + 25 && myTransform->getPosition().getXComponent() - 25 > paddle1->getTransform()->getPosition().getXComponent()) {

                velocity.setVector(8, 4);

            }

        }

    //paddle 2-----------------------------------------------------------------------------------------------------

    } else if (myTransform->getPosition().getXComponent() > 400) {

        if (myTransform->getPosition().getYComponent() + 25 > paddle2->getTransform()->getPosition().getYComponent() - 75 && myTransform->getPosition().getYComponent()  + 25 < paddle2->getTransform()->getPosition().getYComponent()) {

            if (myTransform->getPosition().getXComponent() + 25 > paddle2->getTransform()->getPosition().getXComponent() - 25 && myTransform->getPosition().getXComponent() - 25 < paddle2->getTransform()->getPosition().getXComponent()) {

                velocity.setVector(-8, -4);

            }
            
        } else if (myTransform->getPosition().getYComponent() - 25 > paddle2->getTransform()->getPosition().getYComponent() && myTransform->getPosition().getYComponent() < paddle2->getTransform()->getPosition().getYComponent() + 75) {

            if (myTransform->getPosition().getXComponent() + 25 > paddle2->getTransform()->getPosition().getXComponent() - 25 && myTransform->getPosition().getXComponent() - 25 < paddle2->getTransform()->getPosition().getXComponent()) {

                velocity.setVector(-8, 4);

            }
            
        }

        if (myTransform->getPosition().getYComponent() - 25 > paddle2->getTransform()->getPosition().getYComponent() - 50 && myTransform->getPosition().getYComponent() + 25 < paddle2->getTransform()->getPosition().getYComponent() + 50) {

            if (myTransform->getPosition().getXComponent() + 25 > paddle2->getTransform()->getPosition().getXComponent() - 25 && myTransform->getPosition().getXComponent() - 25 < paddle2->getTransform()->getPosition().getXComponent()) {

                velocity.setVector(-8, 0);

            }

        }

    }

    //scoring code----------------------------------------------------------------------------

    if (timer == 0) {

        if (myTransform->getPosition().getXComponent() - 25 <= 0) {

            score.increment(0, 1);
            velocity.setVector(8, 0);
            myTransform->setPosition(400, 300);
            timer = waitTime;

        } else if (myTransform->getPosition().getXComponent() + 25 >= 800) {

            score.increment(1, 0);
            velocity.setVector(-8, 0);
            myTransform->setPosition(400, 300);
            timer = waitTime;

        }

        myTransform->translate(velocity.getXComponent(), velocity.getYComponent());

    } else if (timer > 0) {

        timer--;

    }

    std::cout << score.getXComponent() << " - " << score.getYComponent() << std::endl;

}

DUO::ballRenderer::ballRenderer(int newID, DUO::gameObject* newObject, double radius, int r, int g, int b) :
renderComponent(newID, newObject, radius, 0), R(r), G(g), B(b) {

    myType = DUO::RENDERER;

}

void DUO::ballRenderer::update() {

    DUO::fillCircle(myTransform->getPosition().getXComponent(), myTransform->getPosition().getYComponent(), dimensions.getXComponent(), R, G, B, myObject->getRenderer());

}


DUO::paddleController::paddleController(int newID, DUO::gameObject* newObject, SDL_Scancode newUp, SDL_Scancode newDown, DUO::transformComponent* newTransform) :
    gameObjectComponent(newID, newObject), upKey(newUp), downKey(newDown), myTransform(newTransform) {

        myType = DUO::BASE;

}

void DUO::paddleController::update() {

    if (DUO::keyboard::isKeyDown(upKey)) {

        yA = -6;

    }

    if (DUO::keyboard::isKeyDown(downKey)) {

        yA = 6;

    } 

    if (DUO::keyboard::isKeyUp(upKey) && DUO::keyboard::isKeyUp(downKey)) {

        yA = 0;

    }

    myTransform->translate(0, yA);

    if (myTransform->getPosition().getYComponent() + 75 >= 600) {

        myTransform->setPosition(myTransform->getPosition().getXComponent(), 525);

    } else if (myTransform->getPosition().getYComponent() - 75 <= 0) {

        myTransform->setPosition(myTransform->getPosition().getXComponent(), 75);   

    }

}

DUO::paddleRenderer::paddleRenderer(int newID, DUO::gameObject* newObject, double width, double height, int r, int g, int b) : 
    renderComponent(newID, newObject, width, height), R(r), G(g), B(b){

        myType = DUO::RENDERER;
        myTransform = myObject->getTransform();

}

void DUO::paddleRenderer::update() {

    DUO::fillRect(myTransform->getPosition().getXComponent(), myTransform->getPosition().getYComponent(), 0, R, G, B, myObject->getRenderer(), dimensions.getXComponent(), dimensions.getYComponent());

}