#ifndef PUNTO_H
#define PUNTO_H
#include <cmath>
#include <fstream>

using namespace std;

class Punto
{
private:
    double x;
    double y;

public:
    Punto()=default;
    Punto(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    const double getX()
    {
        return this->x;
    }
    const double getY()
    {
        return this->y;
    }
    const double distancia(Punto aux)
    {
        return sqrt( pow(this->getX()- aux.getX(),2) + pow(this->getY()- aux.getY(),2) );
    }
    bool operator==(Punto aux)
    {
        return ((this->getX()==aux.getX())&&(this->getY()==aux.getY()));
    }
    bool operator!=(Punto aux)
    {
        return ((this->getX()!=aux.getX())||(this->getY()!=aux.getY()));
    }
    Punto operator= (Punto aux)
    {
        this->x=aux.getX();
        this->y=aux.getY();
    }
    ostream & operator << (ostream &out)
    {
         out << "(" << this->getX() << ", " << this->getY() << ")";
         return out;
    }
    double productoCruzado(Punto aux)
    {
        return ((this->getX()*aux.getY())-(aux.getX()*this->getY()));
    }
};

#endif // PUNTO_H
