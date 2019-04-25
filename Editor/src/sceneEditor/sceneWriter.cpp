#include "sceneWriter.h"
#include <DUO-Engine.h>
#include <string>

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

Editor::sceneWriter::sceneWriter(std::string fileName) : m_fileName(fileName) {

    DUO::sceneParser reader(fileName);

    translateObjects(reader.getObjectDict());

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