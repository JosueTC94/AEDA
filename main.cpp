#include "pila.h"
#include "numero.h"
#include "entero.h"
#include "real.h"
#include "racional.h"
#include "complejo.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int main () {

  cout << "MENU" << endl;
  cout << "Ejecutando pruebas. Presione enter para ejecutar cada prueba." << endl;
  cout << "1.-Sumando 1 + 4.2. Debe dar => 5" << endl;
  cin.get();
  Numero* n1 = new Entero(1);
  Numero* n2 = new Real(4.2);
  cout << "Resultado: " << *n1+*n2 << endl;
  cout << "--------------------------------------" << endl;

  cout << "2.-Restando 4.2 - 1. Debe dar => 3.2" << endl;
  cin.get();
  cout << "Resultado: " << *n2 - *n1 << endl;
  cout << "--------------------------------------" << endl;

  cout << "3.- Multiplicando 4/3 * 1.2. Debe dar => 4/3" << endl;
  cin.get();
  Numero* n3 = new Racional(4,3);
  Numero* n4 = new Real(1.2);
  cout << "Resultado: " << *n3 * *n4 << endl;
  cout << "--------------------------------------" << endl;

  cout << "4.- Restando 1 + 3i - 5/3. Debe dar => 0 + 3i" << endl;
  cin.get();
  Numero* n5 = new Complejo(1,3);
  Numero* n6 = new Racional(5,3);
  cout << "Resultado: " << *n5 - *n6 << endl;
  cout << "--------------------------------------" << endl;

  cout << "5.- Dividiendo 8 y 4.7. Debe dar => 2" << endl;
  cin.get();
  Numero* n7 = new Entero(8);
  Numero* n8 = new Real(4.7);
  cout << "Resultado: " << *n7 / *n8 << endl;
  cout << "--------------------------------------" << endl;

  cout << "6.-  Diviendo 8.2 y 4. Debe dar => 2.05" << endl;
  cin.get();
  Numero* n9 = new Real(8.2);
  Numero* n10 = new Entero(4);
  cout << "Resultado: " << *n9 / *n10 << endl;
  cout << "--------------------------------------" << endl;

  cout << "7.- Restando 1.7 - 2 + 4i. Debe dar => -0.3" << endl;
  cin.get();
  Numero* n13 = new Real(1.7);
  Numero* n14 = new Complejo(2,4);
  cout << "Resultado: " << *n13 - *n14 << endl;
  cout << "--------------------------------------" << endl;

  cout << "8.- Sumando 1/3 + 2/7. Debe dar => 13/21" << endl;
  cin.get();
  Numero *n15 = new Racional(1,3);
  Numero *n16 = new Racional(2,7);
  cout << "Resultado: " << *n15 + *n16 << endl;
  cout << "--------------------------------------" << endl;

  cout << "9.- Sumando 9/4 + 1 + 1i. Debe dar => 13/4" << endl;
  cin.get();
  Numero* n17 = new Racional(9,4);
  Numero* n18 = new Complejo(1,1);
  cout << "Resultado: " << *n17 + *n18 << endl;
  cout << "--------------------------------------" << endl;

/*
  cout << "CALCULADORAAAAAAA" << endl;
  cout << "Introduzca una expresion: ";
  cout.flush();
  pila<Numero*> p1;
  while(cin.peek() != EOF && cin.peek() != '\n')
  {
    cin >> std::ws;  // Gestión de los espacios en blanco
    char c = cin.peek();  // carácter peek
  //  cout << "Peek->" << cin.peek() << endl;
    if(c == '+')
    {
        Numero* n1;
        Numero* n2;
        n1 = p1.pop();
        n2 = p1.pop();
        p1.push(*n1+*n2);
    }
    else
    {
      switch(c)
      {
        case 'e':
                  int aux = 0;
                  cin >> aux;
                  Numero* e = new Entero(aux);
                  p1.push(e);
              break;
        case 'f':
              break;
        case 'r':
              break;
        case 'c':
              break;
        default:
      }
    }
  }*/
  return 0;
}
