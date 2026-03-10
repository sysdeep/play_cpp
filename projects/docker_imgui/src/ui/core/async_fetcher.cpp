#include <iostream>
#include "async_fetcher.hpp"
#include "models/container_model.hpp"
#include "models/system_info.hpp"

using namespace ui;

template <class payloadT>
AsyncFetcher<payloadT>::AsyncFetcher(
    std::function<payloadT()> fetcher,
    std::chrono::microseconds timeout) : fetcher(fetcher), timeout(timeout)
{
    lastUpdate = std::chrono::system_clock::now() - timeout * 2;
}

template <class payloadT>
payloadT AsyncFetcher<payloadT>::tick()
{
    // запуск фонового процесса
    if (timeout.count() > 0)
    {

        auto now = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->lastUpdate);
        if (elapsed > timeout)
        {

            this->start();
            this->lastUpdate = now;
        }
    }

    // обработка футур
    if (!futures.empty())
    {

        for (auto it = futures.begin(); it != futures.end();)
        {

            if (it->valid())
            {
                auto future_status = it->wait_for(std::chrono::seconds(0));
                if (future_status == std::future_status::ready)
                {
                    // std::cout << "future status - ready, update containers and erase" << std::endl;
                    // this->containers = it->get();
                    // handler(it->get());
                    payload = it->get();
                    // remove element from vector
                    futures.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                ++it;
            }
        }
    }

    return payload;
}

template <class payloadT>
void AsyncFetcher<payloadT>::start()
{
    std::cout << "start async task" << std::endl;
    auto task_future = std::async(std::launch::async, fetcher);
    futures.push_back(std::move(task_future));
}

// template classes -----------------------------------------------------------
template class ui::AsyncFetcher<docker::ContainerModel>;
template class ui::AsyncFetcher<docker::SystemInfo>;