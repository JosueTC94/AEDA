#ifndef _NODO_H
#define _NODO_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//typedef int TDATO;

template<class TDATO>
class nodo
{
private:
  TDATO dato;
  nodo<TDATO>* siguiente;
public:
  nodo();
  ~nodo();
  nodo(TDATO d);
  nodo(TDATO d, nodo<TDATO>* sig);
  TDATO get_dato(void);
  void set_dato(TDATO d);
  void set_siguiente(nodo<TDATO>* next);
  nodo<TDATO>* get_siguiente(void);
};

template <class TDATO>
nodo<TDATO>::nodo()
{
  siguiente = NULL;
}

template <class TDATO>
nodo<TDATO>::~nodo()
{
  siguiente = NULL;
}

template <class TDATO>
nodo<TDATO>::nodo(TDATO d)
{
    dato = d;
    siguiente = NULL;
}

template <class TDATO>
nodo<TDATO>::nodo(TDATO d,nodo* sig)
{
    dato = d;
    siguiente = sig;
}

template <class TDATO>
TDATO nodo<TDATO>::get_dato(void)
{
    return dato;
}

template <class TDATO>
void nodo<TDATO>::set_dato(TDATO d)
{
    dato = d;
}

template <class TDATO>
void nodo<TDATO>::set_siguiente(nodo* next)
{
   siguiente = next;
}

template <class TDATO>
nodo<TDATO>* nodo<TDATO>::get_siguiente(void)
{
    return siguiente;
}

#endif