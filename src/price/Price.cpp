
#include "Price.h"
#include "RegularMoviePrice.h"
#include "ChildrenMoviePrice.h"
#include "NewReleaseMoviePrice.h"


int Price::calculateFrequentRenterPoints(int daysRented) {
    return 1;
}


Price* Price::_regularMoviePrice = new RegularMoviePrice();
Price* Price::_childrenMoviePrice = new ChildrenMoviePrice();
Price* Price::_newReleaseMoviePrice = new NewReleaseMoviePrice();

Price* Price::setRegularMoviePrice() {
    return _regularMoviePrice;
}

Price* Price::setChildrenMoviePrice() {
    return _childrenMoviePrice;
}

Price* Price::setNewReleaseMoviePrice() {
    return _newReleaseMoviePrice;
}



