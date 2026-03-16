#include "./model_publisher.hpp"
#include "./model_subscriber.hpp"

using namespace LOGIC;

void ModelPublisher::subscribe_attr_changed(ModelSubscriber *subscriber) { attr_changed_channel.push_back(subscriber); }

void ModelPublisher::notify_attr_changed(int attr_id) {
    for (auto subcriber : attr_changed_channel) {
        subcriber->on_attr_changed(attr_id);
    }
}
