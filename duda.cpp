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

bool carga(tLista& lista);
void alejandro(const tLista& lista);

int main()
{
	tLista lista;
	if (carga(lista)) {

		alejandro(lista);

	}
	else {
		cout << "U couldnt open the txt ." << endl;
	}



	return 0;
}

bool carga(tLista& lista) {
	bool exito;
	fstream archivo;
	string aux;
	lista.contador = 0;
	string ayuda, ayuda1;
	archivo.open("lista.txt");
	if (archivo.is_open()) {

		archivo >> aux;
		while ((aux != "XXX") && (lista.contador < MAX)) {
			lista.miArray[lista.contador].nombre = aux;
			archivo >> lista.miArray[lista.contador].edad;
			archivo.ignore();
			getline(archivo, ayuda);
			lista.miArray[lista.contador].estudios = ayuda;
			archivo.ignore();
			getline(archivo, ayuda1);
			lista.miArray[lista.contador].contrato = ayuda1;
			archivo.ignore();
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
	return;
}

