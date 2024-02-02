#ifndef LOGIC_BASE_MODEL
#define LOGIC_BASE_MODEL

#include "./attr.hpp"
#include "./model_publisher.hpp"
#include <vector>

namespace LOGIC {

class BaseModel : public ModelPublisher {

  public:
    // explicit BaseModel(std::vector<Attr *> attrs) : attrs(std::move(attrs)) {}
    // BaseModel();
    Attr *get_attr(int id);
    int get_attr_value(int id);
    void set_attr_value(int id, int value);

  protected:
    std::vector<Attr *> attrs;
};

} // namespace LOGIC

#endif // !LOGIC_BASE_MODEL
