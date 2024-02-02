#include "./dsensor_proto.hpp"
#include "./dsensor_vm.hpp"

using namespace UI;

DSensorProto::DSensorProto(DSensorVM *view) : view(view) {}

void DSensorProto::on_attr_changed(int attr_id) {
    if (attr_id == 1) {
        int attr_value = model->get_attr_value(attr_id);
        this->view->set_light_state(attr_value > 0);
    }
}

void DSensorProto::set_model(LOGIC::BaseModel *model) {
    this->model = model;
    this->model->subscribe_attr_changed(this);
}
