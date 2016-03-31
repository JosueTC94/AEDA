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
#include "complejo.h"

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
  cout << "MENU" << endl;
  cout << "Ejecutando pruebas. Presione enter para ejecutar cada prueba." << endl;
  cout << "1.-Sumando 1 + 4.2. Debe dar => 5" << endl;
  cin.get();
  Numero* n1 = new Entero(1);
  Numero* n2 = new Real(4.2);
  cout << "Resultado: " << *n1+*n2 << endl;
  cout << "2.-Restando 4.2 - 1. Debe dar => 3.2" << endl;
  cin.get();
  cout << "Resultado: " << *n2 - *n1 << endl;
  cout << "3.- Multiplicando 4/3 * 1.2. Debe dar => 4/3" << endl;
  cin.get();
  Numero* n3 = new Real(0.0);
  Numero* n4 = new Racional(1,1);
  cout << "Resultado: " << *n3 * *n4 << endl;
  cout << "4.- Restando 1 + 3i - 5/3. Debe dar => 0 + 3i" << endl;
  cin.get();
  Numero* n5 = new Complejo(1,3);
  Numero* n6 = new Racional(5,3);
  cout << "Resultado: " << *n5 - *n6 << endl;
  cout << "5.- Dividiendo 8 y 4.7. Debe dar => 2" << endl;
  cin.get();
  Numero* n7 = new Entero(8);
  Numero* n8 = new Real(4.7);
  cout << "Resultado: " << *n7 / *n8 << endl;
  cout << "6.-  Diviendo 8.2 y 4. Debe dar => 2.05" << endl;
  cin.get();
  Numero* n9 = new Real(8.2);
  Numero* n10 = new Entero(4);
  cout << "Resultado: " << *n9 / *n10 << endl;
  cout << "Probando las excepciones. Try/Catch " << endl;

  return 0;
}
