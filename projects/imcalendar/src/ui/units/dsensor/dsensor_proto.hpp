#ifndef UI_DSENSOR_PROTO
#define UI_DSENSOR_PROTO

#include "./dsensor_vm.hpp"
#include "logic/core/base_model.hpp"
#include "logic/core/model_subscriber.hpp"

namespace UI {
class DSensorProto : public LOGIC::ModelSubscriber {
  public:
    DSensorProto(DSensorVM *);
    void set_model(LOGIC::BaseModel *model);

  private:
    DSensorVM *view;
    LOGIC::BaseModel *model = nullptr;
    void on_attr_changed(int attr_id) override;
};

} // namespace UI

#endif // !DEBUG
