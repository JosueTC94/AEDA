#include "real.h"
#include "entero.h"
#include "racional.h"
#include "complejo.h"

#include <cstdlib>
#include <assert.h>

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
    //cout << "This->valor:" << this->valor << endl;
    Entero auxiliar(this->valor);
    return auxiliar;
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
    return Complejo(valor,0);
  }
  catch(int e)
  {
    cout << "Se pierde presición al intentar pasar de un real a complejo." << endl;
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
        throw 1;
      }
    }
    catch(int e)
    {
      cout << "Ha ocurrido una excepcion. Nº excepcion: " << e << endl;
    }
}


Numero& Real::operator+(const Numero &b) const
{
    Real auxiliar = b.toReal();
    return *(new Real(valor+auxiliar.valor));
}

Numero& Real::operator-(const Numero &b) const
{
    Real auxiliar = b.toReal();
    return *(new Real(valor-auxiliar.valor));
}

Numero& Real::operator*(const Numero &b) const
{
    Real auxiliar = b.toReal();
    return *(new Real(valor*auxiliar.valor));
}

Numero& Real::operator/(const Numero &b) const
{
    Real auxiliar = b.toReal();
    try
    {
      if(auxiliar.valor == 0)
      {
        throw 1;
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
