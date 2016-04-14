#pragma once
#include <iostream>
#include <cstdlib>

#include "DNI.h"
#include "celda.h"
#include "tabla_hash.h"

typedef int TClave;

using namespace std;

int main()
{
    int numero_celdas = 0;
    int numero_bloques = 0;
    int dispersion = 0;
    int exploracion = 0;

    cout << "Introduzca el numero de celdas: ";
    cin >> numero_celdas;

    cout << "Introduzca el numero de bloques: ";
    cin >> numero_bloques;

    cout << "Seleccione el tipo de dispersion: " << endl;
    cout << "\t1.- Modulo " << endl;
    cout << "\t2.- Pseudoaleatoria:" << endl;
    cin >> dispersion;

    cout << "Seleccione el tipo de exploracion: " << endl;
    cout << "\t1.- Lineal." << endl;
    cout << "\t2.- Cuadratica." << endl;
    cout << "\t3.- Dispersion doble." << endl;
    cout << "\t4.- Re-dispersion." << endl;
    cin >> exploracion;

    TablaHash<int> t1(numero_celdas, numero_bloques, dispersion, exploracion);

    t1.insertar(123);
    t1.insertar(120);
    t1.insertar(117);
    t1.insertar(3);
    t1.insertar(6);
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "BUSCANDO LOLOLOLOLOLOLOOOOOOOOOOO" << endl;
    t1.buscar(6);
    return 0;
}
