#ifndef Arista_H
#define Arista_H

#include <iostream>
// #include "Lista.h"
#include "Nodo.h"
#include <cmath>
struct Arista
{
    //Atributos
    // Nodo *primera;
    // Nodo *segundo;
    char * concatenar = (char*)malloc(sizeof(char)*2);
    double distanciaEuclediana;
    
    //constructor
    Arista(Nodo * primerNodo, Nodo * segundoNodo){
        // this->primera = primerNodo;
        // this->segundo = segundoNodo;
        // this->concatenar = primerNodo->nombre[0] + segundoNodo->nombre[0];
        int contador = 0;
        while (*primerNodo->nombre)
        {
            *this->concatenar = *primerNodo->nombre;
            ++this->concatenar;
            ++primerNodo->nombre;
            ++contador;
        }
        while (*segundoNodo->nombre)
        {
            *this->concatenar = * segundoNodo->nombre;
            ++this->concatenar;
            ++segundoNodo->nombre;
            ++contador;
        }
        this->concatenar -= contador;
        this->distanciaEuclediana = sqrt(pow(segundoNodo->x - primerNodo->x, 2) + pow(segundoNodo->y - primerNodo->y, 2));
    }
};


#endif