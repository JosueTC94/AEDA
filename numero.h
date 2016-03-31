#ifndef _NUMERO_H
#define _NUMERO_H

#pragma once
#include <iostream>

using namespace std;

//class Complejo;
//class Racional;
class Entero;
class Real;

class Numero
{

    public:

    virtual const Entero toEntero() const = 0;
    virtual const Real toReal() const = 0;

    virtual Numero& operator+(const Numero &b) const = 0;
    virtual Numero& operator-(const Numero &b) const = 0;
    virtual Numero& operator/(const Numero &b) const = 0;
    virtual Numero& operator*(const Numero &b) const = 0;

    //virtual const Racional toRacional() const =0;
    //virtual const Complejos toComplejo() const=0;

    //Escribe una Numero al flujo sout
    virtual ostream& toStream(ostream& sout) const = 0;
    //Lee un Numero desde flujo sin
    virtual istream& fromStream(istream& sin) = 0;

    //Sobrecarga de operadores << y >>

    //Operadores +,-,*,/

    //Friend
    friend ostream& operator << (ostream& sout, const Numero& n);
    friend istream& operator >>(istream& sin, Numero& n);
};

#endif
