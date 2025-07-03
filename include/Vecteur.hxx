#pragma once

#include <ostream>

class Vecteur
{
private:
    double x, y, z;
public:
    double getX() const;
    double getY() const;
    double getZ() const;
    Vecteur();
    Vecteur(double x, double y, double z);
    Vecteur &operator +=(const Vecteur &other);
    Vecteur &operator -=(const Vecteur &other);
    Vecteur &operator *=(const double lamda);
    ~Vecteur();
};

std::ostream& operator <<(std::ostream &out, const Vecteur &v);
Vecteur operator +(const Vecteur &v1, const Vecteur &v2);
Vecteur operator -(const Vecteur &v1, const Vecteur &v2);
Vecteur operator *(const double lamda, const Vecteur &v);
