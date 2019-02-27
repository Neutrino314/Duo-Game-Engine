#pragma once

#include "Layer.h"

#include <vector>
#include <iterator>

namespace DUO
{

class LayerStack
{

public:

    LayerStack(); //default constructor

    ~LayerStack(); //destructor

    void pushLayer(Layer* layer); //pushes a layer to the "stack"

    void popLayer(Layer* layer); //pops layer at the top of the stack and returns

    std::vector<Layer*>::iterator begin() {return m_layerStack.begin();}

    std::vector<Layer*>::iterator end() {return m_layerStack.end();}

private:
    
    std::vector<Layer*> m_layerStack;

};

}