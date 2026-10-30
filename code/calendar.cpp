//
// Created by Joachim on 30.10.2026.
//

#include "calendar.h"

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

bool isLeapYear(const int year) { //O(1)
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

int getDaysinMonth(const int month, const int year) { //O(1)
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

        default:
            return 0; //manage err
    }
}