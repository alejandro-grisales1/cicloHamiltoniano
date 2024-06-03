#ifndef TablaHash_H
#define TablaHash_H

#include <iostream>
#include "Nodo.h"

using namespace std;

struct TablaHash
{
  char **contenido;
  Nodo *Distancia;
  int cantidad;

  //constructor
  TablaHash(): cantidad(100) {
    this->contenido = (char **)malloc(sizeof(char *) * this->cantidad);
    this->Distancia = NULL;
  }

  void Adicionar(){

  }

  //funcion para obtener el valor del indice en el que se va a almacenar
  unsigned int function_hash(char* Nombre, int cantidad) {
      int suma = 0;
      for (int i = 0; Nombre[i] != '\0'; i++) {
          suma += Nombre[i];
      }
      return suma % cantidad;
  }
};

#endif