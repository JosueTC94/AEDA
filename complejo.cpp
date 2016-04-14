#include "complejo.h"
#include "racional.h"
#include "real.h"
#include "entero.h"

#include <iostream>
#include <cstdlib>


Complejo::Complejo()
{
	real = 0;
	imaginaria = 0;
	signo = true;
}

Complejo::Complejo(d_Complejo real_,d_Complejo imaginaria_)
{
	real = real_;
	if(imaginaria_ < 0)
	{
		signo = false;
	}
	else
	{
		signo = true;
	}
	imaginaria = imaginaria_;
}

Complejo::~Complejo()
{}

d_Complejo Complejo::get_real(void)
{
	return real;
}

d_Complejo Complejo::get_imaginaria(void)
{
	return imaginaria;
}

void Complejo::set_real(d_Complejo real_)
{
	real = real_;
}

void Complejo::set_imaginaria(d_Complejo imaginaria_)
{
	imaginaria = imaginaria_;
}

//CAMBIOS DE TIPO
const Entero Complejo::toEntero() const
{
    return Entero(real);
}

const Real Complejo::toReal() const
{
    return Real(real);
}

const Racional Complejo::toRacional() const
{
  	return Racional(real,1);
}

const Complejo Complejo::toComplejo() const
{
    return Complejo(*this);
}
//operadores
Numero& Complejo::operator+(const Numero &b) const
{
    Complejo auxiliar = b.toComplejo();
		//cout << "Auxiliar: " << auxiliar.get_real() << ", Imaginaria: " << auxiliar.get_imaginaria() << endl;
    return *(new Complejo(real+auxiliar.get_real(),imaginaria+auxiliar.get_imaginaria()));
}

Numero& Complejo::operator-(const Numero &b) const
{
		cout << "Transformo: " << b;
    Complejo auxiliar = b.toComplejo();
		cout << " en " << auxiliar << endl;
    return *(new Complejo(real-auxiliar.get_real(),imaginaria-auxiliar.get_imaginaria()));
}

Numero& Complejo::operator*(const Numero &b) const
{
		cout << "Transformo: " << b;
		Complejo auxiliar = b.toComplejo();
		cout << " en " << auxiliar << endl;
    float real = real*auxiliar.get_real()-imaginaria*auxiliar.get_imaginaria();
    float imag = real*auxiliar.get_imaginaria()+imaginaria*auxiliar.get_real();
    return *(new Complejo(real,imag));
}

Numero& Complejo::operator/(const Numero &b) const
{
		cout << "Transformo: " << b;
    Complejo auxiliar = b.toComplejo();
		cout << " en " << auxiliar << endl;
    return *(new Complejo(real/auxiliar.get_real(),imaginaria/auxiliar.get_imaginaria()));
}

//Escribe una Numero al flujo sout
ostream& Complejo::toStream(ostream& sout) const
{
		sout << real;
    if(signo == true)
      sout << "+";
    sout << imaginaria;
    sout << "i";
    return sout;
}

//Lee un Numero desde flujo sin
istream& Complejo::fromStream(istream& sin)
{
		char caracter;
    sin >> real;
		sin >> caracter;
    if(caracter == '+')
      signo = true;
    else
      signo = false;
    sin >> imaginaria;
		sin >> variable_imaginaria;
    return sin;
}
