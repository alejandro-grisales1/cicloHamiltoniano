#ifndef LeerCoordenadas_H
#define LeerCoordenadas_H

#include <iostream>
#include <sstream>
#include <fstream>
// #include "Nodo.h"
#include "Lista.h"

using namespace std;

struct LeerCoordenadas
{
  string linea;
  char delimitador = ',';

  void leerArchivo(const string &nombreArchivo,Lista &lista,Tablahash tabla)
  {
    ifstream archivo(nombreArchivo);
    while (getline(archivo, linea))
    {
      // Aquí puedes procesar cada línea
      // Por ejemplo, puedes usar stringstream para dividir la línea por comas
      stringstream stream(linea);
      string str, x_str, y_str;
      double x, y;
      getline(stream, str, delimitador);
      getline(stream, x_str, delimitador);
      getline(stream, y_str, delimitador);

      // Convertir las coordenadas a double
      x = stod(x_str);
      y = stod(y_str);

      const char *c = str.c_str();
      char *nombre = (char *)malloc(sizeof(char) * 2);

      nombre[0] = c[0];
      nombre[1] = '\0';
      cout << "Nodo: " << nombre << "("<< x << "," << y << ") ";

      Nodo *nodo = new Nodo(nombre, x, y);
      lista.Agregar(nodo,tabla);
    }
    archivo.close();
    }
};

#endif
