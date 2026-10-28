#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>

short getYear() {
    short year;
    do {
        std::cout << "entrer une valeur [1800 - 2100] : ";
        std::cin >> year;

        if (year < 1800 || year > 2100) {
            std::cout << "/!\\ erreur de saisie\n";
        }
    } while (year < 1800 || year > 2100);

    return year;
}

int zellerCongruence(const short q, const short m, const short K, const short J) {
    return (q+static_cast<short>(floor(13*(m+1)/5))+K+static_cast<short>(floor(K/4))+static_cast<short>(floor(J/4))-2*J)%7;
}

void printDays(const short firstDay, const short lastDay) {
    constexpr short dayInWeek = 7;
    short pos = static_cast<short>((firstDay+5)%dayInWeek); //0=monday, etc

    std::cout << std::string(pos*3, ' ');
    std::cout << std::setw(2) << 1 << std::setw(3);

    for (int i = 2; i <= lastDay; i++) {
        std::cout << i << std::setw(3);
        ++pos;
        if (pos%dayInWeek == 6) {
            std::cout << std::setw(2);
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

bool isLeapYear(short year) {
    return year%400==0&&year%100!=0&&year%4==0;
}

short getDaysinMonths(short month, short year) {
    switch (month) {
        case 0: //janvier
            return 31;
            break;
        case 1: //février
            return isLeapYear(year) ? 29 : 28;
            break;
        case 2: //mars
            return 31;
            break;
        case 3: //avril
            return 30;
            break;
        case 4: //mai
            return 31;
            break;
        case 5: //juin
            return 30;
            break;
        case 6: //juillet
            return 31;
            break;
        case 7: //aout
            return 31;
            break;
        case 8: //septembre
            return 30;
            break;
        case 9: //octobre
            return 31;
            break;
        case 10: //novembre
            return 30;
            break;
        case 11: //decembre
            return 31;
            break;
        default:
            std::cout << "Erreur lors de la recuperation du nombre de jour dans le mois" << month << std::endl;
            return 0; //err recognition
            break;
    }
}

short getDate(short year, const short month, const short day) {
    const short q = day;
    short m = month;
    if (m<=1) { //january and february are 13 and 14
        m+=13;
        year--;
    }
    const short K = (year)-static_cast<short>(floor((year)/100))*100;
    const short J = static_cast<short>(floor((year)/100));

    return zellerCongruence(q,m,K,J);
}

int main() {
    do {
        short year = getYear();
        std::array<std::string,12> months {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};

        for (size_t i = 0; i < months.size(); ++i) {
            std::cout << months.at(i) << " " << year << std::endl;
            std::cout << " L  M  M  J  V  S  D" << std::endl;

            const short firstDay = getDate(year, static_cast<short>(i), 1);
            const short dayInMonth = getDaysinMonths(static_cast<short>(i), year);
            printDays(firstDay,dayInMonth);

            std::cout << std::endl;
        }
    } while (true);
}
