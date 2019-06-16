//
// Created by baribal on 6/16/19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/Rental.h"
class MockRental : public Rental {
public:

    MockRental(const Movie& movie, int daysRented) : Rental(movie, daysRented) {}
    MOCK_CONST_METHOD0(statement, std::string());
    MOCK_CONST_METHOD0(calculateAmount, double());
    MOCK_CONST_METHOD0(addFrequentRenterPoints, int());
};