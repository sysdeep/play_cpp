#pragma once
#include <chrono>
#include <vector>
#include <future>
#include <functional>

namespace ui
{

    template <class payloadT>
    class AsyncFetcher
    {
    public:
        explicit AsyncFetcher(std::function<payloadT()> fetcher, std::chrono::microseconds timeout = std::chrono::milliseconds(0));

        payloadT tick();
        void start();

    private:
        std::chrono::microseconds timeout; // ms
        std::chrono::system_clock::time_point lastUpdate;
        std::vector<std::future<payloadT>> futures;

        std::function<payloadT()> fetcher;

        payloadT payload{};
    };
}