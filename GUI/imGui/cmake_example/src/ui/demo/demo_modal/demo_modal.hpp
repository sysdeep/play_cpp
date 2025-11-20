#ifndef DEMO_MODAL
#define DEMO_MODAL
#include "./child_demo_modal.hpp"
#include <map>
#include <set>

class DemoModal {
  private:
    std::map<int, ChildDemoModal *> childrens;
    std::set<int> modals{1};

  public:
    DemoModal(/* args */);
    // ~DemoModal();
    void draw();
};

#endif