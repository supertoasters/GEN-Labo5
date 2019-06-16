
#include "NewReleaseMoviePrice.h"

double NewReleaseMoviePrice::getPriceByType(int daysRented) {
    return daysRented * 3;
}

int NewReleaseMoviePrice::calculateFrequentRenterPoints(int daysRented) {
    if (daysRented > 1) {
        return 2;
    } else {
        return 1;
    }
}