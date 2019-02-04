#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"

namespace DUO
{               
    
class userComponent : DUO::gameObject
{

private:

    DUO::gameObject* myObject = NULL;

public:

    userComponent(int ID, DUO::gameObjectComponent* newObj = NULL);

    virtual ~userComponent();

    virtual void update();

    virtual void setup();

};

} // DUO
