#include "Vecteur.hxx"
#include "Particle.hxx"
#include "Universe.hxx"

#include <vector>
#include <iostream>

int main() {
    Vecteur sunPos, sunSpeed, sunForce, earthForce, jupyterForce, haleyForce;
    Vecteur sunOld, earthOld, jupyterOld, haleyOld;

    Vecteur earthPos(0.0, 1.0, 0.0);
    Vecteur earthSpeed(-1.0, 0.0, 0.0);

    Vecteur jupyterPos(0.0, 5.36, 0.0);
    Vecteur jupyterSpeed(-0.425, 0.0, 0.0);

    Vecteur haleyPos(34.75, 0.0, 0.0);
    Vecteur haleySpeed(0.0, 0.0296, 0.0);

    Particle sun(sunPos, sunSpeed, sunForce, 1.0, 0, "Sun");
    Particle earth(earthPos, earthSpeed, earthForce, 3e-6, 1, "Earth");
    Particle jupyter(jupyterPos, jupyterSpeed, jupyterForce, 9.55e-4, 2, "Jupyter");
    Particle haley(haleyPos, haleySpeed, haleyForce, 1e-14, 3, "Haley");

    double delta_t = 0.015;
    double t_end = 468.5;

    std::vector<Particle> particles = {sun, earth, jupyter, haley};
    std::vector<Vecteur> f_old = {sunOld, earthOld, jupyterOld, haleyOld};
    std::vector<Vecteur> forces(f_old.size());

    Universe universe(particles.size(), particles);

    double t = 0;
    while (t < t_end) {
        std::cout << "t = " << t << universe << std::endl;

        universe.stromerVerlet(f_old, forces, delta_t);
        t += delta_t;
    }

    return 0;
}
