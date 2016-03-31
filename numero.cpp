#include "numero.h"

using namespace std;

ostream& operator << (ostream& sout, const Numero& n)
{
    n.toStream(sout);
    return sout; 
}
         

istream& operator >>(istream& sin, Numero& n)
{
    n.fromStream(sin);
    return sin;
}
