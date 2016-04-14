#ifndef _TABLAHASH_H
#define _TABLAHASH_H

#pragma once
#include "celda.h"
#include "FuncDisp.h"
#include "FuncExp.h"

using namespace std;

template<class TClave>
class TablaHash
{
    private:
        Celda<TClave>** pCeldas;
        int numero_celdas;
        FuncDisp *pfd;
        FuncExp *pfe;
    public:
        TablaHash(int num_celdas,int numero_bloques, int funcion_dispersion, int funcion_exploracion)
        {
            numero_celdas = num_celdas;
            pCeldas = new Celda<TClave>*[numero_celdas];
            for(int i=0;i<numero_celdas;i++)
            {
                pCeldas[i] = new Celda<TClave>(numero_bloques); // Construyo fila de la matriz
            }
            //Switch para declarar la función de exploración
            switch(funcion_dispersion)
            {
                case 1:
                {
                    pfd = new Modulo();
                    break;
                }
                case 2:
                {
        //            pfd = new Pseudoaleatoria();
                    break;
                }
                default:
                    cerr << "Funcion de dispersion incorrecta...";
                    exit(-1);
            }
            switch(funcion_exploracion)
            {
                case 1:
                {
                    pfe = new Lineal();
                    break;
                }
                case 2:
                {
                    pfe = new Cuadratica();
                    break;
                }
                default:
                    cerr << "Funcion de exploracion incorrecta...";
                    exit(-1);
            }
        }

        ~TablaHash()
        {
        	if(pCeldas != NULL)
        	{
    		    delete [] pCeldas;
        		pCeldas = NULL;
            }
        }

        bool insertar(const TClave clave)
        {
            cout << "Accedo a insertar..." << endl;
            int intento = 0;
            bool insertado = false;
            int pos = pfd->get_posicion(clave,numero_celdas,0);
            cout << "Celda en la que inserto: " << pos << endl;
            if(pCeldas[pos]->estallena() != true)
            {
                cout << "No esta llena..." << endl;
                insertado = pCeldas[pos]->insertar(clave);
                if(insertado != false)
                {
                    cout << "Insertado..." << endl;
                }
                else
                {
                    cout << "No insertado..." << endl;
                }
            }
            else
            {
                insertado = false;
                intento++;
                cout << "Esta llena..." << endl;
                cout << "Activo exploracion..." << endl;
                cout << "Intendo: " << intento << endl;
                pfe = new Lineal();

                while(insertado == false)
                {
                    int pos1 = pfe->get_posicion(clave,numero_celdas,intento);
                    cout << "Celda en la que inserto: " << pos1 << endl;

                    if(pCeldas[pos1]->estallena() != true)
                    {
                        insertado = pCeldas[pos1]->insertar(clave);
                        if(insertado != true) //try-catch
                        {
                            cout << "brabrabrabrabra" << endl;
                            exit(-1);
                        }
                        else
                        {
                            cout << "Insertado..." << endl;
                            pCeldas[pos1]->imprimir_bloque();
                        }
                    }
                    else
                    {
                        intento++;
                        insertado = false;
                    }
                }
            }
        }
        bool buscar(const TClave clave)
        {
            int posicion = pfd->get_posicion(clave,numero_celdas,0);
            int intento = 0;
            int resultado = pCeldas[posicion]->get_bloque(0);
            bool encontrado = false;
            //Ahora busco en los bloques de la celda correspondiente
            if(resultado == clave)
            {
               cout << "No se ha aplicado exploracion." << endl;
               cout << "Se ha encontrado la clave: " << clave << " en: Celda " << posicion << " ,Bloque: " << intento << endl;
               encontrado = true;
            }
            else
            {
              cout << "Se ha aplicado exploracion." << endl;
              encontrado = false;
              intento = 1;
              int aux = 0;
              while(encontrado != true)
              {
                  posicion = pfe->get_posicion(clave,numero_celdas,intento);
                  cout << "Busco en celda: " << posicion << endl;
                  aux = 0;
                  while(aux < pCeldas[posicion]->get_nBloques() && encontrado == false)
                  {
                    if(pCeldas[posicion]->get_bloque(aux) == clave)
                    {
                      cout << "Clave: " << clave << ", Contenido de bloque " << aux << ": " << pCeldas[posicion]->get_bloque(aux) << ". Encontrado." << endl;
                      encontrado = true;
                    }
                    else
                    {
                      cout << "Clave: " << clave << ", Contenido de bloque " << aux << ": " << pCeldas[posicion]->get_bloque(aux) << ". No Encontrado." << endl;
                      encontrado = false;
                      aux++;
                    }
                    cout << "ENTER" << endl;
                    cout << "--------------------------------" << endl;
                    cin.get();
                  }
                  intento++;
              }
              /*if(pCeldas[posicion]->get_bloque(aux) == clave)
              {
                cout << "Se ha encontrado la clave: " << clave << " en: Celda " << posicion << " ,Bloque: " << intento << endl;
              }*/
            }
        }
        void write(void)
        {
          for(int i=0;i<numero_celdas;i++)
          {
            cout << "Celda " << i << ": ";
            cout << pCeldas[i]->imprimir_bloque();
            if(i < numero_celdas-1)
            {
              cout << ",";
            }
            cout << endl;
          }
        }
};

#endif
