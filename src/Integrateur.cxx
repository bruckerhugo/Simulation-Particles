#include "Integrateur.hxx"
#include <cmath>
#include <iostream>

void stromerVerlet(std::vector<Particle>& particles,
                   std::vector<Vecteur>& forces_old,
                   double delta_t, double t_end)
{
    double t = 0;
    std::vector<Vecteur> forces(forces_old.size());

    while (t < t_end) {
        for (size_t i = 0; i < particles.size(); i++) {
            Vecteur pos = particles[i].getPos();
            Vecteur spe = particles[i].getSpe();
            double wei = particles[i].getWeight();
            particles[i].setPos(pos + delta_t * (spe + 0.5 / wei * delta_t * forces_old[i]));
            forces_old[i] = forces[i];
        }

        for (size_t i = 0; i < particles.size(); i++) {
            for (size_t j = 0; j < particles.size(); j++) {
                if (i != j) {
                    Vecteur iv = particles[i].getPos();
                    Vecteur jv = particles[j].getPos();
                    double iweight = particles[i].getWeight(), jweight = particles[j].getWeight();
                    double dst = sqrt(pow(jv.getX() - iv.getX(), 2)
                                    + pow(jv.getY() - iv.getY(), 2)
                                    + pow(jv.getZ() - iv.getZ(), 2));
                    forces[i] += iweight * jweight / pow(dst, 3) * (jv - iv);
                }
            }
        }

        for (size_t i = 0; i < particles.size(); i++) {
            Vecteur spe = particles[i].getSpe();
            double wei = particles[i].getWeight();
            particles[i].setSpe(spe + delta_t * 0.5 / wei * (forces[i] + forces_old[i]));
        }

        std::cout << "t = " << t;
        for (auto& p : particles) {
            std::cout << " " << p.getType() << ": " << p.getPos();
        }
        std::cout << std::endl;

        t += delta_t;
    }
}
