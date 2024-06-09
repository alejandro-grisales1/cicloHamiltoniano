#ifndef Lista_H
#define Lista_H

#include <iostream>
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

  //este metodo de agregar permite agregar nodos a la lista si el nodo existe 
  void Agregar(Nodo*&nuevoNodo,Tablahash tabla){
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
            cout << endl
                 << "El nodo: " << iterador->nombre << " ya esta creado." << endl;
            return;
            }
            iterador = iterador->siguiente;
        }
      this->cola->siguiente = nuevoNodo;
      this->cola = nuevoNodo;
      Arista *nuevaAristaCabeza = new Arista(this->cabeza, this->cola);
      tabla.Adicionar(nuevaAristaCabeza);

      Nodo *iterador2 = this->cabeza;
      while (iterador2 != this->cola)
      {
        Arista *nuevaAristaCola = new Arista(this->cola, iterador2);
        tabla.Adicionar(nuevaAristaCola);
        iterador2 = iterador2->siguiente;
      }
    }
    // this->cola = nuevoNodo;
    ++this->numero;
    cout << "Nodo agregado exitosamente." << endl;
  }

  //esta opcion elimina el nodo seleccionado si este esta en la lista
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

  //metodo para actualizar las coordenadas de un nodo
  void Actualizar(){
    if (this->cabeza == NULL)
    {
        cout << endl << "No hay nodos para actulizar!!!" << endl;
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
              cout << endl
                   << "Nodo actualizado exitosamente!!!" << endl;
              return;
            }
          iterador = iterador->siguiente;
        }
        cout << endl << "No se encontro el nodo..." << endl;
    }
  }

  //este metodo permite mostrar los nodos con sus atributos
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