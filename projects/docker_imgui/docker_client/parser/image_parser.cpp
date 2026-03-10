#include "rapidjson/document.h"
#include "image_parser.hpp"
#include "parser_utils.hpp"

using namespace docker;
ImageModel parser::parseImage(const std::string &src)
{
    rapidjson::Document document;
    document.Parse(src.c_str());

    ImageModel result{};

    // Id
    result.Id = processString(document, "Id", "Error");

    // RepoTags
    if (document.HasMember("RepoTags"))
    {
        if (document["RepoTags"].IsArray())
        {
            for (auto const &val : document["RepoTags"].GetArray())
            {
                if (val.IsString())
                {
                    std::string res(val.GetString(), val.GetStringLength());
                    result.RepoTags.push_back(std::move(res));
                }
            }
        }
    }

    // Size
    result.Size = processUint64If(document, "Size", 0);

    // Config
    if (document.HasMember("Config"))
        result.Config = parseImageConfig(document["Config"]);

    return result;
}

ImageConfigModel parser::parseImageConfig(const rapidjson::Value &value)
{

    ImageConfigModel result{
        processStringsList(value, "Cmd"),        // Cmd
        processStringsList(value, "Entrypoint"), // Entrypoint
    };

    // // Cmd
    // if (value.HasMember("Cmd"))
    // {
    //     if (value["Cmd"].IsArray())
    //     {
    //         for (auto const &val : value["Cmd"].GetArray())
    //         {
    //             if (val.IsString())
    //             {
    //                 std::string res(val.GetString(), val.GetStringLength());
    //                 result.Cmd.push_back(std::move(res));
    //             }
    //         }
    //     }
    // }

    return result;
}

