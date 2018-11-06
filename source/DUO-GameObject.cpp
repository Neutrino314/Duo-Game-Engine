#include "DUO-GameObject.h"

DUO::gameObject::gameObject(int newID) : ID(newID) {



};

int DUO::gameObject::getID() {return ID;};

void DUO::gameObject::setID(int newID) {ID = newID;};