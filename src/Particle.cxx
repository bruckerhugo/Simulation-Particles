#include "Particle.hxx"

Particle::Particle(Vecteur pos,
            Vecteur speed,
            Vecteur force,
            double weight,
            int id,
            std::string type)
{
    this->pos = pos;
    this->speed = speed;
    this->force = force;
    this->weight = weight;
    this->id = id;
    this->type = type;
}

Particle::~Particle()
{
}

Vecteur Particle::getPos() {
    return this->pos;
}

Vecteur Particle::getSpe() {
    return this->speed;
}

Vecteur Particle::getFor() {
    return this->force;
}

double Particle::getWeight() {
    return this->weight;
}

int Particle::getId() {
    return this->id;
}

std::string Particle::getType() {
    return this->type;
}

void Particle::setPos(Vecteur pos) {
    this->pos = pos;
}

void Particle::setSpe(Vecteur speed) {
    this->speed = speed;
}

void Particle::setFor(Vecteur force) {
    this->force=force;
}

