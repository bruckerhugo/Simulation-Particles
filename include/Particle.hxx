#pragma once

#include <string>
#include "Vecteur.hxx"
#include <vector>

class Particle
{
private:
    Vecteur pos, speed, force;
    double weight;
    int id;
    std::string type;
public:
    Particle(Vecteur pos,
            Vecteur speed,
            Vecteur force,
            double weight,
            int id,
            std::string type);
    bool operator<(const Particle& other) const;
    Vecteur getPos();
    Vecteur getSpe();
    Vecteur getFor();
    double getWeight();
    int getId();
    std::string getType();

    void setPos(Vecteur pos);
    void setSpe(Vecteur speed);
    void setFor(Vecteur force);
    ~Particle();
};
