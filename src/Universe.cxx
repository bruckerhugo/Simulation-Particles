#include "Universe.hxx"
#include <cmath>
#include <iostream>

Universe::Universe(unsigned int nb, std::vector<Particle> Particles)
{
    this->nbParticles = nb;
    this->Particles = Particles;
}

Universe::Universe(unsigned int nb) : Particles(nb), nbParticles(nb)
{}

Universe::~Universe()
{
}

unsigned int Universe::getNb() const {
    return this->nbParticles;
}

Particle Universe::getParticle(unsigned int i) const {
    return this->Particles[i];
}

void Universe::stromerVerlet(std::vector<Vecteur>& forces_old, 
                            std::vector<Vecteur>& forces_new,
                            double delta_t)
{

    for (size_t i = 0; i < Particles.size(); i++) {
        Vecteur pos = Particles[i].getPos();
        Vecteur spe = Particles[i].getSpe();
        double wei = Particles[i].getWeight();
        Particles[i].setPos(pos + delta_t * (spe + 0.5 / wei * delta_t * forces_old[i]));
        forces_old[i] = forces_new[i];
    }

    for (size_t i = 0; i < Particles.size(); i++) {
        for (size_t j = 0; j < Particles.size(); j++) {
            if (i != j) {
                Vecteur iv = Particles[i].getPos();
                Vecteur jv = Particles[j].getPos();
                double iweight = Particles[i].getWeight(), jweight = Particles[j].getWeight();
                double dst = sqrt(pow(jv.getX() - iv.getX(), 2)
                                + pow(jv.getY() - iv.getY(), 2)
                                + pow(jv.getZ() - iv.getZ(), 2));
                forces_new[i] += iweight * jweight / pow(dst, 3) * (jv - iv);
            }
        }
    }

    for (size_t i = 0; i < Particles.size(); i++) {
        Vecteur spe = Particles[i].getSpe();
        double wei = Particles[i].getWeight();
        Particles[i].setSpe(spe + delta_t * 0.5 / wei * (forces_new[i] + forces_old[i]));
    }
}

std::ostream& operator<<(std::ostream& out, const Universe &u) {
    for (int i=0; i<u.getNb(); i++) {
        Particle p = u.getParticle(i);
        out << " " << p.getType() << ": " << p.getPos();
    }
    return out;
}
