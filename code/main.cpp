#include <iostream>

#include "display.h"

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

bool continueProgram() {
    char restart = 'N';
    do {
        std::cout << "voulez-vous continuer [O|N] : ";
        std::cin >> restart;
    } while (restart != 'O' && restart != 'N' && restart != 'n' && restart != 'o');
    return restart == 'O' || restart == 'o';
}

int main() {
    do {
        const int year = getYear();
        printCalendar(year);
    } while (continueProgram());
    std::cout << "le programme est termine";
}
