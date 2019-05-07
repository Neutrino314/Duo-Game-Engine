#include <DUO-Engine.h>
#include <string>

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

yamlObject generateCamera();

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

    int m_curID{1};

    void refreshID();

    void translateObjects(std::map<std::size_t, std::vector<std::string>>& objectMap); //translates the object dictionary provided by the yaml parser to yamlObject instances

public:

    sceneWriter(std::string fileName); 
    ~sceneWriter();

    void addGameObject(); //adds a game object to the scene tree

    void removeGameObject(int objectID); //removes an object from the scene tree

    void addComp(yamlObject& object, int ID); //adds a component to the current last game object in the tree

    void removeComp(int objID, int compID); //removes a component from the scene tree

    bool saveScene(); //saves the scene to the specified file name

};

} // Editor
