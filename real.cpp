#include "real.h"
#include "entero.h"
#include "racional.h"
#include "complejo.h"

#include <iostream>
#include <cstdlib>

using namespace std;


Real::Real()
{
    valor = 0;
}

Real::Real(float v)
{
    valor = v;
}

Real::~Real()
{}


void Real::set_dato(float n)
{
    valor = n;
}

float Real::get_dato(void){
    return valor;
}
//Devuelve una copia del Número actual en el tipo Real
const Real Real::toReal() const
{
    return Real(*this);
}

const Entero Real::toEntero() const
{
    try
    {
      throw 5;
    }
    catch(int e)
    {
      //cout << "Perdiendo precision al pasar de real a entero. Nº Excepcion: " << e << endl;
      Entero auxiliar(this->valor);
      return auxiliar;
    }
}

const Racional Real::toRacional() const
{
  //try catch --> El numerador pierde precisión pasando de real a entero
  return Racional(valor,1);
}

const Complejo Real::toComplejo() const
{
  try
  {
    throw 6;
  }
  catch(int e)
  {
    //cout << "Se pierde presición al intentar pasar de un real a complejo. Nº excepcion: " << e << endl;
    return Complejo(valor,0);
  }
}
//Escribe una Numero al flujo sout
ostream& Real::toStream(ostream& sout) const
{
    sout << this->valor;
    return sout;
}

//Lee un Numero desde flujo sin
istream& Real::fromStream(istream& sin)
{
    try
    {
      if(sin != NULL)
      {
        float auxiliar;
        sin >> auxiliar;
        set_dato(auxiliar);
        return sin;
      }
      else
      {
        throw 3;
      }
    }
    catch(int e)
    {
      cout << "Ha ocurrido una excepcion. Nº excepcion: " << e << endl;
    }
}


Numero& Real::operator+(const Numero &b) const
{
    cout << "Transformo " << b;
    Real auxiliar = b.toReal();
    cout << " en " << auxiliar << endl;
    return *(new Real(valor+auxiliar.valor));
}

Numero& Real::operator-(const Numero &b) const
{
    cout << "Transformo " << b;
    Real auxiliar = b.toReal();
    cout << " en " << auxiliar << endl;
    return *(new Real(valor-auxiliar.valor));
}

Numero& Real::operator*(const Numero &b) const
{
    cout << "Transformo " << b;
    Real auxiliar = b.toReal();
    cout << " en " << auxiliar << endl;
    return *(new Real(valor*auxiliar.valor));
}

Numero& Real::operator/(const Numero &b) const
{
    cout << "Transformo " << b;
    Real auxiliar = b.toReal();
    cout << " en " << auxiliar << endl;
    try
    {
      if(auxiliar.valor == 0)
      {
        throw 4;
      }
      else
      {
        return *(new Real(valor/auxiliar.valor));
      }
    }
    catch(int e)
    {
      cerr << "Excepcion- Se esta intentando dividir por cero. Nº Excepcion: " << e << endl;
      exit(-1);
    }
}
