#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>

int getYear() {
    int year;
    do {
        std::cout << "entrer une valeur [1800 - 2100] : ";
        std::cin >> year;

        if (year < 1800 || year > 2100) {
            std::cout << "/!\\ erreur de saisie\n";
        }
    } while (year < 1800 || year > 2100);

    return year;
}

///https://en.wikipedia.org/wiki/Zeller%27s_congruence
int zellerCongruence(const int q, int m, int year) { //O(1)
    if (m<=2) {
        m+=12;
        year--;
    }
    const int K = year%100;
    const int J = year/100;

    const int h = (q+13*(m+1)/5+K+K/4+J/4-2*J)%7;
    return (h+7)%7; //abs
}


bool isLeapYear(int year) { //O(1)
    if (year%400 == 0) {
        return true;
    }
    if (year%100 == 0) {
        return false;
    }
    if (year%4 == 0) {
        return true;
    }

    return false;
}

int getDaysinMonth(int month, int year) { //O(1)
    switch (month) {
        case 1: //janvier
        case 3: //mars
        case 5: //mai
        case 7: //juillet
        case 8: //aout
        case 10: //octobre
        case 12: //decembre
            return 31;

        case 4: //avril
        case 6: //juin
        case 9: //septembre
        case 11: //novembre
            return 30;

        case 2: //février
            return isLeapYear(year) ? 29 : 28;
    }
}

void printDays(const int firstDay, const int lastDay) {
    constexpr int dayInWeek = 7;
    int pos = (firstDay+5)%dayInWeek; //0=monday, etc

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

int main() {
    char restart = 'N';
    do {
        const int year = getYear();
        std::array<std::string,12> months {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};

        for (size_t i = 1; i <= months.size(); ++i) {
            std::cout << months.at(i-1) << " " << year << std::endl;
            std::cout << "  L  M  M  J  V  S  D" << std::endl;

            const int firstDay = zellerCongruence(1, static_cast<int>(i), year);
            const int dayInMonth = getDaysinMonth(static_cast<int>(i), year);
            printDays(firstDay,dayInMonth);

            std::cout << std::endl;
        }

        do {
            std::cout << "voulez-vous continuer [O|N] : ";
            std::cin >> restart;
        }while (restart != 'O' && restart != 'N' && restart != 'n' && restart != 'o');
    } while (restart=='o'||restart=='O');
    std::cout << "le programme est termine";
}
