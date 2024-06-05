#include <iostream>
#include <sstream>
#include <fstream>
#include "../view/View.h"
#include "../model/Lista.h"
#include "../model/LeerCoordenadas.h"
#define COORDENADAS "Coordenadas.csv"

using namespace std;

int main(){
  // se crean los atributos
  View vi;
  Lista li;
  int op;

  //se hace el llamado al metodo bienvenida
  vi.bienvenida();

  //se crea un bucle para que muestre el menu repetida mente hasta que se seleccione la opcion de salir
  while (op != 7)
  {
    //se muestra el primer menu del programa y se recive la opcion seleccionada
    vi.menuUno();
    op = vi.opcion();
    //la opcion uno permite leer el archivo de Coordenadas.csv y se crean los nodos y se crea una lista enlazada simple
    if (op == 1)
    {
      ifstream archivo(COORDENADAS);
      string linea;
      char delimitador = ',';
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
        li.Agregar(nodo);
    }
    archivo.close();
    }
    //esta opcion permite agregar nodos a la lista manualmente
    else if (op == 2)
    {
      li.MostrarNodos();
      double x;
      double y;
      char *nombre = (char*)malloc(sizeof(char)*2);
      cout << endl
           << "Ingresa el caracter (nombre) de la nueva coordenada: ";
      cin >> nombre;
      cout << endl
           << "Ingrese la coordenada x del nuevo nodo: ";
      cin >> x;
      cout << "Ingrese la coordenada y del nuevo nodo: ";
      cin >> y;
      Nodo *nodo = new Nodo(nombre, x, y);
      li.Agregar(nodo);
    }
    //esta opcion permite eliminar nodos manualmente
    else if (op == 3)
    {
      li.MostrarNodos();
      char *nombre = (char *)malloc(sizeof(char) * 2);
      cout << endl
           << "Ingresa el caracter (nombre) de la coordenada que deseas eliminar: ";
      cin >> nombre;
      li.Eliminar(nombre);
    }
    else if (op == 4)
    {
      li.MostrarNodos();
      li.Actualizar();
    }
    else if (op == 5)
    {
      li.Mostrar();
    }
    else if (op == 6)
    {
      while (op != 7)
      {
        vi.menuDos();
        op = vi.opcion();
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
          cout << endl
               << "Volviendo al menu principal..." << endl;
          break;
        }else if (op == 7)
        {
          return 0;
        }else
        {
          cout << endl
           << "Opcion incorrecta, ingresa una opcion correcta!!!" << endl;
        }
        
      }
    }else if (op == 7)
    {
      cout << endl
           << "Saliendo del programa..." << endl;
      break;
    }else
    {
      cout << endl
           << "Opcion incorrecta, ingresa una opcion correcta!!!" << endl;
    }
  }
  return 0;
}