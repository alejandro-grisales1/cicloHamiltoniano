#ifndef Lista_H
#define Lista_H

#include <iostream>
#include <cstring>
#include "Nodo.h"
#include "TablaHash.h"

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

  ~Lista() {
        // Liberar todos los nodos de la lista
        Nodo *actual = this->cabeza;
        while (actual != nullptr) {
            Nodo *temporal = actual;
            actual = actual->siguiente;
            delete[] temporal->nombre;
            temporal->nombre = NULL;
            delete temporal;
        }
    }

  //este metodo de agregar permite agregar nodos a la lista si el nodo existe 
  void Agregar(Nodo*&nuevoNodo,Tablahash &tabla){
    //si la lista esta vacia agrega el elemento a la cabeza y a la cola
    if (this->cabeza == NULL && this->cola == NULL)
    {
      this->cabeza = nuevoNodo;
      this->cola = nuevoNodo;
    }else
    {
      //se itera la lista y busca que no se agregue un nodo duplicado
      Nodo* iterador = this->cabeza;
      while (iterador != NULL){
          if (iterador->nombre[0] == nuevoNodo->nombre[0])
          {
            cout << "⚠️Error, Este nodo ya esta creado⚠️" << endl;
            return;
            }
            iterador = iterador->siguiente;
        }
      this->cola->siguiente = nuevoNodo;
      this->cola = nuevoNodo;

      Nodo *iterador2 = this->cabeza;
      while (iterador2 != this->cola)
      {
        Arista *nuevaAristaCabeza = new Arista(iterador2, this->cola);
        tabla.Adicionar(nuevaAristaCabeza);
        Arista *nuevaAristaCola = new Arista(this->cola, iterador2);
        tabla.Adicionar(nuevaAristaCola);
        iterador2 = iterador2->siguiente;
      }
    }
    // this->cola = nuevoNodo;
    ++this->numero;
    cout << "➕Nodo agregado exitosamente➕" << endl;
  }

  //esta opcion elimina el nodo seleccionado si este esta en la lista
  void Eliminar(const char *nombre,Tablahash &tabla) {
    if (this->cabeza == NULL) {
        cout << "⚠️No hay nodos para eliminar⚠️" << endl;
    } else {
        Nodo* iterador = this->cabeza;
        Nodo* actual = NULL;

        // Si el nodo a eliminar está en la cabeza
        if (this->cabeza->nombre[0] == nombre[0]) {
            this->cabeza = iterador->siguiente;
            iterador->siguiente = nullptr;
            if (this->cabeza == NULL) {  // Si la lista queda vacía
                this->cola = NULL;
            }
            delete iterador;
            --this->numero;
            cout << "⛔Nodo eliminado exitosamente⛔" << endl;
            return;
        }

        // Buscar el nodo a eliminar
        while (iterador != NULL) {
            actual = iterador;
            iterador = iterador->siguiente;
            if (iterador != NULL && iterador->nombre[0] == nombre[0]) {
                break;
            }
        }

        // Si el nodo no está en la lista
        if (iterador == NULL) {
            cout << "⚠️No se encontró el nodo en la lista⚠️" << endl;
            return;
        }

        // Desconectar el nodo de la lista
        actual->siguiente = iterador->siguiente;
        if (iterador == this->cola) {  // Si el nodo a eliminar es la cola
            this->cola = actual;
        }
        
        Nodo *iterador2 = this->cabeza;
        char cadena[10];
        while (iterador2 != nullptr)
        {
          cadena[0] = iterador2->nombre[0];
          cadena[1] = iterador->nombre[0];
          cadena[2] = '\0';
          tabla.Eliminar(cadena);
          cadena[0] = iterador->nombre[0];
          cadena[1] = iterador2->nombre[0];
          cadena[2] = '\0';
          tabla.Eliminar(cadena);


          iterador2 = iterador2->siguiente;
        }

        // Liberar la memoria
        iterador->siguiente = nullptr;
        delete iterador;
        --this->numero;
        cout << "⛔Nodo eliminado con exitosamente⛔" << endl;
    }
}


  //metodo para actualizar las coordenadas de un nodo
  void Actualizar(){
    if (this->cabeza == NULL)
    {
        cout << endl << "⚠️No hay nodos para actulizar⚠️" << endl;
    }else
    {
      char *NodoActualizable = (char *)malloc(sizeof(char) * 2);
      cout << endl
           << "Ingresa el nombre del nodo que desea actualizar: ";
      cin >> NodoActualizable;
      Nodo *iterador = this->cabeza;
      while (iterador != NULL )
        {
          if (iterador->nombre[0] == NodoActualizable[0])
            {
              cout << endl
                   << "Ingrese la nueva coordenada x del nodo " << iterador->nombre << ": ";
              cin >> iterador->x;
              cout << "Ingrese la nueva coordenada y del nodo " << iterador->nombre << ": ";
              cin >> iterador->y;
              cout << "✅Nodo actualizado exitosamente✅" << endl;
              return;
            }
          iterador = iterador->siguiente;
        }
        cout << "⚠️No se encontro el nodo⚠️" << endl;
        free(NodoActualizable);
        NodoActualizable = NULL;
    }
  }

  //este metodo permite mostrar los nodos con sus atributos
  void MostrarNodos(){
    cout<< endl <<"Cantidad de nodos: "<<this->numero<<endl;
    Nodo * iterador = this->cabeza;
    // cout << "Nodo " << iterador->nombre << endl;
    while(iterador != NULL){
      cout << "Nodo ";
      iterador->mostrarNodo();
      cout << endl;
      iterador = iterador->siguiente;
    }
    iterador = this->cabeza;
  }

  //este metodo permite mostrar los nodos y sus enlaces
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