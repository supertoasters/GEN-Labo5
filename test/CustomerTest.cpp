#ifndef GENLAB05_CUSTOMERTEST_CPP
#define GENLAB05_CUSTOMERTEST_CPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Customer.h"
#include "../src/Movie.h"
#include "../src/Rental.h"

TEST(CustomerTest, simple) {
    const std::string CUSTOMER_NAME = "Darth Vader";
    const std::string MOVIE_NAME = "The Phantom Menace";
    const size_t DAYS_RENTED = 34;
    const size_t AMOUNT = 2 + (DAYS_RENTED - 2) * 1.5;

    Customer customer(CUSTOMER_NAME);
    customer.addRental( Rental( Movie( MOVIE_NAME, Movie::REGULAR ), DAYS_RENTED));

    std::string result = "Rental Record for " + CUSTOMER_NAME + "\n\t" + MOVIE_NAME + '\t' + std::to_string(AMOUNT) + "\nAmount owed is " + std::to_string(AMOUNT) + "\nYou earned 1 frequent renter points";

    ASSERT_EQ(customer.statement(),
                 result
    );
}




#endif //GENLAB05_CUSTOMERTEST_CPP
