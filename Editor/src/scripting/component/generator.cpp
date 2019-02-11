#include <DUO-Engine.h>
#include "generator.h"

#include <string>
#include <fstream>

void Editor::compGen::newComp(std::string compName)
{

    std::string classDec = "class " + compName + " : public DUO::userComponent {";

    std::string lines[] = {"#include <DUO-Engine.h>", classDec, "private:", "public:", compName + "(int ID, DUO::gameObject* obj = NULL) : userComponent(ID, obj) {}", "virtual ~" + compName + "() {}", "virtual void setup() {}", "virtual void update() override {}", "virtual void load(DUO::gameObject* obj, std::size_t ID) override {}", "};", "extern \"C\"  DUO::userComponent* create_" + compName + "() {return new " + compName + "(0);}", "extern \"C\"  void destroy_" + compName + "(DUO::userComponent* u) {delete u;}"};

    std::string path = compName + ".cpp";

    std::ofstream ofs(path);

    for (const auto& line : lines)
    {

        ofs << line.c_str() << std::endl;

    }

}