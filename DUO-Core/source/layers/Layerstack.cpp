#include "Layer.h"
#include "Layerstack.h"

#include <vector>
#include <iterator>
#include <algorithm>

DUO::LayerStack::LayerStack()
{

    

}

DUO::LayerStack::~LayerStack()
{

    //loops through each layer in the stack and deletes them
    for (Layer* element : m_layerStack)
    {

        delete element;

    }

}

void DUO::LayerStack::pushLayer(DUO::Layer* layer)
{

    m_layerStack.emplace_back(layer);

}

void DUO::LayerStack::popLayer(DUO::Layer* layer)
{

    auto it = std::find(m_layerStack.begin(), m_layerStack.end(), layer);

    if (it != m_layerStack.end())
    {

        m_layerStack.erase(it);

    }

}