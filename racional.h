#ifndef _RACIONAL_H
#define _RACIONAL_H

#pragma once
#include "numero.h"
#include <iostream>

using namespace std;

class Real;
class Entero;

typedef int d_racional;

class Racional: public Numero
{

	d_racional numerador;
	d_racional denominador;

public:
	Racional();
	Racional(d_racional num_,d_racional den_);
	~Racional();

	d_racional get_numerador(void);
	d_racional get_denominador(void);

	void set_numerador(d_racional num_);
	void set_denominador(d_racional dem_);

	d_racional denominador_comun(d_racional a,d_racional b);

	//operadores
	  const Entero toEntero() const;
	  const Real toReal() const;
	  const Racional toRacional() const;

	  Numero& operator+(const Numero &b) const;
	  Numero& operator-(const Numero &b) const;
	  Numero& operator/(const Numero &b) const;
	  Numero& operator*(const Numero &b) const;

	//  const Complejos toComplejo() const=0;

	//Escribe una Numero al flujo sout
	  ostream& toStream(ostream& sout) const;
	//Lee un Numero desde flujo sin
	  istream& fromStream(istream& sin);

	/*bool operator==(const racional &rac_);
	bool operator<(const racional &rac_);
	bool operator>(const racional &rac_);*/
};

#endif
