#pragma once
#include <string>
#include <vector>

namespace docker {

//class ContainersParser
//{
//public:
//    ContainersParser();
//};

struct Container {
     std::string Id;
     std::string Image;
     std::string ImageID;
     std::vector<std::string> Names;
     std::string State;
     std::string Status;
};



Container parseContainer(const std::string &value);
std::vector<Container> parseContainers(const std::string &value);

}

