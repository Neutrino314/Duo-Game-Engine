#include "DUO-Command.h"

#include <typeinfo>

DUO::Command::Command()
{

    myType = typeid(this).name();

}

DUO::Command::~Command()
{

    delete myType;
    myType = nullptr;

}

