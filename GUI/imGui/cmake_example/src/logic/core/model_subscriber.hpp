#ifndef LOGIC_MODEL_SUBSCRIBER
#define LOGIC_MODEL_SUBSCRIBER

namespace LOGIC {
class ModelSubscriber {
  public:
    virtual void on_attr_changed(int attr_id) = 0;
};
} // namespace LOGIC

#endif // !DEBUG
