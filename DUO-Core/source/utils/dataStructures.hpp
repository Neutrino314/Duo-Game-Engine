#pragma once

#include <memory>
#include <vector>
#include <iostream>

namespace DUO
{

//implementation of a tree data structure ----------------------------------------------------------------------------

template <typename T> //tree node of type T
class treeNode
{

private:

    T data;
    
    treeNode& parent = NULL;

    std::vector<treeNode<T>> children;

    bool m_hasChildren{false}, m_hasParent{false};

public:

    treeNode(T newData) : data(newData) {



    }

    ~treeNode() {

        if (hasChildren()) {

            children.clear();

        }

        std::cout << "deleting  myself\n";

    };

    void appendChild(T data) {

        children.emplace_back(treeNode<T>{data});

        m_hasChildren = true;

    };

    void setParent(treeNode<T>& newParent) {

        m_hasParent = true;

        parent = newParent;

    };

    treeNode<T>& getParent() const {return parent;};

    treeNode<T>& getChild(std::size_t childID) const {

        if (childID > children.size() - 1 || !m_hasChildren) {

            return nullptr;

        } else {

            return children[childID];

        }

    };

    treeNode<T>& getLastChild() const {

        if (!m_hasChildren) {

            return nullptr;

        } else
        {
            return children.back();
        }
        
    }

    void deleteChild(int childID) {

        if (childID > children.size() - 1 || !hasChildren()) {

            return;

        }

        children.erase(children.begin() + childID);

    };

    bool hasChildren() const {return m_hasChildren;};

    bool hasParent() const {return m_hasParent;};

    T& getData() {return data;}

};


} // DUO
