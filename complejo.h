#ifndef _Complejo_H
#define _Complejo_H

#pragma once
#include "numero.h"
#include <iostream>

using namespace std;

class Real;
class Entero;
class Racional;

typedef float d_Complejo;

class Complejo: public Numero
{
  	d_Complejo real;
  	d_Complejo imaginaria;
  	bool signo;
  	char variable_imaginaria;

  public:
  	 Complejo();
  	 Complejo(d_Complejo real_,d_Complejo imaginaria_);
  	 ~Complejo();
  	 d_Complejo get_real(void);
  	 d_Complejo get_imaginaria(void);
  	 void set_real(d_Complejo real_);
  	 void set_imaginaria(d_Complejo imaginaria_);

     //operadores
     const Entero toEntero() const;
     const Real toReal() const;
     const Racional toRacional() const;
     const Complejo toComplejo() const;

     Numero& operator+(const Numero &b) const;
 	   Numero& operator-(const Numero &b) const;
 	   Numero& operator/(const Numero &b) const;
 	   Numero& operator*(const Numero &b) const;

     //Escribe una Numero al flujo sout
     ostream& toStream(ostream& sout) const;
     //Lee un Numero desde flujo sin
     istream& fromStream(istream& sin);
};

#endif
