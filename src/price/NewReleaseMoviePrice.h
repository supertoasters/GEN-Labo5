
#ifndef GEN_LAB05_NEWRELEASEMOVIEPRICE_H
#define GEN_LAB05_NEWRELEASEMOVIEPRICE_H


#include "Price.h"

class NewReleaseMoviePrice : public Price {
public:
    double getPriceByType(int daysRented);
    int calculateFrequentRenterPoints(int daysRented);

};


#endif //GEN_LAB05_NEWRELEASEMOVIEPRICE_H
