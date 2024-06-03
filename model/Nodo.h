#ifndef Nodo_H
#define Nodo_H

#include <iostream>

using namespace std;

struct Nodo
{
  char *nombre = (char*)malloc(sizeof(char)*1);
  double x;
  double y;
  Nodo *siguiente;

  //metodo
  Nodo(char *nombre,double x, double y){
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->siguiente = NULL;
  }

  //metodo para mostrar los nodos
  void mostrarNodo(){
    cout << this->nombre << ": " << "(" << this->x << "," << this->y << ")" << " -> ";
  }
};

#endif