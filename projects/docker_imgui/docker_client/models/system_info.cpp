#include "system_info.hpp"
#include "rapidjson/document.h"
#include <iostream>

using namespace docker;

SystemInfo SystemInfo::fromString(const std::string src)
{
    rapidjson::Document document;
    document.Parse(src.c_str());

    // int containers = document["Containers"].GetInt();
    // std::cout << containers << std::endl;

    SystemInfo result = SystemInfo{};

    if (document.HasMember("Containers"))
        result.Containers = document["Containers"].GetUint();

    if (document.HasMember("ContainersRunning"))
        result.ContainersRunning = document["ContainersRunning"].GetUint();

    if (document.HasMember("ContainersPaused"))
        result.ContainersPaused = document["ContainersPaused"].GetUint();

    if (document.HasMember("ContainersStopped"))
        result.ContainersStopped = document["ContainersStopped"].GetUint();

    if (document.HasMember("Images"))
        result.Images = document["Images"].GetUint();

    if (document.HasMember("MemTotal"))
        result.MemTotal = document["MemTotal"].GetUint64();

    if (document.HasMember("ServerVersion"))
    {
        auto res = document["ServerVersion"].GetString();
        result.ServerVersion = std::string(res, document["ServerVersion"].GetStringLength());
    }

    return result;
}

