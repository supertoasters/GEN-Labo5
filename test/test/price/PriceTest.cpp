
#ifndef GENLAB05_PRICETEST_CPP
#define GENLAB05_PRICETEST_CPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../../src/price/RegularMoviePrice.h"
#include "../../../src/price/ChildrenMoviePrice.h"
#include "../../../src/price/NewReleaseMoviePrice.h"

/**
 * Regular Movie price
 */
TEST(RegularTest, FrequentRenterPoints) {
    RegularMoviePrice regularMoviePrice;
    const size_t EXPECTED = 1, DAYS_RENTED = 5;

    ASSERT_EQ(regularMoviePrice.calculateFrequentRenterPoints(DAYS_RENTED),
              EXPECTED
    );
}

TEST(RegularTest, priceCheckSimple) {
    RegularMoviePrice regularMoviePrice;
    const double EXPECTED = 21.5;
    const size_t DAYS_RENTED = 15;

    ASSERT_EQ(regularMoviePrice.getPriceByType(DAYS_RENTED),
              EXPECTED
    );
}

/**
 * Children Movie price
 */
TEST(ChildrenTest, FrequentRenterPoints) {
    ChildrenMoviePrice childrenMoviePrice;
    const size_t EXPECTED = 1, DAYS_RENTED = 39;

    ASSERT_EQ(childrenMoviePrice.calculateFrequentRenterPoints(DAYS_RENTED),
              EXPECTED
    );
}


TEST(ChildrenTest, priceCheckSimple) {
    ChildrenMoviePrice childrenMoviePrice;
    const double EXPECTED = 19.5;
    const size_t DAYS_RENTED = 15;

    ASSERT_EQ(childrenMoviePrice.getPriceByType(DAYS_RENTED),
              EXPECTED
    );
}


/**
 * New Release Movie price
 */

TEST(NewReleaseTest, FrequentRenterPointsGreaterThanOne) {
    NewReleaseMoviePrice newReleaseMoviePrice;
    const size_t EXPECTED = 2, DAYS_RENTED = 8;

    ASSERT_EQ(newReleaseMoviePrice.calculateFrequentRenterPoints(DAYS_RENTED),
              EXPECTED
    );
}

TEST(NewReleaseTest, FrequentRenterPointsSimple) {
    NewReleaseMoviePrice newReleaseMoviePrice;
    const size_t EXPECTED = 1,  DAYS_RENTED = 1;

    ASSERT_EQ(newReleaseMoviePrice.calculateFrequentRenterPoints(DAYS_RENTED),
              EXPECTED
    );
}


TEST(NewReleaseTest, priceCheckSimple) {
    NewReleaseMoviePrice newReleaseMoviePrice;
    const double EXPECTED = 45.0;
    const size_t DAYS_RENTED = 15;

    ASSERT_EQ(newReleaseMoviePrice.getPriceByType(DAYS_RENTED),
              EXPECTED
    );
}



int main(int argc, char** argv) {
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif //GENLAB05_PRICETEST_CPP
