#include <iostream>

#include "Customer.h"
#include "price/NewReleaseMoviePrice.h"
#include "price/ChildrenMoviePrice.h"

int main() {

    Customer customer("Olivier");
    customer.addRental(Rental(Movie("Karate Kid"), 7));
    customer.addRental(Rental(Movie("Avengers: Endgame", new NewReleaseMoviePrice()), 5));
    customer.addRental(Rental(Movie("Snow White", new ChildrenMoviePrice()), 3));

    std::cout << customer.statement() << std::endl;

    return 0;
}