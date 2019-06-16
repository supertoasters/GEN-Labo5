
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../mock/MockMovie.cpp"
#include "../../src/Rental.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


const size_t DAYS_RENTED = 3;
const double EXPECTED_AMOUNT = 3.5;


TEST(TestRental, AmountComputation) {
    const std::string MOVIE_TITLE = "The Phantom Menace";

    MockMovie movie(MOVIE_TITLE);
    Rental rental(movie, DAYS_RENTED);
    ASSERT_EQ(rental.calculateAmount() , EXPECTED_AMOUNT);
}

TEST(TestRental, Title) {
    const std::string MOVIE_TITLE = "The Phantom Menace";


    MockMovie movie(MOVIE_TITLE);
    Rental rental(movie, DAYS_RENTED);
    ASSERT_EQ(MOVIE_TITLE, rental.getMovie().getTitle());
}


TEST(TestRental, Statement) {
    const std::string MOVIE_TITLE = "The Phantom Menace";

    MockMovie movie(MOVIE_TITLE);
    Rental rental(movie, DAYS_RENTED);

    EXPECT_CALL(movie, calculateAmount(DAYS_RENTED)).WillRepeatedly(Return(EXPECTED_AMOUNT));

    // create an output string stream
    std::ostringstream streamObj;
    // add caracter, double and string to stream
    streamObj <<  "\tThe Phantom Menace\t" << EXPECTED_AMOUNT << '\n';
    ASSERT_EQ(rental.statement(), streamObj.str());
}


