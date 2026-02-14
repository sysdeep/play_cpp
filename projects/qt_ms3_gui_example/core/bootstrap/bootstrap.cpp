#include "bootstrap.hpp"
#include "lib/service_locator.hpp"
#include "services/glog/iglog.hpp"
#include "services/glog/glog.hpp"
#include "services/user/user.hpp"

Bootstrap::Bootstrap()
{
    ServiceLocator::registerService<IGLog>(std::make_shared<GLog>());
    ServiceLocator::registerService<IUser>(std::make_shared<User>());
}