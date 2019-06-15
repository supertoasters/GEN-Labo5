#include "Movie.h"

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

int Movie::getPriceCode() const {
    return _priceCode;
}

void Movie::setPriceCode(int arg) {
    _priceCode = arg;
}

std::string Movie::getTitle() const {
    return _title;
}
 