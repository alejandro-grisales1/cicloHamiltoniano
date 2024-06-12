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
    char * concatenar;
    double distanciaEuclediana;
    
    //constructor predeterminado
    Arista() : primera(nullptr), segundo(nullptr), concatenar(nullptr), distanciaEuclediana(0.0) {}

    //constructor
Arista(Nodo * primerNodo, Nodo * segundoNodo){
    this->primera = primerNodo->nombre;
    this->segundo = segundoNodo->nombre;
    this->concatenar = (char*)malloc(sizeof(char)*5);
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
    *iterador = '\0';
    this->distanciaEuclediana = sqrt(pow(segundoNodo->x - primerNodo->x, 2) + pow(segundoNodo->y - primerNodo->y, 2));
}


    ~Arista(){
        free(this->concatenar);
        this->concatenar = NULL;
    }
};


#endif