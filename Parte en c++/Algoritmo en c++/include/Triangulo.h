#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Punto.h"
#include <cmath>

class Triangulo : public Figura2D
{
private:
    Punto A;
    Punto B;
    Punto C;
public:
    Triangulo(Punto A,Punto B,Punto C): Figura2D()
    {
        if((A!=B)&&(A!=C)&&(B!=C))
        {
            this->A=A;
            this->B=B;
            this->C=C;
        }
    };
    const Punto getExtA()
    {
        return this->A;
    }
    const Punto getExtB()
    {
        return this->B;
    }
    const Punto getExtC()
    {
        return this->C;
    }
    double calcularArea()
    {
        double a=this->A.distancia(this->getExtB());
        double b=this->A.distancia(this->getExtC());
        double c=this->B.distancia(this->getExtC());
        double s= (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    };
    double calcularPerimetro()
    {
        double a=this->A.distancia(this->getExtB());
        double b=this->A.distancia(this->getExtC());
        double c=this->B.distancia(this->getExtC());
        return a+b+c;
    }
};
#endif // TRIANGULO_H
