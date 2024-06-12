#ifndef LeerCoordenadas_H
#define LeerCoordenadas_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring> // Para std::strcpy
#include "Lista.h"

using namespace std;

struct LeerCoordenadas {
    string linea;
    char delimitador = ',';

    void leerArchivo(const string &nombreArchivo, Lista &lista, Tablahash tabla) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
            return;
        }

        cout << endl;
        while (getline(archivo, linea)) {
            // Procesar cada línea usando stringstream para dividir la línea por comas
            stringstream stream(linea);
            string str, x_str, y_str;
            double x, y;
            getline(stream, str, delimitador);
            getline(stream, x_str, delimitador);
            getline(stream, y_str, delimitador);

            // Convertir las coordenadas a double
            x = stod(x_str);
            y = stod(y_str);

            // Convertir el string a char*
            const char *c = str.c_str();
            char *nombre = (char *)malloc(sizeof(char) * 2);
            strcpy(nombre, c);

            cout << "Nodo: " << nombre << "(" << x << "," << y << ") ";

            Nodo *nodo = new Nodo(nombre, x, y);
            lista.Agregar(nodo, tabla);

            // Liberar la memoria asignada a nombre
            free(nombre);
            nombre = NULL;
        }
        archivo.close();
    }
};

#endif
