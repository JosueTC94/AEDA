#include "entero.h"
#include "real.h"
#include "racional.h"
#include "complejo.h"

#include <cstdlib>

using namespace std;

Entero::Entero()
{
    valor = 0;
}

Entero::Entero(int v)
{
    valor = v;
}

Entero::~Entero()
{}


void Entero::set_dato(int n)
{
    valor = n;
}

int Entero::get_dato(void){
    return valor;
}
//Devuelve una copia del Número actual en el tipo Entero
const Entero Entero::toEntero() const
{
    return Entero(*this);
}

const Real Entero::toReal() const
{
    Real auxiliar(this->valor);
    return auxiliar;
}

const Racional Entero::toRacional() const
{
    return Racional(this->valor,1);
}

const Complejo Entero::toComplejo() const
{
    return Complejo(this->valor,0);
}

//Escribe una Numero al flujo sout
ostream& Entero::toStream(ostream& sout) const
{
    sout << this->valor;
    return sout;
}

//Lee un Numero desde flujo sin
istream& Entero::fromStream(istream& sin)
{
    int auxiliar;
    sin >> auxiliar;
    set_dato(auxiliar);
    return sin;
}

Numero& Entero::operator+(const Numero &b) const
{
    cout << "Transformo " << b;
    Entero auxiliar = b.toEntero();
    cout << " en " << auxiliar << endl;
    return *(new Entero(valor+auxiliar.valor));
}

Numero& Entero::operator-(const Numero &b) const
{
    cout << "Transformo " << b;
    Entero auxiliar = b.toEntero();
    cout << " en " << auxiliar << endl;
    return *(new Entero(valor-auxiliar.valor));
}

Numero& Entero::operator*(const Numero &b) const
{
    cout << "Transformo " << b;
    Entero auxiliar = b.toEntero();
    cout << " en " << auxiliar << endl;
    return *(new Entero(valor*auxiliar.valor));
}

Numero& Entero::operator/(const Numero &b) const
{
    cout << "Transformo " << b;
    Entero auxiliar = b.toEntero();
    cout << " en " << auxiliar << endl;
    try
    {
      if(auxiliar.valor == 0)
      {
        throw 1;
      }
      else
      {
        return *(new Entero(valor/auxiliar.valor));
      }
    }
    catch(int e)
    {
       cerr << "Excepción nº " << e << ". Se divide por 0." << endl;
       exit(-1);
    }
}
