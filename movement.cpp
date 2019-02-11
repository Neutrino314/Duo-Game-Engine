#include <DUO-Engine.h>
class movement : public DUO::userComponent {
private:
public:
movement(int ID, DUO::gameObject* obj = NULL) : userComponent(ID, obj) {}
virtual ~movement() {}
virtual void setup() {}
virtual void update() override {}
virtual void load(DUO::gameObject* obj, std::size_t ID) override {}
};
extern "C"  DUO::userComponent* create_movement() {return new movement(0);}
extern "C"  void destroy_movement(DUO::userComponent* u) {delete u;}
