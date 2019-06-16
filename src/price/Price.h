
#ifndef GEN_LAB05_PRICE_H
#define GEN_LAB05_PRICE_H


class Price {
public:
    virtual double getPriceByType(int daysRented) = 0;
    int calculateFrequentRenterPoints(int daysRented);

};


#endif //GEN_LAB05_PRICE_H
