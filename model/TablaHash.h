#ifndef TablaHash_H
#define TablaHash_H

#include <iostream>
#include <cstring> // Para strdup
#include "Arista.h"

using namespace std;

struct Tablahash {
    Arista** contenido;
    int cantidad = 500;

    Tablahash() {
        this->contenido = (Arista **)malloc(sizeof(Arista* ) * this->cantidad);
        for (int i = 0; i < cantidad; ++i) {
            this->contenido[i] = NULL;
        }
    }

    void Adicionar(Arista *&arista) {
    char* Nombre = arista->concatenar;
    int item = function_hash(Nombre);
    int inicio = item;

    // Buscar un espacio vacío en la tabla hash
    while (this->contenido[item] != nullptr) {
        item = (item + 1) % cantidad;
        if (item == inicio) {
            cout << "⚠️Error, la tabla hash está llena⚠️" << endl;
            return;
        }
    }

    // Asignar y copiar la cadena
    this->contenido[item] = arista;
    }

    void Eliminar(char* Nombre) {
    int item = function_hash(Nombre);
    int inicio = item;

    while (item+1 != inicio) {
      if (this->contenido[item] != NULL)
      {
        if (strcmp(this->contenido[item]->concatenar, Nombre) == 0)
        {
          // Node found, delete it
          delete this->contenido[item];
          this->contenido[item] = NULL;
          cout << "Node successfully deleted" << endl;
          return;
        }
      }
      
        item = (item + 1) % cantidad;
    }
}


    void mostrarTabla() {
        cout << "Contenido de la tabla:" << endl;
        for (int i = 0; i < this->cantidad; i++) {
            if (this->contenido[i] != nullptr) {
                cout << "Posición [" << i << "] Nombre: ";
                mostrarCadena(this->contenido[i]->concatenar);
                cout << " Distancia: " << this->contenido[i]->distanciaEuclediana << endl;
            }
        }
    }

    void mostrarCadena(char* cadena) {
        while (*cadena) {
            cout << *cadena;
            cadena++;
        }
    }

    void mostrarElemento(int indice) {
        cout << "Posición [" << indice << "] Nombre: " << this->contenido[indice]->concatenar << " Distancia: " << this->contenido[indice]->distanciaEuclediana << endl;
    }

    double obtenerDistancia(char* nombre) {
        int item = function_hash(nombre);

        while (this->contenido[item]->concatenar != nombre) {
            item = (item + 1) % cantidad;
        }

        return this->contenido[item]->distanciaEuclediana;
    }

    int function_hash(char* Nombre) {
        int suma = 0;
        for (int i = 0; Nombre[i] != '\0'; i++) {
            suma += Nombre[i];
        }
        return suma % this->cantidad;
    }
};

#endif
