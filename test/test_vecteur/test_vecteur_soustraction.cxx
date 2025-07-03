#include "Vecteur.hxx"
#include <catch2/catch_all.hpp>

TEST_CASE("Vecteur: soustraction", "[vecteur]") {
    Vecteur v1(4, 5, 6);
    Vecteur v2(1, 2, 3);
    Vecteur res = v1 - v2;

    REQUIRE(res.getX() == 3);
    REQUIRE(res.getY() == 3);
    REQUIRE(res.getZ() == 3);
}