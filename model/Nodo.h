#ifndef Nodo_H
#define Nodo_H

#include <iostream>
#include <cstring>

using namespace std;

struct Nodo
{
  char *nombre;
  double x;
  double y;
  Nodo *siguiente;

  //metodo
  Nodo(char *Nombre,double x, double y){
    this->nombre = (char*)malloc(sizeof(char)*2);
    strcpy(this->nombre, Nombre);
    this->x = x;
    this->y = y;
    this->siguiente = NULL;
  }

  //metodo para mostrar los nodos
  void mostrarNodo(){
    cout << this->nombre << ": " << "(" << this->x << "," << this->y << ")";
  }

  // Destructor
  ~Nodo() {
     free(this->nombre); // Libera la memoria asignada para nombre
    this->nombre = NULL;
  }
};

#endif