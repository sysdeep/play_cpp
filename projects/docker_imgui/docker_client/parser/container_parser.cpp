#include "rapidjson/document.h"
#include "parser_utils.hpp"
#include "container_parser.hpp"

using namespace docker;

ContainerModel parser::parseContainer(const std::string &src)
{
    rapidjson::Document document;
    document.Parse(src.c_str());

    ContainerModel result{};

    result.Id = processString(document, "Id", "Not Found");
    result.Path = processString(document, "Path", "Not Found");
    result.Name = processString(document, "Name", "Not Found");
    if (document.HasMember("RestartCount"))
        result.RestartCount = processUint64(document["RestartCount"]);

    if (document.HasMember("State"))
        result.State = parseContainerState(document["State"]);

    return result;
}

ContainerState parser::parseContainerState(const rapidjson::Value &value)
{

    ContainerState result{};

    result.Status = processString(value, "Status", "Not Found");
    result.StartedAt = processString(value, "StartedAt", "Not Found");
    // result.Running = processBool(document, "Running");
    // result.Paused = processBool(document, "Paused");
    // result.Restarting;

    return result;
}

/*
{
    "Id":"28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba",
    "Created":"2025-11-25T15:37:33.710427462Z",
    "Path":"/entrypoint.sh",
    "Args":["/etc/docker/registry/config.yml"],
    "State":{
        "Status":"running",
        "Running":true,
        "Paused":false,
        "Restarting":false,
        "OOMKilled":false,
        "Dead":false,
        "Pid":4591,
        "ExitCode":0,
        "Error":"",
        "StartedAt":"2026-03-05T07:08:32.952693854Z",
        "FinishedAt":"2026-03-04T15:42:18.255986124Z"
        },
    "Image":"sha256:a98a5e59fc04ef47a28c1119b48f3e7826fc7ff14b80641bcf0c4131b225360d",
    "ResolvConfPath":"/home/var/lib/docker/containers/28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba/resolv.conf",
    "HostnamePath":"/home/var/lib/docker/containers/28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba/hostname",
    "HostsPath":"/home/var/lib/docker/containers/28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba/hosts",
    "LogPath":"/home/var/lib/docker/containers/28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba/28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba-json.log",
    "Name":"/registry",
    "RestartCount":0,
    "Driver":"overlay2",
    "Platform":"linux",
    "MountLabel":"",
    "ProcessLabel":"",
    "AppArmorProfile":"docker-default",
    "ExecIDs":null,
    "HostConfig":{"Binds":["docker-registry:/var/lib/registry"],"ContainerIDFile":"","LogConfig":{"Type":"json-file","Config":{}},"NetworkMode":"bridge","PortBindings":{"5000/tcp":[{"HostIp":"127.0.0.1","HostPort":"5000"},{"HostIp":"172.28.1.1","HostPort":"5000"}]},"RestartPolicy":{"Name":"always","MaximumRetryCount":0},"AutoRemove":false,"VolumeDriver":"","VolumesFrom":null,"ConsoleSize":[46,160],"CapAdd":null,"CapDrop":null,"CgroupnsMode":"private","Dns":[],"DnsOptions":[],"DnsSearch":[],"ExtraHosts":null,"GroupAdd":null,"IpcMode":"private","Cgroup":"","Links":null,"OomScoreAdj":0,"PidMode":"","Privileged":false,"PublishAllPorts":false,"ReadonlyRootfs":false,"SecurityOpt":null,"UTSMode":"","UsernsMode":"","ShmSize":67108864,"Runtime":"runc","Isolation":"","CpuShares":0,"Memory":0,"NanoCpus":0,"CgroupParent":"","BlkioWeight":0,"BlkioWeightDevice":[],"BlkioDeviceReadBps":[],"BlkioDeviceWriteBps":[],"BlkioDeviceReadIOps":[],"BlkioDeviceWriteIOps":[],"CpuPeriod":0,"CpuQuota":0,"CpuRealtimePeriod":0,"CpuRealtimeRuntime":0,"CpusetCpus":"","CpusetMems":"","Devices":[],"DeviceCgroupRules":null,"DeviceRequests":null,"MemoryReservation":0,"MemorySwap":0,"MemorySwappiness":null,"OomKillDisable":null,"PidsLimit":null,"Ulimits":[],"CpuCount":0,"CpuPercent":0,"IOMaximumIOps":0,"IOMaximumBandwidth":0,"MaskedPaths":["/proc/acpi","/proc/asound","/proc/interrupts","/proc/kcore","/proc/keys","/proc/latency_stats","/proc/sched_debug","/proc/scsi","/proc/timer_list","/proc/timer_stats","/sys/devices/virtual/powercap","/sys/firmware","/sys/devices/system/cpu/cpu0/thermal_throttle","/sys/devices/system/cpu/cpu1/thermal_throttle","/sys/devices/system/cpu/cpu2/thermal_throttle","/sys/devices/system/cpu/cpu3/thermal_throttle","/sys/devices/system/cpu/cpu4/thermal_throttle","/sys/devices/system/cpu/cpu5/thermal_throttle","/sys/devices/system/cpu/cpu6/thermal_throttle","/sys/devices/system/cpu/cpu7/thermal_throttle"],"ReadonlyPaths":["/proc/bus","/proc/fs","/proc/irq","/proc/sys","/proc/sysrq-trigger"]},"GraphDriver":{"Data":{"ID":"28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba","LowerDir":"/home/var/lib/docker/overlay2/2add5b9d6f12502447d7796d49ef4acecd93345e0f72f20e82e64b576a9ef65d-init/diff:/home/var/lib/docker/overlay2/j01fg04xdwngz6ycmt7w5xomm/diff:/home/var/lib/docker/overlay2/bd97e5b35a586ff3bf7516985371ad923bb85320849c61aa9f07f0fd8b215157/diff:/home/var/lib/docker/overlay2/3d75e987deb70070e8ec1dd89dc10aba142182c7a18ac8a05c72c8e5a5c0393c/diff:/home/var/lib/docker/overlay2/9962e74d58f6f45f5864d34bcebf4a4985f50ce2e1c5b495d91a795985e5717b/diff:/home/var/lib/docker/overlay2/a16844153c69acc7aaa86cfa53bbd9e75d0154fc253387f5ccd847eddd1b53f0/diff:/home/var/lib/docker/overlay2/d95fee1d78687b372dd7c82fa30cec25346abf8bd03782b0aa82fa12e38c4c33/diff","MergedDir":"/home/var/lib/docker/overlay2/2add5b9d6f12502447d7796d49ef4acecd93345e0f72f20e82e64b576a9ef65d/merged","UpperDir":"/home/var/lib/docker/overlay2/2add5b9d6f12502447d7796d49ef4acecd93345e0f72f20e82e64b576a9ef65d/diff","WorkDir":"/home/var/lib/docker/overlay2/2add5b9d6f12502447d7796d49ef4acecd93345e0f72f20e82e64b576a9ef65d/work"},"Name":"overlay2"},"Mounts":[{"Type":"volume","Name":"docker-registry","Source":"/home/var/lib/docker/volumes/docker-registry/_data","Destination":"/var/lib/registry","Driver":"local","Mode":"z","RW":true,"Propagation":""}],"Config":{"Hostname":"28cf1320d2ba","Domainname":"","User":"","AttachStdin":false,"AttachStdout":false,"AttachStderr":false,"ExposedPorts":{"5000/tcp":{}},"Tty":false,"OpenStdin":false,"StdinOnce":false,"Env":["PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin","REGISTRY_HTTP_TLS_CERTIFICATE=/opt/docker-registry/cert/cert.crt","REGISTRY_HTTP_TLS_KEY=/opt/docker-registry/cert/cert.key","REGISTRY_STORAGE_DELETE_ENABLED=true"],"Cmd":["/etc/docker/registry/config.yml"],"Image":"kata/dev/registry:2","Volumes":{"/var/lib/registry":{}},"WorkingDir":"","Entrypoint":["/entrypoint.sh"],"Labels":{}},"NetworkSettings":{"SandboxID":"aaae80ded51178b5ed96acb86e22af8c00c25f06909a99de0c0fd0c5b94e08d4","SandboxKey":"/var/run/docker/netns/aaae80ded511","Ports":{"5000/tcp":[{"HostIp":"127.0.0.1","HostPort":"5000"},{"HostIp":"172.28.1.1","HostPort":"5000"}]},"Networks":{"bridge":{"IPAMConfig":null,"Links":null,"Aliases":null,"DriverOpts":null,"GwPriority":0,"NetworkID":"c0b2808cd1bad3a66315b921dc460d2de879b44f899a9729c8b120ffc9605ed7","EndpointID":"350a060bed460c3c79b8713a859e2b20611733400dadd6c27c61cc771f809847","Gateway":"172.27.0.1","IPAddress":"172.27.0.2","MacAddress":"ea:f3:eb:46:3c:11","IPPrefixLen":24,"IPv6Gateway":"","GlobalIPv6Address":"","GlobalIPv6PrefixLen":0,"DNSNames":null}}}}
*/