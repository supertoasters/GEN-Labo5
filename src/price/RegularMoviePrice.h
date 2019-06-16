
#ifndef GEN_LAB05_REGULARMOVIEPRICE_H
#define GEN_LAB05_REGULARMOVIEPRICE_H


#include "Price.h"

class RegularMoviePrice : public Price {
public:
    double getPriceByType(int daysRented);

};


#endif //GEN_LAB05_REGULARMOVIEPRICE_H
