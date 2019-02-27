#include <DUO-Engine.h>

#include <vector>
#include <string>

namespace DUO
{

    enum class assetTypes { 

        COMPONENT,
        COMMAND,
        IMAGE,
        SCENE

    };

    class assetManager
    {

    private:

        

    public:

        assetManager(std::string assetPath);

        void addAsset(std::string path, assetTypes assetType, std::string name);

        void removeAsset(std::string name, std::string id);

        void editAsset(std::string path);

    };

}