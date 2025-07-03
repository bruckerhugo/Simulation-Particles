#include "Vecteur.hxx"
#include "Particle.hxx"
#include <vector>
#include "Integrateur.hxx"

int main() {
    Vecteur sunPos, sunSpeed, sunForce, earthForce, jupyterForce, haleyForce, sunOld, earthOld, jupyterOld, haleyOld;
    Vecteur earthPos = Vecteur(0.0, 1.0, 0.0);
    Vecteur earthSpeed = Vecteur(-1.0, 0.0, 0.0);
    Vecteur jupyterPos = Vecteur(0.0, 5.36, 0.0);
    Vecteur jupyterSpeed = Vecteur(-0.425, 0.0, 0.0);
    Vecteur haleyPos = Vecteur(34.75, 0.0, 0.0);
    Vecteur haleySpeed = Vecteur(0.0, 0.0296, 0.0);
    Particle sun = Particle(sunPos, sunSpeed, sunForce, 1.0, 0, "Sun");
    Particle earth = Particle(earthPos, earthSpeed, earthForce, 3e-6, 1, "Earth");
    Particle jupyter = Particle(jupyterPos, jupyterSpeed, jupyterForce, 9.55e-4, 2, "Jupyter");
    Particle haley = Particle(haleyPos, haleySpeed, haleyForce, 1e-14, 3, "Haley");
    double delta_t = 0.015;
    double t_end = 468.5;
    std::vector<Particle> particles = {sun, earth, jupyter, haley};
    std::vector<Vecteur> f_old = {sunOld, earthOld, jupyterOld, haleyOld};
    stromerVerlet(particles, f_old, delta_t, t_end);
    
    return 0;
}