
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "price/Price.h"
#include "price/RegularMoviePrice.h"

class Movie {
public:

    Movie( const std::string& title, Price* movieTypePrice = new RegularMoviePrice() );

    Price* getPrice() const;
    std::string getTitle() const;
    double calculateAmount(int daysRented);
    int calculateFrequentRenterPoints(int daysRented);

private:
    std::string _title;
    Price* _priceCode;
};

#endif // MOVIE_H