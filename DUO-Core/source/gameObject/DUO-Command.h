#pragma once

namespace DUO
{

class Command
{

private:

    const char* myType;

public:

    Command();

    virtual ~Command();

    virtual void execute() {};

};

}