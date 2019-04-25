#include <DUO-Engine.h>

namespace Editor
{
/*

This class is responsible for creating valid yaml files that will be read and edited by the editor and
scenemanager during the loading phase.

*/

struct yamlObject { //a representation of yaml objects

    std::string objType;
    std::map<std::string, std::string> elements;

};

struct sceneTree
{

    std::vector<DUO::treeNode<yamlObject>> sceneGraph;

};


void printYamlObject(yamlObject& object);

void translateAttributes(yamlObject& object, std::vector<std::string>& rawAttrs);

class sceneWriter
{
private:
    
    sceneTree m_sceneGraph;

    std::string m_fileName;

    void translateObjects(std::map<std::size_t, std::vector<std::string>>& objectMap); //translates the object dictionary provided by the yaml parser to yamlObject instances

public:

    sceneWriter(std::string fileName);
    ~sceneWriter();

    void addGameObject();

    void removeGameObject(std::size_t objectID);

    void addComp();

    void removeComp(std::size_t compID);

    bool saveScene();

};

} // Editor
