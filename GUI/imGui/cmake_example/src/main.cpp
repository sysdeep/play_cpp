#include "application/application.hpp"
#include <spdlog/spdlog.h>

int main(int, char **) {

    spdlog::set_level(spdlog::level::debug); // Set *global* log level to debug
    // spdlog::info("INFO!!!!!");
    // spdlog::debug("INFO!!!!!");

    auto app = new Application();
    app->run();

    return 0;
}
