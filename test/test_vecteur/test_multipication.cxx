#include "Vecteur.hxx"
#include <catch2/catch_all.hpp>

TEST_CASE("Vecteur: multiplication scalaire à gauche", "[vecteur]") {
    Vecteur v(1, 2, 3);
    Vecteur res = 2 * v;

    REQUIRE(res.getX() == 2);
    REQUIRE(res.getY() == 4);
    REQUIRE(res.getZ() == 6);
}
