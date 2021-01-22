#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo : public Figura2D
{

protected:
    Punto A;
    Punto B;
    Punto C;
    Punto D;

public:
    Rectangulo() {};
    Rectangulo(Punto A,Punto B,Punto C,Punto D) : Figura2D()
    {
        if(((A.distancia(B)==A.distancia(C)) && (A.distancia(B)!=A.distancia(D)))||((A.distancia(B)==A.distancia(D)) && (A.distancia(B)!=A.distancia(C)))||((A.distancia(C)==A.distancia(D)) && (A.distancia(C)!=A.distancia(B))))
        {
            this->A=A;
            this->B=B;
            this->C=C;
            this->D=D;
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
    const Punto getC()
    {
        return this->C;
    }
    const Punto getD()
    {
        return this->D;
    }
    double calcularArea()
    {
        double aux1=A.distancia(B);
        double aux2=B.distancia(C);
        return aux1*aux2;
    }
    double calcularPerimetro()
    {
        double a=this->A.distancia(this->getB());
        double b=this->B.distancia(this->getC());
        return ((a+b)*2);
    }
};

#endif // RECTANGULO_H
