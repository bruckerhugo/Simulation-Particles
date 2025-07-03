#pragma once

#include "Particle.hxx"
#include <vector>
#include <ostream>

class Universe
{
private:
    unsigned int nbParticles;
    std::vector<Particle> Particles;
public:
    Universe(unsigned int nb, std::vector<Particle> Particles);
    unsigned int getNb() const;
    Particle getParticle(unsigned int i) const;
    void stromerVerlet(std::vector<Vecteur>& forces_old, 
                        std::vector<Vecteur>& forces_new, 
                        double delta_t);
    ~Universe();
};

std::ostream &operator<<(std::ostream &out, const Universe &u);
