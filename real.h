#ifndef _REAL_H
#define _REAL_H

#pragma once
#include "numero.h"
#include <iostream>

using namespace std;

class Entero;
class Racional;

class Real: public Numero
{

    float valor;

    public:
    //Constructor
    Real();
    Real(float v);
    //Destructor
    ~Real();

    void set_dato(float n);
    float get_dato(void);

    //Devuelve una copia del Número actual en el tipo Real
    const Entero toEntero() const;
    const Real toReal() const;
    const Racional toRacional() const;
    //const Complejo toComplejo() const;


    //Escribe una Numero al flujo sout
    ostream& toStream(ostream& sout) const;
    //Lee un Numero desde flujo sin
    istream& fromStream(istream& sin);

    //Operadores
    Numero& operator+(const Numero &b) const;
    Numero& operator-(const Numero &b) const;
    Numero& operator/(const Numero &b) const;
    Numero& operator*(const Numero &b) const;

};

#endif
