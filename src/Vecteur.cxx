#include "Vecteur.hxx"
#include <iostream>

Vecteur::Vecteur(double x, double y, double z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

Vecteur::Vecteur() {
    this->x=0;
    this->y=0;
    this->z=0;
}

Vecteur::~Vecteur() {}

double Vecteur::getX() const {
    return this->x;
}

double Vecteur::getY() const {
    return this->y;
}

double Vecteur::getZ() const {
    return this->z;
}

Vecteur &Vecteur::operator+=(const Vecteur &other) {
    this->x+=other.getX();
    this->y+=other.getY();
    this->z+=other.getZ();
    return *this;
}

Vecteur &Vecteur::operator-=(const Vecteur &other) {
    this->x-=other.getX();
    this->y-=other.getY();
    this->z-=other.getZ();
    return *this;
}

Vecteur &Vecteur::operator*=(double lamda) {
    this->x*=lamda;
    this->y*=lamda;
    this->z*=lamda;
    return *this;
}

Vecteur operator +(const Vecteur &v1, const Vecteur&v2) {
    double x = v1.getX()+v2.getX();
    double y = v1.getY()+v2.getY();
    double z = v1.getZ()+v2.getZ();
    return Vecteur(x, y, z);
}

Vecteur operator -(const Vecteur &v1, const Vecteur&v2) {
    double x = v1.getX()-v2.getX();
    double y = v1.getY()-v2.getY();
    double z = v1.getZ()-v2.getZ();
    return Vecteur(x, y, z);
}

Vecteur operator *(const double lamda, const Vecteur &v) {
    return Vecteur(lamda*v.getX(), lamda*v.getY(), lamda*v.getZ());
}

std::ostream& operator <<(std::ostream &out, const Vecteur &v) {
    out << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return out;
}

