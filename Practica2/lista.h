#ifndef _LISTA_H
#define _LISTA_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h> 
#include "nodo.h"

using namespace std;

template<class TDATO> 
class lista
{
private:
  nodo<TDATO>* inicio;
  nodo<TDATO>* final;
public:
  lista();

  lista(nodo<TDATO>* ini);

  ~lista();
  
  bool is_empty(void);

  void insertar_final(TDATO d);

  void insertar_principio(TDATO d);

  TDATO extraer_inicio(void);

  TDATO extraer_final(void);

  void borrar_hasta(TDATO d);

  void borrar_todo(void);

  void mostrar_lista(void);

};

  template<class TDATO>
  lista<TDATO>::lista()
  {
    inicio = NULL;
    final = NULL;
  }
  
  template<class TDATO>
  lista<TDATO>::lista(nodo<TDATO>* ini)
  {
    inicio = ini;
    final = ini;
  }
   
  template<class TDATO>
  lista<TDATO>::~lista()
  {
    inicio = NULL;
    final = NULL;
  }
  
  template<class TDATO>
  bool lista<TDATO>::is_empty(void)
  {
    if((inicio == final) && (inicio == NULL) && (final == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
  }
  
  template<class TDATO>
  void lista<TDATO>::insertar_final(TDATO d)
  {
    nodo<TDATO>* nd = new nodo<TDATO>(d);
    if(is_empty() == true)
    {
      inicio = nd;
      final = nd;
    }
    else
    {
      final->set_siguiente(nd);
      final = nd;
    }
  }
  
  template<class TDATO>
  void lista<TDATO>::insertar_principio(TDATO d)
  {
    nodo<TDATO>* nd = new nodo<TDATO>(d);
    if(is_empty() == true)
    {
      inicio = nd;
      final = nd;
    }
    else
    {
      nd->set_siguiente(inicio);
      inicio = nd;
    }
  }

  template<class TDATO>
  TDATO lista<TDATO>::extraer_inicio(void)
  {
    TDATO res;
    if(is_empty() != true)
    {
      if(inicio==final)
      {
        res=inicio->get_dato();
        inicio->set_siguiente(NULL);
        inicio=NULL;
        final=NULL;
      }
      else
      {
        res = inicio->get_dato();
        nodo<TDATO>* auxiliar = inicio;
        inicio=inicio->get_siguiente();
        delete auxiliar;
      }
    }
    return res;
  }

  template<class TDATO>
  TDATO lista<TDATO>::extraer_final(void)
  {
    TDATO res;
    if(is_empty() != true)
    {
      if(inicio==final)
      {
        res=inicio->get_dato();
        inicio->set_siguiente(NULL);
        inicio=NULL;
        final=NULL;
      }
      else
      {
        res = final->get_dato();
        nodo<TDATO>* auxiliar=inicio;
        while(auxiliar->get_siguiente()!=final)
        {
          auxiliar=auxiliar->get_siguiente();
        }
        if(auxiliar->get_siguiente()==final)
        {
          final=auxiliar;
          auxiliar=auxiliar->get_siguiente();
          final->set_siguiente(NULL);
          delete auxiliar;
        }
      }
    }
    return res;
  }

  template<class TDATO>
  void lista<TDATO>::borrar_hasta(TDATO d)
  {
    if(is_empty() != true)
    {
      if(inicio == final)
      {
        if(inicio->get_dato() == d)
        {
          inicio->set_siguiente(NULL);
          inicio = NULL;
          final = NULL;
        }
      }
      else
      {
        nodo<TDATO>* auxiliar = new nodo<TDATO>();
        while(inicio->get_dato()!=d)
        {
          auxiliar=inicio;
          inicio=inicio->get_siguiente();
          auxiliar->set_siguiente(NULL);
          delete auxiliar;
        }
      }
    }
  }

  template<class TDATO>
  void lista<TDATO>::borrar_todo(void)
  {
      nodo<TDATO>* auxiliar = new nodo<TDATO>();
      if(is_empty() != true)
      {
        while(inicio!=NULL)
        {
          auxiliar=inicio;
          inicio=inicio->get_siguiente();
          auxiliar->set_siguiente(NULL);
          delete auxiliar;
        }
      }
  }

  template<class TDATO>
  void lista<TDATO>::mostrar_lista(void)
  {
    nodo<TDATO>* auxiliar;
    auxiliar=inicio;
    if(inicio==NULL)
    {
      cout << "Lista vacia"<< endl;
    }
    else
    {
      while(auxiliar!=NULL)
      {
        cout << auxiliar->get_dato();
        if(auxiliar->get_siguiente() != NULL)
        {
          cout << ",";
        }
        auxiliar = auxiliar->get_siguiente();
      }
    }
  }
  
#endif