#include <iostream>
#include <sstream>
#include <fstream>
#include "../view/View.h"
#include "../model/Lista.h"
#include "../model/LeerCoordenadas.h"
#define COORDENADAS "Coordenadas.csv"

using namespace std;

int main(){
  //objetos
  LeerCoordenadas leer;
  View vi;
  Lista li;

  //variables
  int op;

  //mostrar bienvenida
  vi.bienvenida();

  //bucle de menu uno
  while (op != 7)
  {
    //mostrar menu uno
    vi.menuUno();
    //pedir opcion al usuario
    cin >> op;

    if (op == 1)
    {
      //la opcion uno lee el archivo .csv y crea una lista enlazada simple con nodos
      leer.leerArchivo(COORDENADAS, li);
    }
    else if (op == 2)
    {
      //la opcion dos muestra los nodos que hay y deja ingresar un nuevo nodo
      li.MostrarNodos();
      double x;
      double y;
      char *nombre = (char*)malloc(sizeof(char)*2);
      //pide el nombre para agregar
      vi.v2_1();
      cin >> nombre;
      //pide la coordenada x
      vi.v2_2();
      cin >> x;
      //pide la coordenada y
      vi.v2_3();
      cin >> y;
      Nodo *nodo = new Nodo(nombre, x, y);
      li.Agregar(nodo);
    }
    else if (op == 3)
    {
      //la opcion tres muestra los nodos que hay y deja eliminar un nodo
      li.MostrarNodos();
      char *nombre = (char *)malloc(sizeof(char) * 2);
      //pide el nombre para eliminar
      vi.v3_1();
      cin >> nombre;
      li.Eliminar(nombre);
    }
    else if (op == 4)
    {
      //la opcion cuatro muestra los nodos que hay y deja actualizar un nodo existente
      li.MostrarNodos();
      li.Actualizar();
    }
    else if (op == 5)
    {
      //la opcion cinco muestra los nodos con sus punteros
      li.Mostrar();
    }
    else if (op == 6)
    {
      //la opcion seis genera bucle de menu dos
      while (op != 7)
      {
        //muestra el menu dos 
        vi.menuDos();
        //pedir opcion al usuario
        cin >> op;
        if (op == 1)
        {
          /* code */
        }else if (op == 2)
        {
          /* code */
        }else if (op == 3)
        {
          /* code */
        }else if (op == 4)
        {
          /* code */
        }else if (op == 5)
        {
          /* code */
        }else if (op == 6)
        {
          //vuelve al menu uno
          vi.m2v6();
          break;
        }
        else if (op == 7)
        {
          //finaliza el programa
          vi.salir();
          return 0;
        }else
        {
          vi.opcionIncorrecta();
        }
      }
    }else if (op == 7)
    {
      //la opcion siete sale del programa
      vi.salir();
      break;
    }else
    {
      //si ingresa otra opcion muestra un error
      vi.opcionIncorrecta();
    }
  }
  //finaliza el programa
  return 0;
}