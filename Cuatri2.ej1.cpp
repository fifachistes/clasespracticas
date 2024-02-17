#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 10;

typedef struct {
    string nombre;
    int edad;
    string estudios;
    string contrato;
} tEmpleado;

typedef tEmpleado tArray[MAX];

typedef struct {
    tArray miArray;
    int contador;
} tLista;

// Prototipo de la función carga()
bool carga(tLista& lista);

void alejandro(const tLista& lista);
void busqueda(const tLista& lista, string nombre);
bool poder( const tLista & lista );
void anadir(tLista& lista, int index);
void eliminar(tLista& lista);

int main() {
    string nombre;
    int index;
    tLista lista;
    if (carga(lista)) {
        alejandro(lista);
        cout << "Ingresa el nombre del empleado : ";
        cin >> nombre;
        busqueda(lista, nombre);
        cout << "introduce el indice" << endl;
        cin >> index;
        if (poder(lista) ){
            cout << "se pudo!" << endl;
            anadir(lista, index);

            alejandro(lista);
        }
        else {
            cout << "se pudo!" << endl;
        }
        eliminar(lista);
        alejandro(lista);

        
    }
    else {
        cout << "U couldnt open the txt ." << endl;
    }

    return 0;
}

// Definición de la función carga()
bool carga(tLista& lista) {
    bool exito;
    fstream archivo;
    string aux;
    lista.contador = 0;

    archivo.open("empleos.txt");
    if (archivo.is_open()) {

        archivo >> aux;
        while ((aux != "XXX") && (lista.contador < MAX)) {
            lista.miArray[lista.contador].nombre = aux;
            archivo >> lista.miArray[lista.contador].edad;
            archivo >> lista.miArray[lista.contador].contrato;
            archivo >> lista.miArray[lista.contador].estudios;
            lista.contador++;
            archivo >> aux;

        }
        archivo.close();
        exito = true;
    }
    else {
        exito = false;

    }
    return exito;
}

void alejandro(const tLista& lista) {
   

    for (int i = 0;i < lista.contador;i++) {
        cout << lista.miArray[i].nombre << endl;
        cout << lista.miArray[i].edad << endl;
        cout << lista.miArray[i].estudios << endl;
        cout << lista.miArray[i].contrato << endl;
       
    }
    
}
void busqueda(const tLista& lista, string nombre) {
    int i = 0, aux;
    bool esta=false;
    while ((!esta)) {
        if (lista.miArray[i].nombre == nombre) {
            esta = true;
            aux = i;
            cout << "el trabajador es:" << lista.miArray[aux].nombre << " su titulo es = " << lista.miArray[aux].estudios << endl;
        }
        i++; 
     
        }
    if (!esta) {
        cout << "El empleado no esta" << endl;
      }
    return;

    }
void anadir(tLista& lista, int index) {
  
      for (int i = lista.contador; i > index; i--) {
          lista.miArray[i] = lista.miArray[i - 1];
      }
      cout<< "mete los datos del nuevo empleado!"<< endl;

      lista.miArray[index].nombre=" pedro";
      lista.miArray[index].edad= 5 ;
      lista.miArray[index].estudios= " ade";
      lista.miArray[index].contrato= " el meojo";
    
  return ;
  }


bool poder( const tLista &lista ){
    bool  poder;
    if (MAX > lista.contador > 0) {
        poder = true;
    }
    else {
        poder = false;
    }
    return poder;
}
void eliminar(tLista& lista) {
    lista.miArray[lista.contador] = { 0 };
}