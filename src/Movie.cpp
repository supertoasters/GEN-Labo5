#include "Movie.h"

const int Movie::CHILDREN;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

Movie::
Movie( const std::string& title, Price* movieTypePrice )
        : _title( title )
        , _priceCode( movieTypePrice )
{}

Price* Movie::
getPrice() const { return _priceCode; }

//inline void Movie::
//setPriceCode( int arg ) { _priceCode = arg; }

std::string Movie::
getTitle() const { return _title; }
 