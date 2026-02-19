#include "params_builder.hpp"

ParamsBuilder::ParamsBuilder() {}

ParamsBuilder *ParamsBuilder::add(std::string key, std::string value)
{
    this->params.push_back(std::make_pair(key, value));
    return this;
}

std::string ParamsBuilder::build()
{
    std::string res = "";
    bool first = false;
    for (auto pair : this->params)
    {
        if (!first)
        {
            res += "&";
        }
        else
        {
            first = true;
        }

        res += pair.first + "=" + pair.second;
    }
    return res;
}
