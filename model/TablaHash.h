#ifndef TablaHash_H
#define TablaHash_H

#include <iostream>
#include "Arista.h"

using namespace std;

struct Tablahash
{
    //atributos
    // char** contenido;
    // Arista* nombre;
    Arista* contenido;
    int cantidad = 230;

    //constructor
    Tablahash(){
      // this->cantidad = 230;
      this->contenido = (Arista *)malloc(sizeof(Arista ) * this->cantidad);
      // this->nombre = NULL;
      // Inicializa el nombre y la distancia de cada Arista
        for (int i = 0; i < cantidad; ++i) {
            this->contenido[i].concatenar = NULL;
            this->contenido[i].distanciaEuclediana = 0.0;
        }
    }

    //metodo para adicionar elemento a la tabla hash
    void Adicionar(Arista * arista) {
      char* Nombre = arista->concatenar;
      int item = function_hash(Nombre);
      // manejo de colision
      while (this->contenido[item].concatenar != nullptr)
      {
        item = (item + 1) % cantidad;
        }
        this->contenido[item].concatenar = (char*)malloc(sizeof(char) * 2);
        char* iterador = this->contenido[item].concatenar;
        while (*Nombre) {
            *iterador = *Nombre;
            Nombre++;
            iterador++;
        }
        this->contenido[item].distanciaEuclediana = arista->distanciaEuclediana;
    }

    //metodo para mostrar la tabla hash
    void mostrarTabla() {
        cout << "Contenido de la tabla:" << endl;
        for (int i = 0; i < this->cantidad; i++) {
            if (this->contenido[i].concatenar != NULL) {
                cout << "Posición [" << i << "] Nombre: ";
                mostrarCadena(this->contenido[i].concatenar);
                cout << " Distancia: " << this->contenido[i].distanciaEuclediana << endl;
            }
        }
    }

    //metodo para mostrar la cadena del elemento
    void mostrarCadena(char* cadena) {
        while (*cadena) {
            cout << *cadena;
            cadena++;
        }
    }

    //metodo para mostrar el elemento pasandole un indice
    void mostrarElemento(int indice){
      cout << "Posición [" << indice << "] Nombre: " << this->contenido[indice].concatenar << " Distancia: " << this->contenido[indice].distanciaEuclediana << endl;
    }

    //funcion para obtener el valor del indice en el que se va a almacenar
    int function_hash(char* Nombre) {
        int suma = 0;
        for (int i = 0; Nombre[i] != '\0'; i++) {
            suma += Nombre[i];
        }
        return suma % this->cantidad;
    }
};

#endif