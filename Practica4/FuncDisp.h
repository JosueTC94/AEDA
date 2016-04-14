#ifndef _FUNCDISP_H
#define _FUNCDISP_H
#pragma once

using namespace std;

class Modulo;

class FuncDisp
{
    public:

        FuncDisp(void){}

        ~FuncDisp(){}

        virtual int get_posicion(int clave, int nCeldas, int intento_) = 0;
};



class Modulo: public FuncDisp{
    public:
        Modulo(void)
        {}

        ~Modulo(){};

        int get_posicion(int clave, int nCeldas, int intento_)
        {
            intento_ = 0;
            cout << "Modulo..." << endl;
            cout << "Clave: " << clave << endl;
            cout << "Celdas: " << nCeldas << endl;
            int auxiliar = clave % nCeldas;
            return auxiliar;
        }
};

class Pseudoaleatoria: public FuncDisp
{
    public:

        Pseudoaleatoria(void){}
        ~Pseudoaleatoria(void){}

        int get_posicion(int clave, int nCeldas, int intento_)
        {
             intento_ = 0;
             srand(clave);
             return rand() % nCeldas;
        }
};

#endif
