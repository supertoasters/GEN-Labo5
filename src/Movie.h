// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "price/Price.h"
#include "price/RegularMoviePrice.h"

class Movie {
public:

    Movie( const std::string& title, Price* movieTypePrice = new RegularMoviePrice() );

    Price* getPrice() const;
    //void setPriceCode( int arg );
    std::string getTitle() const;

private:
    std::string _title;
    Price* _priceCode;
};

#endif // MOVIE_H