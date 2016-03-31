#include "racional.h"
#include "real.h"
#include "entero.h"
#include "complejo.h"

#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;

Racional::Racional()
{
	numerador=0;
	denominador=1;
}

Racional::Racional(d_racional num_,d_racional den_)
{
	try
	{
		if(den_ == 0)
		{
			throw 10;
		}
		else
		{
			numerador = num_;
			denominador = den_;
		}
	}
	catch(int e)
	{
			cerr << "Constructor de Racional con denominador = 0. Nº excepcion: " << e << endl;
			exit(-1);
	}

}
Racional::~Racional()
{}

d_racional Racional::get_numerador(void)
{
	return numerador;
}

d_racional Racional::get_denominador(void)
{
	return denominador;
}

void Racional::set_numerador(d_racional num_)
{
	numerador = num_;
}

void Racional::set_denominador(d_racional den_)
{
	if(den_!=0)	//Try catch
		denominador = den_;
}

d_racional Racional::denominador_comun(d_racional a,d_racional b)
{
	if((a % b) == 0)
		return a;
	if((b % a) == 0)
		return b;
	if(((a % b) != 0) && ((b % a)!=0))
	{
		return a*b;
	}
}
//Devuelve una copia del Número actual en el tipo Entero
const Entero Racional::toEntero() const
{
		int auxiliar = numerador / denominador;
    return Entero(auxiliar);
}

const Real Racional::toReal() const
{
		float auxiliar = numerador / denominador;
    return Real(auxiliar);
}

const Racional Racional::toRacional() const
{
  	return Racional(*this);
}

const Complejo Racional::toComplejo() const
{
		cout << "Racional to complejo" << endl;
		float auxiliar = numerador / denominador;
		cout << "Auxiliar: " << auxiliar << "=> numerador/denominador: " << numerador << "/" << denominador << "=>" << (numerador/denominador) << endl;
  	return Complejo(auxiliar,0);
}

Numero& Racional::operator+(const Numero &b) const
{
    Racional auxiliar = b.toRacional();
		//Minimo común múltiplo
    return *(new Racional(numerador+auxiliar.get_numerador(),denominador+auxiliar.get_denominador()));
}

Numero& Racional::operator-(const Numero &b) const
{
    Racional auxiliar = b.toRacional();
		//Mínimo común múltiplo
    return *(new Racional(numerador-auxiliar.get_numerador(),denominador-auxiliar.get_denominador()));
}

Numero& Racional::operator*(const Numero &b) const
{
		Racional auxiliar = b.toRacional();
		return *(new Racional(numerador*auxiliar.get_numerador(),denominador*auxiliar.get_denominador()));
}

Numero& Racional::operator/(const Numero &b) const
{
			Racional auxiliar = b.toRacional();
			return *(new Racional(numerador*auxiliar.get_denominador(),denominador*auxiliar.get_numerador()));
}

//Escribe una Numero al flujo sout
ostream& Racional::toStream(ostream& sout) const
{
		sout << numerador << "/" << denominador << endl;
    return sout;
}

//Lee un Numero desde flujo sin
istream& Racional::fromStream(istream& sin)
{
		char caracter;
    sin >> numerador;
		sin >> caracter;
		sin >> denominador;
    return sin;
}
