//#include "pila.h"
//#include "lista.h"
//#include "cola.h"
//#include "vector.h"
//#include "calculadora.h"
//#include "complejos.h"
//#include "real.h"
#include "numero.h"
#include "entero.h"
#include "real.h"
#include "racional.h"

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;


int main () {

    //cout << "Introduzca expresion regular: ";
    //cout.flush();
    //calculadora(cin);

  Numero* n1 = new Entero(1);
  Numero* n2 = new Entero(2);
  Numero* n3 = new Real(1.2);
  Numero* n4 = new Real(2.4);
  Numero* n5 = new Racional(1,2);
  Numero* n6 = new Racional(2,3);

  cout << *n2;
  cout << endl;
  /*cout << "Sumando enteros: " << (*n1+*n2) << endl;
  cout << "Sumando reales: " << (*n3+*n4) << endl;*/
  cout << "Sumando 1/2 + 2/3 " << endl;
  cout << "Sumando un racional con un racional: " << (*n5 / *n6) << endl;
  return 0;
}
