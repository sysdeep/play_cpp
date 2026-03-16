#ifndef LOGIC_MODEL
#define LOGIC_MODEL

namespace LOGIC {

class Attr {
  public:
    explicit Attr(int id) : id(id) {}
    int id;

    int get_int();
    void set_int(int value);

  private:
    int value_int{};
};
} // namespace LOGIC

#endif // !DEBUG
