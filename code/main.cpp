#include <iostream>
#include <limits>

#include "display.h"

int getYear();
bool continueProgram();

int getYear() {
    constexpr int min_year = 1800;
    constexpr int max_year = 2100;

    int year;
    do {
        std::cout << "entrer une valeur [" << min_year << " - " << max_year << "] : ";
        std::cin >> year;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (year < min_year || year > max_year) {
            std::cout << "/!\\ erreur de saisie\n";
        }
    } while (year < min_year || year > max_year);

    return year;
}

bool continueProgram() {
    constexpr char continue1 = 'O', continue2 = 'o';
    constexpr char stop1 = 'N', stop2 = 'n';
    char restart = 'N'; //base value
    do {
        std::cout << "Voulez-vous continuer [" << continue1 << "|" << stop1 << "] : ";
        std::cin >> restart;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (restart != continue1 && restart != stop1 && restart != stop2 && restart != continue2);
    return restart == continue1 || restart == continue2;
}

int main() {
    do {
        const int year = getYear();
        printCalendar(year);
    } while (continueProgram());
    std::cout << "le programme est termine";
}
