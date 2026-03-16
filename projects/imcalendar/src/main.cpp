#include <iostream>
#include <ctime>
#include "application/application.hpp"
#include "calendar/cal.hpp"

int main(int, char **)
{

    // // current date/time based on current system
    // time_t now = time(0);

    // // convert now to string form
    // char *dt = ctime(&now);

    // std::cout << "The local date and time is: " << dt << std::endl;

    // auto ttm = localtime(&now);
    // std::cout << "Year: " << ttm->tm_year + 1900 << std::endl;
    // std::cout << "Mon: " << ttm->tm_mon + 1 << std::endl;
    // std::cout << "Day: " << ttm->tm_mday << std::endl;

    // // convert now to tm struct for UTC
    // tm *gmtm = gmtime(&now);
    // dt = asctime(gmtm);
    // std::cout << "The UTC date and time is:" << dt << std::endl;

    // // cal
    // int year = 2024; // високосный год
    // int month = 2;   // февраль
    // std::cout << "Year: " << year << ", Month: " << month << ", Days - " << cal::days_in_month(year, month) << std::endl;
    // std::cout << "Year: " << 2023 << ", Month: " << month << ", Days - " << cal::days_in_month(2023, month) << std::endl;

    // // Перебираем все месяцы 2023‑го (невисокосного) года
    // year = 2026;
    // for (int m = 1; m <= 12; ++m)
    // {
    //     std::cout << "2023, месяц " << m << " → " << cal::days_in_month(year, m) << " дней\n";
    // }

    auto app = new Application();
    app->run();

    return 0;
}
