#ifndef TablaHash_H
#define TablaHash_H

#include <iostream>
#include "Arista.h"

using namespace std;

struct Tablahash
{
    //atributos
    char** contenido;
    Arista* Nombre;
    int cantidad;

    //constructor
    Tablahash(){
      this->cantidad = 230;
      this->contenido = (char **)malloc(sizeof(char *) * this->cantidad);
      this->Nombre = NULL;
    }

    //metodo para adicionar elemento a la tabla hash
    void Adicionar(char* Nombre, int cantidad) {
        int item = function_hash(Nombre, cantidad);
        //manejo de colision
        while (this->contenido[item] != nullptr) {
        item = (item + 1) % cantidad;
        }
        this->contenido[item] = (char*)malloc(sizeof(char) * 2);
        char* iterador = this->contenido[item];
        while (*Nombre) {
            *iterador = *Nombre;
            Nombre++;
            iterador++;
        }
    }

    //metodo para mostrar la tabla hash
    void mostrarTabla(int cantidad) {
        cout << "Contenido de la tabla:" << endl;
        for (int i = 0; i < cantidad; i++) {
            if (this->contenido[i] != NULL) {
                cout << "Posición " << i << ": ";
                mostrarCadena(this->contenido[i]);
                cout << endl;
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
      cout << "Posición " << indice << ": ";
      cout << this->contenido[indice] << endl;
    }

    //funcion para obtener el valor del indice en el que se va a almacenar
    int function_hash(char* Nombre, int cantidad) {
        int suma = 0;
        for (int i = 0; Nombre[i] != '\0'; i++) {
            suma += Nombre[i];
        }
        return suma % cantidad;
    }
};

#endif