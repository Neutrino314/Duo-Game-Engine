#include <DUO-Engine.h>

#include <vector>
#include <string>

namespace DUO
{

    class assetManager
    {

    private:

        

    public:

        assetManager(std::string assetPath);

        void addAsset(std::string path, std::string type, std::string name);

        void removeAsset(std::string name, std::string id);

        void editAsset(std::string path);

    };

}