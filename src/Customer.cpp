// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

double Customer::calculateAmount(Rental rental) {

    double amount = 0;

    switch (rental.getMovie().getPriceCode()) {
        case Movie::REGULAR:
            amount += 2;
            if (rental.getDaysRented() > 2)
                amount += (rental.getDaysRented() - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            amount += rental.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if (rental.getDaysRented() > 3)
                amount += (rental.getDaysRented() - 3) * 1.5;
            break;
    }

    return amount;
}

int Customer::addFrequentRenterPoints(Rental rental) {
    int frequentRenterPoints = 1;

    // add bonus for a two day new release rental
    if ((rental.getMovie().getPriceCode() == Movie::NEW_RELEASE)
        && rental.getDaysRented() > 1) {
        ++frequentRenterPoints;
    }

    return frequentRenterPoints;
}

string Customer::statement() {
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector<Rental>::iterator iter = _rentals.begin();
    vector<Rental>::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (; iter != iter_end; ++iter) {
        Rental thisRental = *iter;

        /* Determine amounts for each line */
        double thisAmount = calculateAmount(thisRental);

        /* Add frequent renter points */
        frequentRenterPoints += addFrequentRenterPoints(thisRental);

        // show figures for this rental
        result << "\t" << thisRental.getMovie().getTitle() << "\t" << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    
    return result.str();
}