#ifndef APPLICATION_CTX
#define APPLICATION_CTX

#include "./app_models/root_model.hpp"
#include "logic/project/project.hpp"

class ApplicationCtx {
  public:
    LOGIC::Project *project;
    RootModel *root;
};

#endif // !APPLICATION_CTX
