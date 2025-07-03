#include <random>
#include <iostream>
#include "Universe.hxx"
#include "Particle.hxx"
#include "Vecteur.hxx"

int main() {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    int n = 1 << 5 << 3;

    std::vector<Particle> particles(n);

    Vecteur velocity = Vecteur(1, 0, 0);
    Vecteur force;

    for (size_t i = 0; i < n; i++)
    {
        double x, y, z;
        x = dist(mt);
        y = dist(mt);
        z = dist(mt);
        Vecteur pos = Vecteur(x, y, z);
        particles[i] = Particle(pos, velocity, force, 1.0, i, "test");
    }

    Universe u = Universe(n, particles);

    std::cout<<u<<std::endl;
    
    return 0;
}