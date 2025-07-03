#include "Vecteur.hxx"
#include <catch2/catch_all.hpp>

TEST_CASE("Vecteur: addition", "[vecteur]") {
    Vecteur v1(1, 2, 3);
    Vecteur v2(4, 5, 6);
    Vecteur res = v1 + v2;

    REQUIRE(res.getX() == 5);
    REQUIRE(res.getY() == 7);
    REQUIRE(res.getZ() == 9);
}
