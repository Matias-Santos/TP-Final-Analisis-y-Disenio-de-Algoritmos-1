#ifndef FIGURA2D_H
#define FIGURA2D_H
#include "Punto.h"
#include <list>

class Figura2D
{
public:
    Figura2D()=default;
    virtual double calcularArea() {};
    virtual double calcularPerimetro() {};
protected:

private:
};

#endif // FIGURA2D_H
