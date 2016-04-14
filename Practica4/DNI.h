#ifndef _DNI_H
#define _DNI_H

#include <iostream>

using namespace std;

class DNI
{
  private:
    long int valor;
  public:
    DNI()
    {
      valor = 0;
    }
    DNI(long int v)
    {
      valor = v;
    }
    void set_dni(long int v)
    {
      valor = v;
    }
    long int get_dni(void)
    {
      return valor;
    }
    bool operator==(DNI& dni1)
    {
        if(valor == dni1.get_dni())
        {
          return true;
        }
        else
        {
          return false;
        }
    }
    /*ostream& operator<<(ostream &salida, const DNI &a)
    {
        salida << a.valor;
        return salida;
    }*/
};

#endif
