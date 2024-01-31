#include "./dsensor_gmodal.hpp"
#include "ui/gmodals//frames/dsensor.hpp"
#include "ui/gmodals/modals/base_gmodal.hpp"

using namespace UI::GMODALS;

DSensorGmodal::DSensorGmodal() : BaseGmodal() { this->frame = new DSensor(); }
