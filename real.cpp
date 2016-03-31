#include "real.h"
#include "entero.h"
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
    cout << "This->valor:" << this->valor << endl;
    Entero auxiliar(this->valor);
    return auxiliar;
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
    float auxiliar;
    sin >> auxiliar;
    set_dato(auxiliar);
    return sin;
}


Numero& Real::operator+(const Numero &b) const
{
    Real auxiliar = b.toReal();
    return *(new Real(valor+auxiliar.valor));
}

Numero& Real::operator-(const Numero &b) const
{
    /*Real auxiliar = b.toReal();
    return *(new Real(valor-auxiliar.valor));*/
}

Numero& Real::operator*(const Numero &b) const
{
    /*Real auxiliar = b.toReal();
    return *(new Real(valor*auxiliar.valor));*/
}

Numero& Real::operator/(const Numero &b) const
{
/*    Real auxiliar = b.toReal();
    return *(new Real(valor/auxiliar.valor));*/
}