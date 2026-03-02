#pragma once
#include <string>
#include <vector>
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"

class AboutPage : public DrawablePage
{
public:
    AboutPage(UIState *state);

    void draw() override;

private:
    UIState *state;

    struct WThirdPartyLibrary
    {
        std::string Name;
        std::string Url;
        std::string LicenseText;

        WThirdPartyLibrary(std::string Name_, std::string Url_, std::string LicenseText_)
            : Name(std::move(Name_)), Url(std::move(Url_)), LicenseText(std::move(LicenseText_))
        {
        }
    };

    std::vector<WThirdPartyLibrary> ThirdPartyLibraries;
};