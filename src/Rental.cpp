
#include <sstream>
#include "Rental.h"

Rental::Rental(const Movie &movie, int daysRented)
        : _movie(movie), _daysRented(daysRented) {}

int Rental::getDaysRented() const {
    return _daysRented;
}

const Movie &Rental::getMovie() const {
    return _movie;
}

double Rental::calculateAmount() {
    return _movie.calculateAmount(_daysRented);
}

int Rental::addFrequentRenterPoints() {
    return _movie.calculateFrequentRenterPoints(_daysRented);
}

std::string Rental::statement()  {
    // create an output string stream
    std::ostringstream streamObj;
    // add caracter, double and string to stream
    streamObj << "\t" << getMovie().getTitle() << "\t" << calculateAmount() << "\n";
    return streamObj.str();
}


