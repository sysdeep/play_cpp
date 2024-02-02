#ifndef LOGIC_MODEL_PUBLISHER
#define LOGIC_MODEL_PUBLISHER

#include "./model_subscriber.hpp"
#include <vector>

namespace LOGIC {
class ModelPublisher {
  public:
    void subscribe_attr_changed(ModelSubscriber *subscriber);
    void notify_attr_changed(int attr_id);

  private:
    std::vector<ModelSubscriber *> attr_changed_channel;
};
} // namespace LOGIC

#endif // !DEBUG
