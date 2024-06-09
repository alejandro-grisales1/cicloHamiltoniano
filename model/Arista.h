#ifndef Arista_H
#define Arista_H

#include <iostream>
// #include "Lista.h"
#include "Nodo.h"
#include <cmath>
struct Arista
{
    //Atributos
    char *primera;
    char *segundo;
    char * concatenar = (char*)malloc(sizeof(char)*2);
    double distanciaEuclediana;
    
    //constructor
    Arista(Nodo * primerNodo, Nodo * segundoNodo){
        this->primera = primerNodo->nombre;
        this->segundo = segundoNodo->nombre;
        char *iterador = this->concatenar;
        while (*this->primera)
        {
            *iterador = *this->primera;
            ++iterador;
            ++this->primera;
        }
        while (*this->segundo)
        {
            *iterador = *this->segundo;
            ++iterador;
            ++this->segundo;
        }
        this->distanciaEuclediana = sqrt(pow(segundoNodo->x - primerNodo->x, 2) + pow(segundoNodo->y - primerNodo->y, 2));
    }
};


#endif