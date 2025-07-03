#pragma once

#include <vector>
#include "Particle.hxx"
#include "Vecteur.hxx"

void stromerVerlet(std::vector<Particle>& particles,
                   std::vector<Vecteur>& forces_old,
                   double delta_t, double t_end);
