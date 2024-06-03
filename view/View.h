#ifndef View_H
#define View_H

#include <iostream>

using namespace std;

struct View
{
  void bienvenida(){
    cout << endl
         << endl
         << "******************************************************" << endl
         << "*BIENVENIDOS A NUESTRO PROGRAMA DE CICLO HAMILTONIANO*" << endl
         << "******************************************************" << endl
         << endl;
  }

  void menuUno(){
    cout << endl
         << "1. AGREGAR NODO" << endl
         << "2. ELIMINAR NODO" << endl
         << "3. ACTUALIZAR NODO" << endl
         << "4. SIGUIENTE" << endl
         << "5. SALIR" << endl;
  }

  void menuDos(){
    cout << endl
         << "1. VER TABLA DE ADYACENCIA" << endl
         << "2. VECINO MÁS CERCANO" << endl
         << "3. VECINO MÁS CERCANO CON 2-OPT" << endl
         << "4. INSERCIÓN MÁS CERCANA" << endl
         << "5. INSERCIÓN MÁS CERCANA CON 2-OPT" << endl
         << "6. ANTERIOIR" << endl
         << "7. SALIR" << endl;
  }

  int opcion(){
    int op;
    cout << endl
         << "INGRESE LA OPCION: ";
    cin >> op;
    return op;
  }
};

#endif