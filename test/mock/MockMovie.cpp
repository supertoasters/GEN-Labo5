//
// Created by baribal on 6/16/19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/Movie.h"



class MockMovie : public Movie {
public:

    MockMovie(const std::string& title) : Movie(title) {}


    MOCK_CONST_METHOD1(calculateAmount, double(int daysRented));
};