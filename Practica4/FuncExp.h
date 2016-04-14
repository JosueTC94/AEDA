#ifndef _FUNCEXP_H
#define _FUNCEXP_H
#pragma once

#include <iostream>

using namespace std;

class Lineal;

class FuncExp
{
    public:

        FuncExp(void){}

        ~FuncExp(){}

        virtual int get_posicion(int clave, int nCeldas, int intento_) = 0;
};



class Lineal: public FuncExp
{
    public:
        Lineal(void)
        {}

        ~Lineal(){};

        int get_posicion(int clave, int nCeldas, int intento_)
        {
            cout << "Lineal..." << endl;
            cout << "Clave: " << clave << endl;
            cout << "Celdas: " << nCeldas << endl;
            int auxiliar = (clave + intento_) % nCeldas;
            return auxiliar;
        }
};

class Cuadratica: public FuncExp
{
  public:
    Cuadratica(void)
    {}

    ~Cuadratica(){};

    int get_posicion(int clave, int nCeldas, int intento_)
    {
        cout << "Cuadratica..." << endl;
        cout << "Clave: " << clave << endl;
        cout << "Celdas: " << nCeldas << endl;
        int auxiliar = (clave + (intento_*intento_)) % nCeldas;
        return auxiliar;
    }
};


class Dispersion_doble: public FuncExp
{
  public:
  Dispersion_doble(void){}

  ~Dispersion_doble(){};

  int get_posicion(int clave, int nCeldas, int intento_)
  {
    //Segunda función de dispersión --> Pseudoaleatoria
    srand(clave);
    int fx = rand() % nCeldas;
    int auxiliar = (clave + intento_ * fx) % nCeldas;
    return auxiliar;
  }
};

/*
class Re_dispersion: public FuncExp
{
  public:
  Re_dispersion(void){}

  ~Re_dispersion(){};

  int get_posicion(int clave, int nCeldas, int intento_)
  {
    //Suma de los digitos
    int fx = 1;
    int auxiliar = (clave + intento_ * fx) % nCeldas;
    return auxiliar;
  }
};
*/

#endif
