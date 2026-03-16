#include "./project.hpp"
#include "logic/core/base_model.hpp"
#include "logic/models/dsensor.hpp"
#include <string>

using namespace LOGIC;

Project::Project() { models.push_back(new DSensor("main_sensor")); }

BaseModel *Project::get_node(std::string path) {
    for (auto model : models) {
        if (model->name == path) {
            return model;
        }
    }
    return nullptr;
}
