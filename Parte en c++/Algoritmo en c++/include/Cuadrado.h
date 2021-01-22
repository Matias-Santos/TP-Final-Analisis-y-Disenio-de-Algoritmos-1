#ifndef CUADRADO_H
#define CUADRADO_H


class Cuadrado : public Rectangulo
{
    public:
        Cuadrado(Punto A,Punto B,Punto C,Punto D) : Rectangulo() {}
        virtual ~Cuadrado() {}
    double calcularArea()
    {
        double aux1=A.distancia(B);
        return aux1*aux1;
    }
    double calcularPerimetro()
    {
        double a=this->A.distancia(this->getB());
        return (a*4);
    }
};

#endif // CUADRADO_H
