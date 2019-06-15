// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer() {}

Customer::Customer( const std::string& name ) : _name( name ) {}

void Customer::addRental( const Rental& arg ) {
    _rentals.push_back( arg );
}

std::string Customer::getName() const {
    return _name;
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
        double thisAmount = thisRental.calculateAmount();

        /* Add frequent renter points */
        frequentRenterPoints += thisRental.addFrequentRenterPoints();

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