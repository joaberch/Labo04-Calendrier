//
// Created by Joachim on 30.10.2026.
//

#include "display.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <array>

void printDays(const int firstDay, const int lastDay) {
    constexpr int dayInWeek = 7;
    const int pos = (firstDay+5)%dayInWeek; //0=monday, etc

    for (int i=0; i<pos;++i) {
        std::cout << "   ";
    }

    for (int i = 1; i <= lastDay; i++) {
        std::cout << std::setw(3) << i;

        if ((pos+i)%dayInWeek == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void printCalendar(const int year) {
    const std::array<std::string,12> months {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};

    for (std::size_t i = 1; i <= months.size(); ++i) {
        std::cout << months.at(i-1) << " " << year << std::endl;
        std::cout << "  L  M  M  J  V  S  D" << std::endl;

        const int firstDay = zellerCongruence(1, static_cast<int>(i), year);
        const int dayInMonth = getDaysinMonth(static_cast<int>(i), year);
        printDays(firstDay,dayInMonth);

        std::cout << std::endl;
    }
}