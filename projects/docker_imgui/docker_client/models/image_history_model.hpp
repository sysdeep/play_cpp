#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    /*
    {
        "Comment": "",
        "Created": 1620348653,
        "CreatedBy": "/bin/sh -c #(nop)  ENTRYPOINT [\"entrypoint.sh\" \"docker-php-entrypoint\"]",
        "Id": "<missing>",
        "Size": 0,
        "Tags": null
    }

    {
        "Comment": "",
        "Created": 1620348654,
        "CreatedBy": "/bin/sh -c #(nop)  EXPOSE 8080",
        "Id": "sha256:365268e7ce469d5474b0f544ba2995f9f95f06ae28ede5d02f307f693a36783a",
        "Size": 0,
        "Tags": [
        "registry.lan:5000/adminer:4.8.0-standalone"
        ]
    },
    */
    struct ImageHistoryModel
    {
        std::string Id;
        std::string CreatedBy;
        uint64_t Created;
        uint64_t Size;
        std::vector<std::string> Tags;
    };

}