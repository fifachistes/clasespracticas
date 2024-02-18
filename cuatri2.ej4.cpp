#include <iostream>// Kei ur the best!!!I hope u do great in life!!! Great person and great friend!!!Alejandro Red 18/02/'24
int const DIM = 2;
using namespace std;
typedef int tMatriz[DIM][DIM];


void cargaMatriz(tMatriz matriz);

void mostrarM(const tMatriz matriz);
void suma(tMatriz matriz1,tMatriz matriz2, tMatriz resultado);
void resta(tMatriz matriz1, tMatriz matriz2, tMatriz resultado);
void multiplicacion(tMatriz matriz1, tMatriz matriz2, tMatriz resultado);
void transponer (tMatriz matriz1);
bool silla(tMatriz matriz1, int i , int j);

int main() {
	tMatriz matriz1, matriz2, resultado;
	
	int i, j;
	cargaMatriz(matriz1);
	mostrarM(matriz1);
	cargaMatriz(matriz2);
	mostrarM(matriz2);
	cout << " quiero ver si el elemento en la fila = ";
	cin >> i;
	cout << " y en la columna = ";
	cin >> j;
	
	if (silla(matriz1, i, j)) {
		cout<< " El elemento es silla!!!"<< endl;
	}
	else {
		cout << " El elemento  no es silla ;(((" << endl;
	}

	cout << " transponer matriz1" << endl;
	transponer( matriz1);
	mostrarM(matriz1);
	cout << " multiplicar matrices" << endl;
	multiplicacion(matriz1, matriz2, resultado);
	mostrarM(resultado); 
	cout << " sumar matrices" << endl;
	suma(matriz1, matriz2, resultado);
	mostrarM(resultado);
	system("pause");
	cout << " restar matrices" << endl;
	resta(matriz1, matriz2, resultado);
	system("pause");
	mostrarM(resultado);


	return 0;
}
void cargaMatriz(tMatriz matriz) {
	for (int fila = 0; fila < DIM;fila++) {
		for (int columna = 0; columna < DIM;columna++) {
			cout << "Mete la info que quieres poner en la fila = " << fila << " columna = " << columna << endl;
			cin >> matriz[fila][columna];
		}
	}
	return;
}
void mostrarM(const tMatriz matriz) {
	for (int fila = 0; fila < DIM;fila++) {
		for (int columna = 0; columna < DIM;columna++) {
			cout << matriz[fila][columna] << "\t";
		}
		cout << endl;
	}
	return;
}
void suma(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {


	for (int fila = 0; fila < DIM;fila++) {
		for (int columna = 0; columna < DIM;columna++) {
			resultado[fila][columna] = matriz1[fila][columna] + matriz2[fila][columna];
		}

	}
	return ;
}
void resta(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {
	for (int fila = 0; fila < DIM;fila++) {
		for (int columna = 0; columna < DIM;columna++) {
			resultado[fila][columna] = matriz1[fila][columna] - matriz2[fila][columna];
		}

	}
	return;
}
void multiplicacion(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {
	
	
	for (int fila = 0; fila < DIM;fila++) {

		for (int columna = 0; columna < DIM;columna++) {
			resultado[fila][columna] = 0;
			for (int i = 0; i < DIM;i++) {
				resultado[fila][columna] += matriz1[fila][i] * matriz2[i][columna];
			}
		}

	}

}
void transponer(tMatriz matriz1) {
	tMatriz aux = { 0 };
	for (int fila = 0; fila < DIM;fila++) {
		for (int columna = 0; columna < DIM;columna++) {
			aux[columna][fila] = matriz1[fila][columna];
		}

	}
	for (int fila = 0; fila < DIM;fila++) {
		for (int columna = 0; columna < DIM;columna++) {
			matriz1[fila][columna] = aux[fila][columna];
		}

	}
	
	return;
}
bool silla(tMatriz matriz1, int i, int j) {
	bool exito= true;
	int maxF=0,  x=0;
	maxF = matriz1[i][j];
	while(exito&& x< DIM){// lo presupongo como el mas grande

		if (maxF< matriz1[i][x]){
			exito= false;
			}
		if (maxF < matriz1[x][j]) {
			exito = false;
		}
		x++;


	}
	return exito;

}