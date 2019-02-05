#pragma once
#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include <yaml/parser.h>

namespace DUO
{               
    
class userComponent : public DUO::gameObjectComponent
{

protected:

    DUO::gameObject* myObj = NULL;

public:

    userComponent(int newID, DUO::gameObject* newObj = NULL);

    virtual ~userComponent();

    virtual void update() override;

    virtual void setup() override;

    virtual void load(DUO::gameObject* newObject, std::size_t ID);

};

typedef userComponent* createComp_t();
typedef void destroy_t(userComponent*);

} // DUO
