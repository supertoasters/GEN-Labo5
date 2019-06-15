// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "price/Price.h"
#include "price/RegularMoviePrice.h"

class Movie {
public:
    static const int CHILDREN    = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    Movie( const std::string& title, Price* movieTypePrice = new RegularMoviePrice() );

    Price* getPrice() const;
    //void setPriceCode( int arg );
    std::string getTitle() const;

private:
    std::string _title;
    Price* _priceCode;
};

inline Movie::
Movie( const std::string& title, Price* movieTypePrice )
        : _title( title )
        , _priceCode( movieTypePrice )
{}

inline Price* Movie::
getPrice() const { return _priceCode; }

//inline void Movie::
//setPriceCode( int arg ) { _priceCode = arg; }

inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H