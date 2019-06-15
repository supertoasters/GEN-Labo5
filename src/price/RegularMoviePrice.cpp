//
// Created by caroline on 15.06.19.
//

#include "RegularMoviePrice.h"

double RegularMoviePrice::movieType(int daysRented) {
    double amount = 2;

    if (daysRented > 2) {
        amount += (daysRented - 2) * 1.5;
    }

    return amount;
}
