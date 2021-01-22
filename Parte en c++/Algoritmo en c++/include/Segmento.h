#ifndef SEGMENTO_H
#define SEGMENTO_H
#include "Punto.h"

class Segmento
{
    private:
        Punto A;
        Punto B;
    public:
        Segmento(Punto A, Punto B)
        {
            if(A!=B)
            {
                this->A=A;
                this->B=B;
            }
        }
        const Punto getA()
        {
            return this->A;
        }
        const Punto getB()
        {
            return this->B;
        }
        double longitud()
        {
            return A.distancia(B);
        }
        virtual ~Segmento() {}

    protected:

};

#endif // SEGMENTO_H
