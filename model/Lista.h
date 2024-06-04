#ifndef Lista_H
#define Lista_H

#include <iostream>
#include "Nodo.h"

using namespace std;

struct Lista
{
  //atributos
  Nodo *cabeza;
  Nodo *cola;
  int numero;

  //constructor
  Lista(){
    this->cabeza = NULL;
    this->cola = NULL;
    this->numero = 0;
  }

  void Agregar(Nodo*&nuevoNodo){
    if (this->cabeza == NULL && this->cola == NULL)
    {
      this->cabeza = nuevoNodo;
    }else
    {
      this->cola->siguiente = nuevoNodo;
    }
    this->cola = nuevoNodo;
    ++this->numero;
  }

  void Eliminar(char * nombre){
    if (this->cabeza == NULL)
    {
        cout << endl << "No hay nodos para eliminar!!!" << endl;
    }
    else
    {
        Nodo* iterador = this->cabeza;
        Nodo* actual = NULL;

        // Si el nodo a eliminar está en la cabeza
        if (this->cabeza->nombre[0] == nombre[0])
        {
            this->cabeza = this->cabeza->siguiente;
            delete iterador;
            cout << endl << "Nodo eliminado con exito!!!" << endl;
            --this->numero;
            return;
        }

        // Buscar el nodo a eliminar
        while (iterador != NULL )
        {
            actual = iterador;
            iterador = iterador->siguiente;
            if (iterador != NULL && iterador->nombre[0] == nombre[0])
            {
                break;
            }
        }

        // Si el nodo no está en la lista
        if (iterador == NULL){
          cout << endl << "No se encontro el nodo en la lista!!!" << endl;
          return;
        }

        // Desconectar el nodo de la lista
        actual->siguiente = iterador->siguiente;

        // Liberar la memoria
        delete iterador;
        cout << endl << "Nodo eliminado con exito!!!" << endl;
        --this->numero;
    }
}


  void MostrarNodos(){
    cout<< endl <<"Cantidad de nodos: "<<this->numero<<endl;
    Nodo * iterador = this->cabeza;
    while(iterador != NULL){
      cout << "Nodo ";
      iterador->mostrarNodo();
      cout << endl;
      iterador = iterador->siguiente;
    }
    cout << endl;
  }

  void Mostrar(){
    cout<< endl <<"Contenido de la lista: "<<endl;
    cout<<"Número del nodo: "<<this->numero<<endl;
    Nodo * iterador = this->cabeza;
    while(iterador != NULL){
      cout<<endl<<"***************************************"<<endl<<endl;
      iterador->mostrarNodo();
      cout << endl;
      cout << "Apuntador siguiente -> " << iterador->siguiente << endl;
      iterador = iterador->siguiente;
      cout<<endl<<"***************************************"<<endl;
    }
    cout << endl;
  }
};

#endif