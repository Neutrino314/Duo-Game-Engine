#include <DUO-Core/source/DUO-Engine.h>
#include <typeinfo>
#include <iostream>

int main() {

    std::cout << typeid(DUO::polygonRenderer).name() << std::endl;

    std::cout << "Linked succesefully\n";

    return 0;

}