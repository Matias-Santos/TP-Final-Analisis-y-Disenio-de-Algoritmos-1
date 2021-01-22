#ifndef POLIGONO_H
#define POLIGONO_H
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <iomanip>

using namespace std;

class Poligono: public Figura2D
{
private:
    struct ParDePuntos {
        Punto v1;
        Punto v2;
    };
    double **matriz=0;
    double ** matrizK=0;
    list<Punto> listaPuntos;
    vector<Punto> vectorPuntos;

    void agregar(Punto aAgregar)
    {
        listaPuntos.push_back(aAgregar);
    }
    void mostraraMatriz(double **matriz, int columna, int fila)
    {
        cout<<setw(10)<< matriz[fila][0]<< endl;
        for (int f = fila-1; f > 2; f--)
        {
            for (int c = 0; c < columna; c++)
                cout << setw(10) << matriz[f][c] << "  ";
            cout << "\n";
        }
        cout<<""<<endl;
    }

    void crearaMatriz(double ** & matriz,const int & columna,const int & fila)
    {
        matriz = new double*[fila];
        for (int f = 0; f <= fila; f++)
            matriz[f] = new double[columna];
    }

    //----------------------------Cargar Matriz vacia-------------------------

    void cargaraMatriz(double ** & matriz,const int & columna,const int & fila)
    {
        for(int i=0; i<=fila; i++)
            for(int j=0; j<columna; j++)
                    matriz[i][j]= 0;
    }
public:
    Poligono(list<Punto> aux): Figura2D()
    {
        list<Punto>:: iterator itp= aux.begin();
        for(itp=aux.begin(); itp!=aux.end(); itp++)
            {
                listaPuntos.push_back(*itp);
                vectorPuntos.push_back(*itp);
            }
    }

    void agregarPunto(Punto aAgregar)
    {
        agregar(aAgregar);
    }

    vector<Punto> devuelveCopiaEnVector()
    {
        vector<Punto> vecP;
        list<Punto>::iterator itp= listaPuntos.begin();
        for(int i=0;i<=this->sizePoligono();i++)
        {
            Punto a=*itp;
            vecP.push_back(a);
            itp++;
        }
        return vecP;
    }

    void trazarLineas(list<ParDePuntos> & lineas,int & s, int & k, int & i)
    {
        //calculo los vertices a agregar;
        k=matrizK[s][i];
        int v1,v2=0;
        if(((i+1)!=(i+k))&&((i-1)!=(i+k)))
        {
            cout<< "agrega la cuerda " << "V" << i << " y V" << i+k <<endl;
            ParDePuntos aux;
            Punto v1=vectorPuntos.at(i);
            aux.v1= v1;
            aux.v2= vectorPuntos.at(i+k);
            lineas.push_back(aux);
        }
        if(((i+s-1)!=(i+k+1))&&((i+s-1)!=(i+k-1)))
        {
            cout<< "agrega la cuerda: " << "V" << i+k << " y V" << i+s-1 <<endl;
            ParDePuntos aux;
            aux.v1= vectorPuntos.at(i+k);
            aux.v2= vectorPuntos.at(i+s-1);
            lineas.push_back(aux);
        }
        //llamo a las nuevas sol
        if(matrizK[k+1][i]!=0)
        {
            s=k+1;
            trazarLineas(lineas,s,k,i);
        }
        if(matrizK[s-k][i+k]!=0)
        {
            s=s-k;
            i=i+k;
            trazarLineas(lineas,s,k,i);
        }
    }

    double calcularArea()
    {
        double area=0;
        list<Punto>:: iterator itp=listaPuntos.begin();
        Punto inic= *itp;
        for (int i=0; i<listaPuntos.size()-1; i++)
        {
            Punto a=*itp;
            itp++;
            Punto b=*itp;
            area+=a.distancia(b);
        }
        Punto fin = *itp;
        area+=inic.distancia(fin);
        if(area < 0)
            return area*(-0.5);
        else
            return area*(0.5);
    }

    int sizePoligono()
    {
        return listaPuntos.size();
    }

    list<Punto> devolverCopiaEnLista()
    {

        list<Punto>:: iterator itp=listaPuntos.begin();
        list<Punto> copia;
        while(itp!= listaPuntos.end())
        {
            copia.push_back(*itp);
            itp++;
        }
        return copia;
    }

    double calcularPerimetro()
    {
        double perimetro=0;
        list<Punto>:: iterator itp=listaPuntos.begin();
        Punto inic= *itp;
        for (int i=0; i<listaPuntos.size()-1; i++)
        {
            Punto a=*itp;
            itp++;
            Punto b=*itp;
            perimetro+=a.distancia(b);
        }
        Punto fin = *itp;
        perimetro+=inic.distancia(fin);
        return perimetro;
    }

    virtual ~Poligono()
    {
        listaPuntos.clear();
    }

    double triangulacion()
    {
        int tam = listaPuntos.size();
        if(tam<4)
            return 0;

        //Pasaje de lista a vector
        vector<Punto> vecP=this->devuelveCopiaEnVector();

        //Inicializacion de la matriz
        crearaMatriz(matriz,tam,tam);
        cargaraMatriz(matriz,tam,tam);
        crearaMatriz(matrizK,tam,tam);
        cargaraMatriz(matrizK,tam,tam);
        //Algoritmo
        for(int s=4; s<=tam; s++)
            for(int i=0; i<tam; i++)
                for(int k=1; k<=s-2; k++)
                {
                    Punto a,b,c;
                    a = vecP.at(i);
                    double valorMat1,valorMat2,aux=0;
                    if(i+k > tam-1)
                    {
                        b=vecP.at(i+k-tam);
                        valorMat1=(matriz[k+1][i]);
                        valorMat2=(matriz[s-k][i+k-tam]);
                    }
                    else
                    {
                        b=vecP.at(i+k);
                        valorMat1=(matriz[k+1][i]);
                        valorMat2=(matriz[s-k][i+k]);
                    }
                    if(i+s-1 > tam-1)
                        c=vecP.at(i+s-1-tam);
                    else
                        c=vecP.at(i+s-1);
                    if((i+1==i+k)||(i-1==i+k))
                        aux=valorMat1+valorMat2+b.distancia(c);
                    else if(((i+k+1)==(i+s-1))||((i+k-1)==(i+s-1)))
                        aux=valorMat1+valorMat2+a.distancia(b);
                    else
                        aux=valorMat1+valorMat2+a.distancia(b)+b.distancia(c);
                    if((matriz[s][i]>= aux)||(matriz[s][i]==0))
                    {
                        matriz[s][i]=aux;
                        matrizK[s][i]=k;
                    }
                }
        mostraraMatriz(matriz,tam,tam);
        cout<<"------------------------------------------------------------------"<<endl;
        mostraraMatriz(matrizK,tam,tam);

        list<ParDePuntos> lineas;
        int s,k,i=0;
        s=7;
        trazarLineas(lineas,s,k,i);
        list<ParDePuntos>:: iterator itp= lineas.begin();
        while(itp!=lineas.end())
        {
            ParDePuntos aux=*itp;
            cout <<" vertices a trazar la cuerda : " << "("<<aux.v1.getX()<<","<< aux.v1.getY()<<")" << "  y  " << "("<<aux.v2.getX()<<","<< aux.v2.getY()<<")" << endl;
            itp++;
        }
        return matriz[tam][0];
    }
};

#endif // POLIGONO_H
