// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer() {}

Customer::Customer(const std::string &name) : _name(name) {}

void Customer::addRental(const Rental &arg) {
    _rentals.push_back(arg);
}

std::string Customer::getName() const {
    return _name;
}

string Customer::statement() {
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (auto iter = _rentals.begin(); iter != _rentals.end(); ++iter) {
        Rental thisRental = *iter;

        /* Determine amounts for each line */
        totalAmount += thisRental.calculateAmount();

        /* Add frequent renter points */
        frequentRenterPoints += thisRental.addFrequentRenterPoints();

        // show figures for this rental
        result << "\t" << thisRental.getMovie().getTitle() << "\t" << thisRental.calculateAmount() << "\n";
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";

    return result.str();
}