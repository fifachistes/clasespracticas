#include <./tablero.h>
void cargar(tTablero &tablero, ifstream& file);
 bool valida(const tTablero &tablero, int fila, int col);
 bool eleccionValida(const tTablero &tablero,int fila, int
col);
 void ponCelda(const tTablero &tablero, int fila, int col,
tcelda celda);
 bool esFicha(const tTablero &tablero, int fila, int col);
 bool esVacia(const tTablero &tablero, int fila, int col);
 void mostrar(const tTablero &tablero);