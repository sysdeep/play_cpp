#include "params_builder.hpp"

using namespace docker;

ParamsBuilder::ParamsBuilder() {}

ParamsBuilder *ParamsBuilder::add(std::string key, std::string value)
{
    this->params.push_back(std::make_pair(key, value));
    return this;
}

std::string ParamsBuilder::build()
{
    std::string res = "";
    const std::string delim = "&";

    for (size_t i = 0; i < params.size(); ++i)
    {
        auto pair = params[i];
        res += pair.first + "=" + pair.second;
        if (i + 1 < params.size())
            res += delim;
    }

    // bool first = false;
    // for (auto pair : this->params)
    // {
    //     res += pair.first + "=" + pair.second;

    //     if (!first)
    //     {
    //         res += "&";
    //     }
    //     else
    //     {
    //         first = true;
    //     }
    // }
    return res;
}
