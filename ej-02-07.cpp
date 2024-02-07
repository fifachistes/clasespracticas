// ej-02-07.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
using namespace std;

const int MaxProductos = 10;

typedef struct {
    int id;
	double precio;
	int unidades;
} tProducto;
typedef tProducto tLista[MaxProductos];
typedef struct {
	tLista lista;
	int contador;
}tProductos;
bool carga(tProductos& productos);
tProducto maxValor(tProductos& productos); 
bool eliminar(tProductos& productos, int id);
void mostrarProducto(const tProducto& producto);
void mostrarLista(const tProductos& productos);
void actualizarDatos(const tProductos productos);

int main()
{
	tProductos productos;
	 
	if (carga(productos)) {
		mostrarLista(productos);
		tProducto max = maxValor(productos);
		cout << endl << "Producto de máximo valor:" << endl;
		mostrarProducto(max);
		cout << "- - - - - - - - - - - - -" << endl << endl;

		int id;
		cout << "Introduce id del producto a eliminar : ";
		cin >> id;
		if (eliminar(productos, id)) {
			cout << endl << endl;
			mostrarLista(productos);
		}

		actualizarDatos(productos);
	 }
	else {
		cout << "No se encontro el fichero";
	}

	return 0;
}

bool carga( tProductos &productos) {
	ifstream archivo;
	bool exito = false;
	int i = 0;
	int valor;
	productos.contador = 0;
	archivo.open("pedidos.txt");

	if (archivo.is_open() ) {
		exito = true;
		archivo >> valor;
		while ((valor != -1) && (productos.contador < MaxProductos)) {
			productos.lista[i].id = valor;
			archivo >> productos.lista[i].precio;
			archivo >> productos.lista[i].unidades;
			productos.contador++;
			archivo >> valor;
			i++;
		}
	}

	return exito;
}
tProducto maxValor(tProductos& productos) {
	double variable;
	int max=-100;
	int indice = 0;

	for (int i = 0; i < productos.contador; i++) {
		variable = productos.lista[i].precio * productos.lista[i].unidades;
		if (variable > max){
			max = variable;
			indice = i;
		}
	}

	return productos.lista[indice];
}

bool eliminar(tProductos& productos, int id) {
	int indice = 0;
	bool exito = false;
	while ((productos.lista[indice].id != id) && indice < productos.contador) {
		indice++;
	}

	if (productos.lista[indice].id == id) {
		productos.contador -= 1;
		for (int i = indice; i < productos.contador; i++) {
			productos.lista[i] = productos.lista[i+1];
		}
		exito = true;
	}
	else {
		cout << endl << "ID inválido!" << endl;
	}

	return exito;
}

void mostrarProducto(const tProducto& producto) {
	cout << "- - - - - - - - - - - - -" << endl;
	cout << "Id: " << producto.id << endl;
	cout << "Precio: " << producto.precio << endl;
	cout << "Unidades: " << producto.unidades << endl;
}
void mostrarLista(const tProductos& productos) {
	for (int i=0; i < productos.contador; i++) {
		mostrarProducto(productos.lista[i]);
	}
	cout << "- - - - - - - - - - - - -" << endl;
}

void actualizarDatos(const tProductos productos) {
	ofstream archivo;
	archivo.open("pedidos.txt");

	if (archivo.is_open()) {
		for (int i = 0; i < productos.contador; i++) {
			archivo << productos.lista[i].id << " ";
			archivo << productos.lista[i].precio << " ";
			archivo << productos.lista[i].unidades << endl;
		}

		archivo << -1;
	}
	else {
		cout << "No se pudieron guardar los datos." << endl;
	}
}