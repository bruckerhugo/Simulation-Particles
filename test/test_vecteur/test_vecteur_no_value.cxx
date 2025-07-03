#include "Vecteur.hxx"
#include <catch2/catch_all.hpp>

TEST_CASE("Vecteur: construction sans valeurs", "[vecteur]") {
    Vecteur v;
    REQUIRE(v.getX() == 0);
    REQUIRE(v.getY() == 0);
    REQUIRE(v.getZ() == 0);
}