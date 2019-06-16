
#ifndef GEN_LAB05_CHILDRENMOVIEPRICE_H
#define GEN_LAB05_CHILDRENMOVIEPRICE_H


#include "Price.h"

class ChildrenMoviePrice : public Price {
public:
    double getPriceByType(int daysRented);

};


#endif //GEN_LAB05_CHILDRENMOVIEPRICE_H
