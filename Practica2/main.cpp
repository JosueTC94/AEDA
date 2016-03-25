#include <iostream>     
#include <string>   
#include <cctype>       // std::isdigit
#include <stdlib.h>
#include "racional.h"
#include "pila.h"

using namespace std;

typedef int TDATO; 


int main () {

  pila<TDATO> p1;

  cout << "Introduzca expresion regular: ";
  cout.flush(); 

while(cin.peek() != EOF && cin.peek() != '\n')
{
  cin >> std::ws;  // Gestión de los espacios en blanco
  TDATO c = cin.peek();  // carácter peek
//  cout << "Peek->" << cin.peek() << endl;

  if (isdigit(c))
  {
     TDATO n;
     cin >> n;

     cout << "Ha introducido un digito " << n << '\n';
     p1.push(n);
   
  }
  else
  {
     
    char str;
    cin >> str;
    if(!isdigit(cin.peek()))
    {

        cout << "Ha introducido un operando: " << str << '\n';
        switch(str)
        {
            case '+':
                { 
                    TDATO auxiliar = 0;
                    //cout << "Sumando" << endl;
                    //cout << "Auxiliar-> " << auxiliar << endl;
                    int i=0;
                    while(i<2)
                    {
                        //cout << "pop:" << p1.pop() << endl;
                        auxiliar = p1.pop() + auxiliar;
                        //cout << "Auxiliar-> " << auxiliar << endl;
                        i++;
                    }
                    p1.push(auxiliar);
                    break;
                }
            case '-':
                {
                    TDATO auxiliar;
                    //cout << "Restando" << endl;
                    //cout << "Auxiliar-> " << auxiliar << endl;
                    int i=0;
                    if(!p1.is_empty())
                    {
                    while(i<2)
                        {
                            auxiliar = p1.pop() - auxiliar;
                            i++; 
                        }
                    p1.push(auxiliar);
                    }
                break;
                }
            case '*':
                {
                    TDATO auxiliar = 1;
                    //cout << "Auxiliar->" << auxiliar  << endl;
                    int i=0;
                    while(i<2)
                    {
                        auxiliar = p1.pop() * auxiliar;
                       // cout << "Auxiliar->" << auxiliar << endl;
                        i++;
                    }
                    p1.push(auxiliar);
                break;
                }
            case '/':
                {
                    TDATO auxiliar = 1;
                    auxiliar = p1.pop();
                    auxiliar = p1.pop() / auxiliar;
                    p1.push(auxiliar);
                }
                break;
            default:
                cout << "Operando no descubierto..." << endl;
        }
    }
    else
    {
        if(str == '-')
        {
           TDATO c = cin.peek();  // peek character
           //cout << "Peek->" << cin.peek() << endl;
          
            if (isdigit(c) )
            {
                 TDATO n;
                 cin >> n;
                 n = -n;
                 cout << "Ha introducido un digito " << n << '\n';
                 p1.push(n);
            }
        }
     }
  }

  cout << "Mostrando pila" << endl;
  p1.mostrar_pila();
  cout << endl;
}

  cout << "Resultado: " << endl;
  p1.mostrar_pila();
  
  cout << endl;
  return 0;
}