#include <DUO-Engine.h>
#include "generator.h"

#include <string>
#include <fstream>

void Editor::compGen::newComp(std::string compName)
{

    std::string classDec = "class " + compName + " : public DUO::userComponent {";

    std::string lines[] = {"#include <DUO-Engine.h>\n", classDec + "\n", "private:\n", "public:\n", "\t" + compName + "(int ID, DUO::gameObject* obj = NULL) : userComponent(ID, obj) {}\n", "\tvirtual ~" + compName + "() {}\n", "\tvirtual void setup() {}\n", "\tvirtual void update() override {}\n", "\tvirtual void load(DUO::gameObject* obj, std::size_t ID) override {}\n", "};\n\n", "extern \"C\"  DUO::userComponent* create_" + compName + "() {return new " + compName + "(0);}", "extern \"C\"  void destroy_" + compName + "(DUO::userComponent* u) {delete u;}"};

    std::string path = compName + ".cpp";

    std::ofstream ofs(path);

    for (const auto& line : lines)
    {

        ofs << line.c_str() << std::endl;

    }

}