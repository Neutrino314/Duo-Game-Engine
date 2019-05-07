#include "sceneWriter.h"
#include <DUO-Engine.h>
#include <string>
#include <fstream>

void Editor::printYamlObject(Editor::yamlObject& object) {

    std::cout << object.objType << std::endl;

    for (const auto& attribute : object.elements) {

        std::cout << attribute.first << " : " << attribute.second << std::endl;

    }

}

void Editor::translateAttributes(Editor::yamlObject& object, std::vector<std::string>& rawAttribs) {

    std::vector<std::string> splitAttributes;

    for (const auto attribute : rawAttribs) {

        splitAttributes = DUO::splitFirst(':', attribute);

        object.elements[splitAttributes[0]] = splitAttributes[1];

    }

}

Editor::yamlObject Editor::generateCamera() {

    return yamlObject{"camera", {{"hasTarget", "0"}, {"targetID", "0"}, {"origin", "{x: 0f, y: 0f}"}}};

}

Editor::sceneWriter::sceneWriter(std::string fileName) : m_fileName(fileName) {

    DUO::sceneParser reader(fileName);

    translateObjects(reader.getObjectDict());

    if (m_sceneGraph.sceneGraph.size() > 0) {

        return;

    } else
    {

        m_sceneGraph.sceneGraph.emplace_back(DUO::treeNode<yamlObject>{generateCamera()});

    }
    

}

void Editor::sceneWriter::translateObjects(std::map<std::size_t, std::vector<std::string>>& objectMap) {

    for (auto& ID : objectMap) { //iterates through the keys in the objectMap

        if (ID.second[0] == "camera") { //if the object is of type camera then 
            
            ID.second.erase(ID.second.begin());

            m_sceneGraph.sceneGraph.emplace_back(DUO::treeNode<yamlObject>{yamlObject{"camera"}});

            Editor::translateAttributes(m_sceneGraph.sceneGraph.back().getData(), ID.second);

        } else if (ID.second[0] == "gameObject") {

            ID.second.erase(ID.second.begin());

            m_sceneGraph.sceneGraph.emplace_back(DUO::treeNode<yamlObject>{yamlObject{"gameObject"}});

            Editor::translateAttributes(m_sceneGraph.sceneGraph.back().getData(), ID.second);

        } else {

            m_sceneGraph.sceneGraph.back().appendChild(yamlObject{ID.second[0]});

            ID.second.erase(ID.second.begin());

            Editor::translateAttributes(m_sceneGraph.sceneGraph.back().getLastChild().getData(), ID.second);

        }

    }

}

void Editor::sceneWriter::addGameObject() {

    m_sceneGraph.sceneGraph.emplace_back(DUO::treeNode<yamlObject>{yamlObject{"gameObject", {{"myID", std::to_string(m_curID)}, {"myVel", "{x: 0.0f, y: 0.0f}"}}}});

    m_sceneGraph.sceneGraph.back().appendChild(yamlObject{"Transform", {{"position", "{x: 0.0f, y: 0.0f}"}, {"scale", "{x: 1.0f, y: 1.0f}"}, {"rotation", "0.0f"}, {"parent", std::to_string(m_curID + 1)}}});

    m_curID += 2;

}

void Editor::sceneWriter::removeGameObject(int objectID) {

    if (!(objectID > 0 && objectID < m_sceneGraph.sceneGraph.size())) {

        return;

    } else
    {
        
        m_sceneGraph.sceneGraph.erase(m_sceneGraph.sceneGraph.begin() + objectID);

    }
    
}

void Editor::sceneWriter::addComp(Editor::yamlObject& object, int ID) {

    m_sceneGraph.sceneGraph.back().appendChild(object);

}

void Editor::sceneWriter::removeComp(int objID, int compID) {

    if (objID > 0 && objID < m_sceneGraph.sceneGraph.size()) {

        if (compID > m_sceneGraph.sceneGraph[objID].getChildAmount() - 1) {

            m_sceneGraph.sceneGraph[objID].deleteChild(compID);

        }

    }

    return;

}

bool Editor::sceneWriter::saveScene() {

    std::ofstream ofs(m_fileName, std::ios::trunc);

    int curID{0};

    for (auto& object : m_sceneGraph.sceneGraph) {

        ofs << "--- &" << curID << std::endl;

        Editor::yamlObject temp{object.getData()};

        ofs << temp.objType.c_str() << ":\n";

        

    }
}