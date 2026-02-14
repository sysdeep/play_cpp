#include "glog.hpp"
#include <iostream>

GLog::GLog() : IGLog() {}

void GLog::do_log(const std::string msg)
{
    std::cout << "glog - " << msg << std::endl;
}
