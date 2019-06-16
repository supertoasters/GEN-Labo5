
#ifndef GEN_LAB05_PRICE_H
#define GEN_LAB05_PRICE_H


class Price {
public:
    /*
    static Price* _regularMoviePrice;
    static Price* _childrenMoviePrice;
    static Price* _newReleaseMoviePrice;

    static Price* setRegularMoviePrice();
    static Price* setChildrenMoviePrice();
    static Price* setNewReleaseMoviePrice();
     */


    virtual double getPriceByType(int daysRented) = 0;
    int calculateFrequentRenterPoints(int daysRented);


};


#endif //GEN_LAB05_PRICE_H
