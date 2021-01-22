#ifndef CIRCULO_H
#define CIRCULO_H
#include <cmath>

class Circulo : public Figura2D
{
private:
    Punto centro;
    double radio;
public:
    Circulo(Punto centro,double radio): Figura2D()
    {
        this->centro=centro;
        this->radio=radio;
    }
    const Punto getCentro()
    {
        return this->centro;
    }
    const double getRadio()
    {
        return this->radio;
    }
    double calcularArea()
    {
        return (M_PI * pow(this->getRadio(),2));
    }
    double calcularPerimetro()
    {
        return (2*M_PI*this->getRadio());
    }
protected:

};

#endif // CIRCULO_H
