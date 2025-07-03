#include "Vecteur.hxx"
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

TEST_CASE("Vecteur: construction avec valeurs", "[vecteur]") {
    Vecteur v(1.0, 2.0, 3.0);
    REQUIRE(v.getX() == 1.0);
    REQUIRE(v.getY() == 2.0);
    REQUIRE(v.getZ() == 3.0);
}