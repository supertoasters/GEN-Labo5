#include "../../src/price/RegularMoviePrice.h"
#include "gmock/gmock.h"

class MockRegularMoviePrice : public RegularMoviePrice {
public:
    MOCK_METHOD1( getPriceByType, double(int daysRented) );
};