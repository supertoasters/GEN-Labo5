
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../mock/price/MockRegularMoviePrice.cpp"
#include "../../src/Movie.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(TestMovie, simple){
    const std::string MOVIE_TITLE = "The Phantom Menace";

    MockRegularMoviePrice mock;
    EXPECT_CALL(mock, getPriceByType(_)).WillRepeatedly(Return(21.5));

    Movie movie(MOVIE_TITLE, &mock);


    ASSERT_EQ(MOVIE_TITLE, movie.getTitle());
    ASSERT_EQ(21.5, movie.getPrice()->getPriceByType(15));

}