/*
{
    "ID":"RIC3:VAEK:G7YV:R6I5:4NTJ:VP3L:SC3L:KII6:Q24U:O3ER:LUEL:N2XC",
    "Containers":9,
    "ContainersRunning":1,
    "ContainersPaused":0,
    "ContainersStopped":8,
    "Images":72,
    "Driver":"overlay2",
    "DriverStatus":[
        ["Backing Filesystem","extfs"],
        ["Supports d_type","true"],
        ["Using metacopy","false"],
        ["Native Overlay Diff","true"],
        ["userxattr","false"]
    ],
    "Plugins":{"
        Volume":["local"],
        "Network":["bridge","host","ipvlan","macvlan","null","overlay"],
        "Authorization":null,
        "Log":["awslogs","fluentd","gcplogs","gelf","journald","json-file","local","splunk","syslog"]
    },
    "MemoryLimit":true,
    "SwapLimit":true,
    "CpuCfsPeriod":true,
    "CpuCfsQuota":true,
    "CPUShares":true,
    "CPUSet":true,
    "PidsLimit":true,
    "IPv4Forwarding":true,
    "Debug":false,
    "NFd":49,
    "OomKillDisable":false,
    "NGoroutines":178,
    "SystemTime":"2026-02-19T15:34:27.872025776+03:00",
    "LoggingDriver":"json-file",
    "CgroupDriver":"systemd",
    "CgroupVersion":"2",
    "NEventsListener":0,
    "KernelVersion":"6.8.0-94-generic",
    "OperatingSystem":"Ubuntu 22.04.5 LTS",
    "OSVersion":"22.04",
    "OSType":"linux",
    "Architecture":"x86_64",
    "IndexServerAddress":"https://index.docker.io/v1/",
    "RegistryConfig":{
        "InsecureRegistryCIDRs":["::1/128","127.0.0.0/8"],
        "IndexConfigs":{
            "docker.io":{"Name":"docker.io","Mirrors":[],"Secure":true,"Official":true},
            "registry.kata.avp.ru:5000":{
                "Name":"registry.kata.avp.ru:5000",
                "Mirrors":[],
                "Secure":false,
                "Official":false
            }
        },
        "Mirrors":[]
    },
    "NCPU":8,
    "MemTotal":24973815808,
    "GenericResources":null,
    "DockerRootDir":"/home/var/lib/docker",
    "HttpProxy":"",
    "HttpsProxy":"",
    "NoProxy":"",
    "Name":"nefedkin.avp.ru",
    "Labels":[],
    "ExperimentalBuild":false,
    "ServerVersion":"29.2.1",
    "Runtimes":{
        "io.containerd.runc.v2":{
            "path":"runc",
            "status":{
                "org.opencontainers.runtime-spec.features":"{
                    \"ociVersionMin\":\"1.0.0\",
                    \"ociVersionMax\":\"1.2.1\",
                    \"hooks\":[\"prestart\",\"createRuntime\",\"createContainer\",\"startContainer\",\"poststart\",\"poststop\"],
                    \"mountOptions\":[\"async\",\"atime\",\"bind\",\"defaults\",\"dev\",\"diratime\",\"dirsync\",\"exec\",\"iversion\",\"lazytime\",\"loud\",\"mand\",\"noatime\",\"nodev\",\"nodiratime\",\"noexec\",\"noiversion\",\"nolazytime\",\"nomand\",\"norelatime\",\"nostrictatime\",\"nosuid\",\"nosymfollow\",\"private\",\"ratime\",\"rbind\",\"rdev\",\"rdiratime\",\"relatime\",\"remount\",\"rexec\",\"rnoatime\",\"rnodev\",\"rnodiratime\",\"rnoexec\",\"rnorelatime\",\"rnostrictatime\",\"rnosuid\",\"rnosymfollow\",\"ro\",\"rprivate\",\"rrelatime\",\"rro\",\"rrw\",\"rshared\",\"rslave\",\"rstrictatime\",\"rsuid\",\"rsymfollow\",\"runbindable\",\"rw\",\"shared\",\"silent\",\"slave\",\"strictatime\",\"suid\",\"symfollow\",\"sync\",\"tmpcopyup\",\"unbindable\"],
                    \"linux\":{\"namespaces\":[\"cgroup\",\"ipc\",\"mount\",\"network\",\"pid\",\"time\",\"user\",\"uts\"],\"capabilities\":[\"CAP_CHOWN\",\"CAP_DAC_OVERRIDE\",\"CAP_DAC_READ_SEARCH\",\"CAP_FOWNER\",\"CAP_FSETID\",\"CAP_KILL\",\"CAP_SETGID\",\"CAP_SETUID\",\"CAP_SETPCAP\",\"CAP_LINUX_IMMUTABLE\",\"CAP_NET_BIND_SERVICE\",\"CAP_NET_BROADCAST\",\"CAP_NET_ADMIN\",\"CAP_NET_RAW\",\"CAP_IPC_LOCK\",\"CAP_IPC_OWNER\",\"CAP_SYS_MODULE\",\"CAP_SYS_RAWIO\",\"CAP_SYS_CHROOT\",\"CAP_SYS_PTRACE\",\"CAP_SYS_PACCT\",\"CAP_SYS_ADMIN\",\"CAP_SYS_BOOT\",\"CAP_SYS_NICE\",\"CAP_SYS_RESOURCE\",\"CAP_SYS_TIME\",\"CAP_SYS_TTY_CONFIG\",\"CAP_MKNOD\",\"CAP_LEASE\",\"CAP_AUDIT_WRITE\",\"CAP_AUDIT_CONTROL\",\"CAP_SETFCAP\",\"CAP_MAC_OVERRIDE\",\"CAP_MAC_ADMIN\",\"CAP_SYSLOG\",\"CAP_WAKE_ALARM\",\"CAP_BLOCK_SUSPEND\",\"CAP_AUDIT_READ\",\"CAP_PERFMON\",\"CAP_BPF\",\"CAP_CHECKPOINT_RESTORE\"],\"cgroup\":{\"v1\":true,\"v2\":true,\"systemd\":true,\"systemdUser\":true,\"rdma\":true},\"seccomp\":{\"enabled\":true,\"actions\":[\"SCMP_ACT_ALLOW\",\"SCMP_ACT_ERRNO\",\"SCMP_ACT_KILL\",\"SCMP_ACT_KILL_PROCESS\",\"SCMP_ACT_KILL_THREAD\",\"SCMP_ACT_LOG\",\"SCMP_ACT_NOTIFY\",\"SCMP_ACT_TRACE\",\"SCMP_ACT_TRAP\"],\"operators\":[\"SCMP_CMP_EQ\",\"SCMP_CMP_GE\",\"SCMP_CMP_GT\",\"SCMP_CMP_LE\",\"SCMP_CMP_LT\",\"SCMP_CMP_MASKED_EQ\",\"SCMP_CMP_NE\"],\"archs\":[\"SCMP_ARCH_AARCH64\",\"SCMP_ARCH_ARM\",\"SCMP_ARCH_MIPS\",\"SCMP_ARCH_MIPS64\",\"SCMP_ARCH_MIPS64N32\",\"SCMP_ARCH_MIPSEL\",\"SCMP_ARCH_MIPSEL64\",\"SCMP_ARCH_MIPSEL64N32\",\"SCMP_ARCH_PPC\",\"SCMP_ARCH_PPC64\",\"SCMP_ARCH_PPC64LE\",\"SCMP_ARCH_RISCV64\",\"SCMP_ARCH_S390\",\"SCMP_ARCH_S390X\",\"SCMP_ARCH_X32\",\"SCMP_ARCH_X86\",\"SCMP_ARCH_X86_64\"],\"knownFlags\":[\"SECCOMP_FILTER_FLAG_TSYNC\",\"SECCOMP_FILTER_FLAG_SPEC_ALLOW\",\"SECCOMP_FILTER_FLAG_LOG\"],\"supportedFlags\":[\"SECCOMP_FILTER_FLAG_TSYNC\",\"SECCOMP_FILTER_FLAG_SPEC_ALLOW\",\"SECCOMP_FILTER_FLAG_LOG\"]},\"apparmor\":{\"enabled\":true},\"selinux\":{\"enabled\":true},\"intelRdt\":{\"enabled\":true},\"mountExtensions\":{\"idmap\":{\"enabled\":true}}},\"annotations\":{\"io.github.seccomp.libseccomp.version\":\"2.5.3\",\"org.opencontainers.runc.checkpoint.enabled\":\"true\",\"org.opencontainers.runc.commit\":\"v1.3.4-0-gd6d73eb8\",\"org.opencontainers.runc.version\":\"1.3.4\\n\"},\"potentiallyUnsafeConfigAnnotations\":[\"bundle\",\"org.systemd.property.\",\"org.criu.config\"]}"}},"runc":{"path":"runc","status":{"org.opencontainers.runtime-spec.features":"{\"ociVersionMin\":\"1.0.0\",\"ociVersionMax\":\"1.2.1\",\"hooks\":[\"prestart\",\"createRuntime\",\"createContainer\",\"startContainer\",\"poststart\",\"poststop\"],\"mountOptions\":[\"async\",\"atime\",\"bind\",\"defaults\",\"dev\",\"diratime\",\"dirsync\",\"exec\",\"iversion\",\"lazytime\",\"loud\",\"mand\",\"noatime\",\"nodev\",\"nodiratime\",\"noexec\",\"noiversion\",\"nolazytime\",\"nomand\",\"norelatime\",\"nostrictatime\",\"nosuid\",\"nosymfollow\",\"private\",\"ratime\",\"rbind\",\"rdev\",\"rdiratime\",\"relatime\",\"remount\",\"rexec\",\"rnoatime\",\"rnodev\",\"rnodiratime\",\"rnoexec\",\"rnorelatime\",\"rnostrictatime\",\"rnosuid\",\"rnosymfollow\",\"ro\",\"rprivate\",\"rrelatime\",\"rro\",\"rrw\",\"rshared\",\"rslave\",\"rstrictatime\",\"rsuid\",\"rsymfollow\",\"runbindable\",\"rw\",\"shared\",\"silent\",\"slave\",\"strictatime\",\"suid\",\"symfollow\",\"sync\",\"tmpcopyup\",\"unbindable\"],\"linux\":{\"namespaces\":[\"cgroup\",\"ipc\",\"mount\",\"network\",\"pid\",\"time\",\"user\",\"uts\"],\"capabilities\":[\"CAP_CHOWN\",\"CAP_DAC_OVERRIDE\",\"CAP_DAC_READ_SEARCH\",\"CAP_FOWNER\",\"CAP_FSETID\",\"CAP_KILL\",\"CAP_SETGID\",\"CAP_SETUID\",\"CAP_SETPCAP\",\"CAP_LINUX_IMMUTABLE\",\"CAP_NET_BIND_SERVICE\",\"CAP_NET_BROADCAST\",\"CAP_NET_ADMIN\",\"CAP_NET_RAW\",\"CAP_IPC_LOCK\",\"CAP_IPC_OWNER\",\"CAP_SYS_MODULE\",\"CAP_SYS_RAWIO\",\"CAP_SYS_CHROOT\",\"CAP_SYS_PTRACE\",\"CAP_SYS_PACCT\",\"CAP_SYS_ADMIN\",\"CAP_SYS_BOOT\",\"CAP_SYS_NICE\",\"CAP_SYS_RESOURCE\",\"CAP_SYS_TIME\",\"CAP_SYS_TTY_CONFIG\",\"CAP_MKNOD\",\"CAP_LEASE\",\"CAP_AUDIT_WRITE\",\"CAP_AUDIT_CONTROL\",\"CAP_SETFCAP\",\"CAP_MAC_OVERRIDE\",\"CAP_MAC_ADMIN\",\"CAP_SYSLOG\",\"CAP_WAKE_ALARM\",\"CAP_BLOCK_SUSPEND\",\"CAP_AUDIT_READ\",\"CAP_PERFMON\",\"CAP_BPF\",\"CAP_CHECKPOINT_RESTORE\"],\"cgroup\":{\"v1\":true,\"v2\":true,\"systemd\":true,\"systemdUser\":true,\"rdma\":true},\"seccomp\":{\"enabled\":true,\"actions\":[\"SCMP_ACT_ALLOW\",\"SCMP_ACT_ERRNO\",\"SCMP_ACT_KILL\",\"SCMP_ACT_KILL_PROCESS\",\"SCMP_ACT_KILL_THREAD\",\"SCMP_ACT_LOG\",\"SCMP_ACT_NOTIFY\",\"SCMP_ACT_TRACE\",\"SCMP_ACT_TRAP\"],\"operators\":[\"SCMP_CMP_EQ\",\"SCMP_CMP_GE\",\"SCMP_CMP_GT\",\"SCMP_CMP_LE\",\"SCMP_CMP_LT\",\"SCMP_CMP_MASKED_EQ\",\"SCMP_CMP_NE\"],\"archs\":[\"SCMP_ARCH_AARCH64\",\"SCMP_ARCH_ARM\",\"SCMP_ARCH_MIPS\",\"SCMP_ARCH_MIPS64\",\"SCMP_ARCH_MIPS64N32\",\"SCMP_ARCH_MIPSEL\",\"SCMP_ARCH_MIPSEL64\",\"SCMP_ARCH_MIPSEL64N32\",\"SCMP_ARCH_PPC\",\"SCMP_ARCH_PPC64\",\"SCMP_ARCH_PPC64LE\",\"SCMP_ARCH_RISCV64\",\"SCMP_ARCH_S390\",\"SCMP_ARCH_S390X\",\"SCMP_ARCH_X32\",\"SCMP_ARCH_X86\",\"SCMP_ARCH_X86_64\"],\"knownFlags\":[\"SECCOMP_FILTER_FLAG_TSYNC\",\"SECCOMP_FILTER_FLAG_SPEC_ALLOW\",\"SECCOMP_FILTER_FLAG_LOG\"],\"supportedFlags\":[\"SECCOMP_FILTER_FLAG_TSYNC\",\"SECCOMP_FILTER_FLAG_SPEC_ALLOW\",\"SECCOMP_FILTER_FLAG_LOG\"]},\"apparmor\":{\"enabled\":true},\"selinux\":{\"enabled\":true},\"intelRdt\":{\"enabled\":true},\"mountExtensions\":{\"idmap\":{\"enabled\":true}}},\"annotations\":{\"io.github.seccomp.libseccomp.version\":\"2.5.3\",\"org.opencontainers.runc.checkpoint.enabled\":\"true\",\"org.opencontainers.runc.commit\":\"v1.3.4-0-gd6d73eb8\",\"org.opencontainers.runc.version\":\"1.3.4\\n\"},\"potentiallyUnsafeConfigAnnotations\":[\"bundle\",\"org.systemd.property.\",\"org.criu.config\"]}"}}},"DefaultRuntime":"runc","Swarm":{"NodeID":"tgyx3z0ro5qukwx6l5ukq1a76","NodeAddr":"192.168.200.52","LocalNodeState":"active","ControlAvailable":true,"Error":"","RemoteManagers":[{"NodeID":"tgyx3z0ro5qukwx6l5ukq1a76","Addr":"192.168.200.52:2377"}],"Nodes":1,"Managers":1,"Cluster":{"ID":"6zgr3oorxon6pv0o952o1ir1b","Version":{"Index":1424688},"CreatedAt":"2022-02-10T07:59:21.216247202Z","UpdatedAt":"2026-02-13T19:07:48.927253561Z","Spec":{"Name":"default","Labels":{},"Orchestration":{"TaskHistoryRetentionLimit":5},"Raft":{"SnapshotInterval":10000,"KeepOldSnapshots":0,"LogEntriesForSlowFollowers":500,"ElectionTick":10,"HeartbeatTick":1},"Dispatcher":{"HeartbeatPeriod":5000000000},"CAConfig":{"NodeCertExpiry":7776000000000000},"TaskDefaults":{},"EncryptionConfig":{"AutoLockManagers":false}},"TLSInfo":{"TrustRoot":"-----BEGIN CERTIFICATE-----\nMIIBajCCARCgAwIBAgIUaeVucZwD4cvcm9xixgZlWZcp7OYwCgYIKoZIzj0EAwIw\nEzERMA8GA1UEAxMIc3dhcm0tY2EwHhcNMjIwMjEwMDc1NDAwWhcNNDIwMjA1MDc1\nNDAwWjATMREwDwYDVQQDEwhzd2FybS1jYTBZMBMGByqGSM49AgEGCCqGSM49AwEH\nA0IABIx52FZ90BZ2F00B+7Sw6arBekqOwrb898e2zELWjKs5J0Ndv7dqoNu2pj2f\n1nax/xNBviAvQWhHfwmzFKv1WLCjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNVHRMB\nAf8EBTADAQH/MB0GA1UdDgQWBBSOdTd6Vo0xX97ef6a3pGQz+B49xDAKBggqhkjO\nPQQDAgNIADBFAiEAtVC60wo/rdpMgGXCstVyhjnIkmZaIMXmN6wCE4Yn9KMCID8n\nfDb+w/Jo+7QZyRvIKT6Sc9fSndY5FYf9D4InF8j7\n-----END CERTIFICATE-----\n","CertIssuerSubject":"MBMxETAPBgNVBAMTCHN3YXJtLWNh","CertIssuerPublicKey":"MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEjHnYVn3QFnYXTQH7tLDpqsF6So7Ctvz3x7bMQtaMqzknQ12/t2qg27amPZ/WdrH/E0G+IC9BaEd/CbMUq/VYsA=="},"RootRotationInProgress":false,"DefaultAddrPool":["10.0.0.0/8"],"SubnetSize":24,"DataPathPort":4789}},"LiveRestoreEnabled":false,"Isolation":"","InitBinary":"docker-init","ContainerdCommit":{"ID":"dea7da592f5d1d2b7755e3a161be07f43fad8f75"},"RuncCommit":{"ID":"v1.3.4-0-gd6d73eb8"},"InitCommit":{"ID":"de40ad0"},"SecurityOptions":["name=apparmor","name=seccomp,profile=builtin","name=cgroupns"],"DefaultAddressPools":[{"Base":"172.27.0.0/16","Size":24}],"FirewallBackend":{"Driver":"iptables"},"CDISpecDirs":["/etc/cdi","/var/run/cdi"],"Containerd":{"Address":"/run/containerd/containerd.sock","Namespaces":{"Containers":"moby","Plugins":"plugins.moby"}},"Warnings":["[DEPRECATION NOTICE]: API is accessible on http://0.0.0.0:2375 without encryption.\n         Access to the remote API is equivalent to root access on the host. Refer\n         to the 'Docker daemon attack surface' section in the documentation for\n         more information: https://docs.docker.com/go/attack-surface/\nIn future versions this will be a hard failure preventing the daemon from starting! Learn more at: https://docs.docker.com/go/api-security/"]}
*/