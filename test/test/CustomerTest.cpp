
#ifndef GENLAB05_CUSTOMERTEST_CPP
#define GENLAB05_CUSTOMERTEST_CPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/Customer.h"
#include "../../src/Movie.h"
#include "../../src/Rental.h"
#include "../mock/MockMovie.cpp"
#include "../mock/MockRental.cpp"

using ::testing::Return;

TEST(CustomerTest, checkStatement) {
    const std::string CUSTOMER_NAME = "Darth Vader";
    const std::string MOVIE_TITLE = "The Phantom Menace";
    const size_t DAYS_RENTED = 34;
    const size_t EXPECTED_AMOUNT = 2 + (DAYS_RENTED - 2) * 1.5;
    const size_t FREQUENT_RENTER_POINTS = 3;


    Customer customer(CUSTOMER_NAME);
    MockMovie mockMovie(MOVIE_TITLE);
    MockRental mockRental(mockMovie, (int) DAYS_RENTED);
    customer.addRental(mockRental);

    EXPECT_CALL(mockRental, statement()).WillRepeatedly(Return("\tThe Phantom Menace\t50\n"));
    EXPECT_CALL(mockRental, calculateAmount()).WillRepeatedly(Return(EXPECTED_AMOUNT));
    EXPECT_CALL(mockRental, addFrequentRenterPoints()).WillRepeatedly(Return(FREQUENT_RENTER_POINTS));


    std::string result = "Rental Record for " + CUSTOMER_NAME + "\n" + "\tThe Phantom Menace\t50\n"  +
                         "Amount owed is " + std::to_string(EXPECTED_AMOUNT) + "\nYou earned 1 frequent renter points";

    ASSERT_EQ(customer.statement(),
              result
    );
}




#endif //GENLAB05_CUSTOMERTEST_CPP
