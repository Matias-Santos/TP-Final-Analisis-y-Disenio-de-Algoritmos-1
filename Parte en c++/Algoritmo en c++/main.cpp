#include "Punto.h"
#include "Figura2D.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Segmento.h"
#include "Poligono.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

 struct ParDePuntos {
        Punto v1;
        Punto v2;
    };

int main()
{
    Punto a0(85,25);
    Punto a1(29,70);
    Punto a2(26,106);
    Punto a3(22,171);
    Punto a4(12,348);
    Punto a5(16,375);
    Punto a6(27,430);
    Punto a7(47,441);
    Punto a8(117,444);
    Punto a9(303,435);
    Punto a10(333,424);
    Punto a11(371,396);
    Punto a12(393,346);
    Punto a13(404,312);
    Punto a14(409,262);
    Punto a15(415,197);
    Punto a16(418,143);
    Punto a17(411,105);
    Punto a18(390,51);
    Punto a19(375,26);
    Punto a20(310,13);
    Punto a21(234,9);
    Punto a22(200,8);
    list<Punto> auxP;
    auxP.push_back(a0);
    auxP.push_back(a1);
    auxP.push_back(a2);
    auxP.push_back(a3);
    auxP.push_back(a4);
    auxP.push_back(a5);
    auxP.push_back(a6);
    auxP.push_back(a7);
    auxP.push_back(a8);
    auxP.push_back(a9);
    auxP.push_back(a10);
    auxP.push_back(a11);
    auxP.push_back(a12);
    auxP.push_back(a13);
    auxP.push_back(a14);
    auxP.push_back(a15);
    auxP.push_back(a16);
    auxP.push_back(a17);
    auxP.push_back(a18);
    auxP.push_back(a19);
    auxP.push_back(a20);
    auxP.push_back(a21);
    auxP.push_back(a22);

    Punto v0(0,10);
    Punto v1(0,20);
    Punto v2(8,26);
    Punto v3(15,26);
    Punto v4(27,21);
    Punto v5(22,12);
    Punto v6(10,0);

    list<Punto> lisPuntos;
    lisPuntos.push_back(v0);
    lisPuntos.push_back(v1);
    lisPuntos.push_back(v2);
    lisPuntos.push_back(v3);
    lisPuntos.push_back(v4);
    lisPuntos.push_back(v5);
    lisPuntos.push_back(v6);
    Poligono * p=new Poligono(lisPuntos);
    Poligono * p2=new Poligono(auxP);
    cout<< "costo de la triangulacion minima:  " << p->triangulacion()<< endl;
    //cout<< "costo de la triangulacion minima:  " << p2->triangulacion()<< endl;
    return 0;
}

