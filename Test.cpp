#include <iostream>
#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
Fraction f0 = Fraction();
Fraction f1 = Fraction(2,2);
Fraction f2 = Fraction(9,5);
Fraction f22 = Fraction(5,-7);

TEST_CASE("test 1 -- Fractoins init"){
    CHECK(f0 == 0);
    CHECK(f1 == 1);
    //check that the numerator get the minus
    CHECK(f22.numerator == -5);
    CHECK(f22.denominator == 7);
}
TEST_CASE("test 2 -- plus"){
    Fraction f3 = f0 + f1 + f2;
    CHECK(f3 == (14.0/5));
    //check that the fraction didnt change
    CHECK(f0 == 0);
    CHECK(f1 == 1);
}
TEST_CASE("test 3 -- minus"){
    Fraction f3 = f0 - f1 - f2;
    CHECK(f3 == -(14.0/5));
    //check that the fraction didnt change
    CHECK(f0 == 0);
    CHECK(f1 == 1);
}
TEST_CASE("test 4 -- mul"){
    Fraction f3 = f0 * f1 * f2;
    CHECK(f3 == 0);
    //check that the fraction didnt change
    CHECK(f0 == 0);
    CHECK(f1 == 1);
}
TEST_CASE("test 5 -- div"){
    //div by 0 med to throw an error
    CHECK_THROWS(f2/f0);
    Fraction f3 = f22/f2;
    CHECK(f3 == Fraction(-25,63));    
}
TEST_CASE("test 6 -- >,<,>=,<="){
    CHECK(f2 >= f0);
    CHECK(f1 <= f2);
    CHECK(f2 <= f2);
    CHECK(f2 >= f2);
}
TEST_CASE("test 7 -- prefix and postfix"){
    ++f0;
    f0++;
    CHECK(f0 == 2);
    --f0;
    f0--;
    CHECK(f0 == 0);
}