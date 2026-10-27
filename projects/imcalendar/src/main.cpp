#include <ctime>
#include <iostream>

#include "application/application.hpp"
#include "argparse/argparse.hpp"
#include "version.hpp"

int main(int argc, const char *const *argv)
{

    // argparse ---------------------------------------------------------------
    argparse::ArgumentParser program("imcalendar", PROJECT_VERSION);

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    // application ------------------------------------------------------------
    auto app = new Application();
    app->run();

    return 0;
}
