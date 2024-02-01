#ifndef LOGIC_BASE_MODEL
#define LOGIC_BASE_MODEL

#include <string>
#include <vector>
namespace LOGIC {

struct Attr {
    int id;
    std::string name;
    int value;
};

class BaseModel {

  public:
    // explicit BaseModel(std::vector<Attr *> attrs) : attrs(std::move(attrs)) {}
    // BaseModel();
    int get_attr_value(int id);
    void set_attr_value(int id, int value);

  protected:
    std::vector<Attr *> attrs;
};

} // namespace LOGIC

#endif // !LOGIC_BASE_MODEL
