#include <cmath>
#include "imgui.h"
#include "board.hpp"
#include "ui/utils/utils.hpp"

using namespace UI;
Board::Board() {}

void Board::draw(CalendarModel *model)
{

    // cache
    if (this->last_month != model->month || this->last_year != model->year)
    {
        this->data_model = this->make_board(model);
        this->last_month = model->month;
        this->last_year = model->year;
    }

    // draw table
    if (ImGui::BeginTable("calendar_grid", 7))
    {

        // week days header
        ImGui::TableNextRow();
        int index = 0;
        for (auto day : calendar::weekdays)
        {
            auto label = calendar::get_weekday_name_short(day);
            ImGui::TableSetColumnIndex(index++);
            // ImGui::Text("%s", label);
            CenterTextInCell(label);
        }

        // body
        const int rows = std::ceil(double(this->data_model.size()) / 7.f);

        for (int row = 0; row < rows; row++)
        {

            ImGui::TableNextRow();

            for (int column = 0; column < 7; column++)
            {

                ImGui::TableSetColumnIndex(column);

                auto index = (row * 7) + column;
                auto day = this->data_model[index]; // день
                // std::cout
                //     << "----> day: " << day.day
                //     << "index: " << index
                //     << std::endl;

                // день недели не из тек. месяца
                if (day.day == 0)
                {
                    // ImGui::Button("", ImVec2(-FLT_MIN, 0.0f));
                    continue;
                }

                bool is_current_day = day_is_current(day, model);
                if (is_current_day)
                {

                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(5 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(5 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(5 / 7.0f, 0.8f, 0.8f));
                }

                auto btn_text_model = std::to_string(day.day);
                ImGui::Button(btn_text_model.c_str(), ImVec2(-FLT_MIN, 0.0f));

                if (is_current_day)
                {
                    ImGui::PopStyleColor(3);
                }

                // auto btn_text_model = std::to_string(column * row);
                // if (ImGui::Button(btn_text_model.c_str(), ImVec2(-FLT_MIN, 0.0f)))
                // {
                //   this->on_day_clicked(column * row);
                // }
            }
        }
        ImGui::EndTable();
    }
}

std::vector<Day> Board::make_board(CalendarModel *model)
{

    std::vector<Day> days;

    // std::cout << "=====================================\n";

    int month_day_index = 0;
    for (;;)
    {
        for (int i = 0; i < 7; i++)
        {
            auto day = model->days[month_day_index];

            // std::cout << "day: " << day.day
            //           << ", wday: " << static_cast<std::size_t>(day.weekday)
            //           << ", i: " << i
            //           << ", iwd: " << static_cast<std::size_t>(weekdays[i]);
            if (day.weekday == calendar::weekdays[i])
            {
                days.push_back(day);
                month_day_index++;
                // std::cout << " [OK]\n";
            }
            else
            {
                days.push_back(Day{0, calendar::Weekday::Sunday}); // empty cell
                // std::cout << " [pass]\n";
            }
        }

        if (month_day_index >= model->days.size())
        {
            break;
        }
    }

    // std::cout << "-----------------------\n";
    // for (const auto &d : days)
    // {
    //     std::cout << "day: " << d.day << ", wd: " << static_cast<std::size_t>(d.weekday) << std::endl;
    // }

    // for (int day = 0; day < model->days; day++)
    // {
    //     auto wd = cal::day_of_week(day + 1, model->month, model->year);

    //     days.push_back({day, wd});
    // }

    return days;
}

bool Board::day_is_current(Day day, CalendarModel *model)
{
    if (model->current_year != model->year)
        return false;

    if (model->current_month != model->month)
        return false;

    return model->current_day == day.day;
}