#ifndef MatrizAdyacencia_H
#define MatrizAdyacencia_H
#include "Lista.h"
#include "Arista.h"
struct MatrizAdyacencia
{
    Arista ** matrizAdyacencia;
    

    MatrizAdyacencia(Lista listaNodos){
        this->matrizAdyacencia = (Arista**)malloc(sizeof(Arista*)*)
    }
    // c, d = 4;
    // A , C = 5;
    //  e, c = 6;
    // A, d = 8;
    // A, e = 10;
    //  c, e = 2;
    //  e, a = 8;
    
    // indice = AB -> 4
    // indice = AC -> 8
    // indice = AD -> 2

    // indice = BC -> 7
    // indice = BD -> 2

    // indice = DC -> 9

    // A-B-C-D-A -> AB,BC,CD,DA, = 14
    // A-B-D-C-A
    // A-D-B-C-A
    // A-D-C-B-A
    // A-C-D-B-A
    // A-C-B-D-A

    // AB = 9,AC = 8,AD = 5
    //  BA = 13, BC = 10, BD = 5,
    //  Tab[5] = AD
    //  Tab[5] = BD
};
#endif