/*
{
    "Architecture":"amd64",
    "Config":{
        "Cmd":["php","-S","[::]:8080","-t","/var/www/html"],
        "Entrypoint":["entrypoint.sh","docker-php-entrypoint"],
        "Env":[
            "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
            "PHPIZE_DEPS=autoconf \t\tdpkg-dev dpkg \t\tfile \t\tg++ \t\tgcc \t\tlibc-dev \t\tmake \t\tpkgconf \t\tre2c",
            "PHP_INI_DIR=/usr/local/etc/php",
            "PHP_CFLAGS=-fstack-protector-strong -fpic -fpie -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64",
            "PHP_CPPFLAGS=-fstack-protector-strong -fpic -fpie -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64",
            "PHP_LDFLAGS=-Wl,-O1 -pie",
            "GPG_KEYS=42670A7FE4D0441C8E4632349E4FDC074A4EF02D 5A52880781F755608BF815FC910DEB46F53EA312",
            "PHP_VERSION=7.4.19",
            "PHP_URL=https://www.php.net/distributions/php-7.4.19.tar.xz",
            "PHP_ASC_URL=https://www.php.net/distributions/php-7.4.19.tar.xz.asc",
            "PHP_SHA256=6c17172c4a411ccb694d9752de899bb63c72a0a3ebe5089116bc13658a1467b2",
            "ADMINER_VERSION=4.8.0",
            "ADMINER_DOWNLOAD_SHA256=e274268e0e0f2a6b8040c000a969889062904ae7a5ccbaf013dc890e12e32eaa",
            "ADMINER_SRC_DOWNLOAD_SHA256=55b52851faa5661667edb003b00cf520ebeb1e41cfcea4a7fc028ed0f55ff557"
        ],
        "ExposedPorts":{"8080/tcp":{}},"StopSignal":"SIGINT","User":"adminer","WorkingDir":"/var/www/html"},
        "Created":"2021-05-07T00:50:54.226770973Z",
        "DockerVersion":"19.03.12",
        "GraphDriver":{"Data":{"LowerDir":"/home/var/lib/docker/overlay2/ac86684c71e5ff9609160ba5c6872e61480864e7e37ee552440c75f25ca1d625/diff:/home/var/lib/docker/overlay2/7466140fb3fc778ca455ead52216bf99b01edd60aa4b374eaa20014745076ec0/diff:/home/var/lib/docker/overlay2/3a9d56fa97f2208df6a8bddfc5885873ffcaf268a6dc3b53185b6b67b0139b2f/diff:/home/var/lib/docker/overlay2/640cd5b70bb55859abbcdb027f9ac442302b9785bedcdbbae9e29341f6632897/diff:/home/var/lib/docker/overlay2/157fff212a08b7ae249711c8ac2d9c8e9628b9ae706fab1dc871dde69c1fe9a3/diff:/home/var/lib/docker/overlay2/8a69292e509224f361e5c59a83adf05ba8fa8aca2993a027bcfa4cbeea9ff949/diff:/home/var/lib/docker/overlay2/a54d5ce85cb3d9460efd160690ff509c3dbde6554c64fef7695b04ed44ab0d60/diff:/home/var/lib/docker/overlay2/bb93ea7a41b5aee10458acde7ba21ec31270198b2222b1639107133161cff237/diff:/home/var/lib/docker/overlay2/1a7e4a71d39f40990e0d15f0e462bbddd54d9adedfa46e34e9b3b51a76df7df9/diff:/home/var/lib/docker/overlay2/d44d997f527bede84b19e1ed65bebeb8a523d495b9df3ede1e3906dbe6dbb90c/diff:/home/var/lib/docker/overlay2/316456d478bca9b5f739bd48727d6ea015e81610a626d3c08da516a36420133b/diff:/home/var/lib/docker/overlay2/a69abbceb1a545acce414fda6d3b646cc8c85847a7e99384cf28267cb18c3f07/diff:/home/var/lib/docker/overlay2/caa3fa686bfda2a47e5fdb564ec2e95fb0f30db62a4c1ae67c6fd884d9232507/diff:/home/var/lib/docker/overlay2/51960965d43eef9dfac1444839e79eb6edbb3312c936435836096662b26168ca/diff","MergedDir":"/home/var/lib/docker/overlay2/ea5e6fa492610708bc325e0c649dd6ddd89998974fa0159821843d4516cb3cee/merged","UpperDir":"/home/var/lib/docker/overlay2/ea5e6fa492610708bc325e0c649dd6ddd89998974fa0159821843d4516cb3cee/diff","WorkDir":"/home/var/lib/docker/overlay2/ea5e6fa492610708bc325e0c649dd6ddd89998974fa0159821843d4516cb3cee/work"},"Name":"overlay2"},
        "Id":"sha256:365268e7ce469d5474b0f544ba2995f9f95f06ae28ede5d02f307f693a36783a",
        "Metadata":{"LastTagTime":"0001-01-01T00:00:00Z"},
        "Os":"linux",
        "RepoDigests":[],
        "RepoTags":["registry.lan:5000/adminer:4.8.0-standalone"],
        "RootFS":{"Layers":["sha256:b2d5eeeaba3a22b9b8aa97261957974a6bd65274ebd43e1d81d0a7b8b752b116","sha256:1ddf5e956d14a0d33c2883b274ea9580a60127b6f4be62042cdfadc2077759eb","sha256:c8ddbd995ae0043bccdcb6e4d55d062494c87aec2effc39a16b5814506ec48d1","sha256:e46056cfc8a0b74ee2a222a2d1df560d59e32ac86e7ee5b1f2b1ed4893916376","sha256:14bf55039dec30427455d83c10200c03caf93086a7670a24268f64165917d4af","sha256:298e886ba5be0e7c49fd04f7cc67ba4fe05fd7bc45a7235f857190484b0b3ad1","sha256:23aefe3e079629101b5be00a505dba62cf2eaa55c35273f695ed4091110ea5dc","sha256:f66c290df14193c4a7dec7f57334a39e3ddec93905135441f3df9a7491c3364a","sha256:76340f9d7a436c3f9fd7c52d21318ef99cb7aef8a0e4a48399ccf0d3abe15927","sha256:c356218d0abc669e44001a46f480d38a6772bc9138386bacc04e189b212e8845","sha256:2c0c46de9cdccdc6ae50c65b62fb60116cbcbc8c729d7cd086a862b6c5cc4c7c","sha256:0dbd6546efef9f4f69bdd8425cee046bb79f0fd3031f87714f1a48d81c355fb3","sha256:c498db09c59ccf85e1b1f0ff98f13f34f1b738ee78d565506a6b2376a684f7d5","sha256:a9e22cda0308d23cddf603e906c0ab8a415db25bebe8a5131c8feb324947ec8e","sha256:db170133755796b8d4917f232422654ba304c7b907c535e57ef3bb2703f3a356"],
            "Type":"layers"
        },
        "Size":89780310
    }
*/