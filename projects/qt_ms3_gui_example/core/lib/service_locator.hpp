// service_locator.hpp
#pragma once
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <type_traits>
#include <stdexcept>

class ServiceLocator
{
public:
    // Регистрация сервиса (обычно один экземпляр – singleton)
    template <class Service>
    static void registerService(std::shared_ptr<Service> impl)
    {
        static_assert(std::is_base_of_v<Service, Service>, "Service must be a class");
        services_[typeid(Service)] = impl;
    }

    // Получить сервис
    template <class Service>
    static std::shared_ptr<Service> provide()
    {
        auto it = services_.find(typeid(Service));
        if (it == services_.end())
            throw std::runtime_error("Service not registered");
        // Приводим тип обратно
        return std::static_pointer_cast<Service>(it->second);
    }

    // Очистить реестр (полезно в unit‑тестах)
    static void clear()
    {
        services_.clear();
    }

private:
    // Хранилище «type → instance»
    static inline std::unordered_map<std::type_index, std::shared_ptr<void>> services_;
};