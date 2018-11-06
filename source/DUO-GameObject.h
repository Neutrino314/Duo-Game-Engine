#pragma once

namespace DUO {
    
class gameObject {

protected:

    int ID;

public:

    gameObject(int newID);

    int getID();
    void setID(int newID);

    void update() {};
    void addComponent() {};
    void removeComponent() {};
    void draw() {}

};

} // DUO