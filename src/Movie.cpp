#include "Movie.h"

Movie::Movie( const std::string& title, Price* movieTypePrice )
        : _title( title )
        , _priceCode( movieTypePrice )
{}

Price* Movie::getPrice() const {
    return _priceCode;
}

//inline void Movie::
//setPriceCode( int arg ) { _priceCode = arg; }

std::string Movie::getTitle() const {
    return _title;
}

double Movie::calculateAmount(int daysRented) {
    return _priceCode->getPriceByType(daysRented);
}
int Movie::calculateFrequentRenterPoints(int daysRented) {
    return _priceCode->calculateFrequentRenterPoints(daysRented);
}