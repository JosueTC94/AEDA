#ifndef _PILA_H
#define _PILA_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

using namespace std;

template<class TDATO>
class pila
{
private:
	lista<TDATO> list_;
	int top_;
public:
	pila();

	~pila();
	
	void push(TDATO d);

	TDATO pop(void);

	TDATO get_top(void);

	void mostrar_pila();

	bool is_empty(void);

  void borrar(void);

  void borrar_hasta(TDATO d);

	void borrar_pila(void);

};

template<class TDATO>
pila<TDATO>::pila()
{
	list_ = NULL;
	top_=-1;
}

template<class TDATO>
pila<TDATO>::~pila()
{
	if(list_.is_empty() != true)
	{
		while(list_.is_empty())
		{
			pop();
		}
	}
}

template<class TDATO>
void pila<TDATO>::push(TDATO d)
{
	list_.insertar_final(d);
	top_++;
}

template<class TDATO>
TDATO pila<TDATO>::pop(void)
{
	TDATO res;

	res = list_.extraer_final();

	top_--;
	return res;
}

template<class TDATO>
TDATO pila<TDATO>::get_top(void)
{
	return top_;
}

template<class TDATO>
void pila<TDATO>::mostrar_pila()
{
	if(is_empty()==true)
		cout << "Pila vacia"<<endl;
	else
		list_.mostrar_lista();

}

template<class TDATO>
bool pila<TDATO>::is_empty(void)
{
	if(top_==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class TDATO>
void pila<TDATO>::borrar(void)
{
    if(is_empty() == true)
    {
      cout << "La lista esta vacia..." << endl;
    }
    else
    {
      while(is_empty() != true)
      {
        pop();
      }
    }
}

template<class TDATO>
void pila<TDATO>::borrar_hasta(TDATO d)
{
    if(is_empty() == true)
    {
      cout << "La pila esta vacia..." << endl;
    }
    else
    {
      TDATO auxiliar = pop();
      while(auxiliar != d)
      {
        auxiliar = pop();
      }
    }
}

template<class TDATO>
void pila<TDATO>::borrar_pila(void)
{
    if(is_empty()==true)
		cout << "Pila vacia"<<endl;
	else
	{
        while(is_empty() == true)
        {
            pop();
        }
	}
}



#endif