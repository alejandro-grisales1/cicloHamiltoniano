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
         << "1. AGREGAR LOS NODOS DEL ARCHIVO" << endl
         << "2. AGREGAR NODO" << endl
         << "3. ELIMINAR NODO" << endl
         << "4. ACTUALIZAR NODO" << endl
         << "5. MOSTRAR NODOS" << endl
         << "6. SIGUIENTE" << endl
         << "7. SALIR" << endl
         << endl
         <<"INGRESE LA OPCION: ";
  }

  void menuDos(){
    cout << endl
         << "1. VER TABLA DE ADYACENCIA" << endl
         << "2. VECINO MÁS CERCANO" << endl
         << "3. VECINO MÁS CERCANO CON 2-OPT" << endl
         << "4. INSERCIÓN MÁS CERCANA" << endl
         << "5. INSERCIÓN MÁS CERCANA CON 2-OPT" << endl
         << "6. ANTERIOIR" << endl
         << "7. SALIR" << endl
         << endl
         <<"INGRESE LA OPCION: ";
  }

  void v2_1(){
    cout << endl
           << "Ingresa el caracter (nombre) de la nueva coordenada: ";
  }

  void v2_2(){
    cout << endl
           << "Ingrese la coordenada x del nuevo nodo: ";
  }

  void v2_3(){
    cout << "Ingrese la coordenada y del nuevo nodo: ";
  }

  void v3_1(){
    cout << endl
           << "Ingresa el caracter (nombre) de la coordenada que deseas eliminar: ";
  }

  void salir(){
    cout << endl
           << "Saliendo del programa..." << endl;
  }

  void opcionIncorrecta(){
    cout << endl
           << "Opcion incorrecta, ingresa una opcion correcta!!!" << endl;
  }

  void m2v6(){
    cout << endl
               << "Volviendo al menu principal..." << endl;
  }

};

#endif