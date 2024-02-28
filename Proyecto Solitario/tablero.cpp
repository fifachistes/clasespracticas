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
 #include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const string FG_BLACK = "\x1B[30m";
const string FG_BLUE = "\x1b[34m";
const string BG_BLACK = "\x1B[40m";
const string BG_BROWN = "\x1B[48;5;94m";
const string BG_ORANGE = "\x1B[48;2;204;102;0m";
const string Reset = "\x1b[0m";

const char Horizontal = char(196);
const char UpperLeft = char(218);
const char UpperCross = char(194);
const char UpperRight = char(191);
const char Vertical = char(179);
const char MidLeft = char(195);
const char MidCross = char(197);
const char MidRight = char(180);
const char LowerLeft = char(192);
const char LowerCross = char(193);
const char LowerRight = char(217);
const char Square = char(219);

const int FILS = 4;
const int COLS = 5;
const int f_meta = 2, c_meta = 1;
const int DEFAULT_COLOR = -1;
//enum tCelda { NULA, VACIA, FICHA };

typedef int tmatriz[FILS][COLS];

tmatriz m = { 0, 0, 1, 2, 2,
2, 1, 2, 2, 0,
0, 1, 1, 2, 0,
0, 0, 0, 0, 0,
};

void pintaCabecera();
void pintaBordeHorizontal(char left, char cross, char right);
void pintaBordeCelda(int fila, int filaMeta, int colMeta);
void pintaCentroCelda(int fila, int filaMeta, int colMeta);

int main(){ //este ser�a vuestro subprograma mostrar del enunciado

   
    system("cls"); // borrar consola
    cout << Reset;
    pintaCabecera();
    pintaBordeHorizontal(UpperLeft, UpperCross, UpperRight);
    for (int fila = 0; fila < FILS; fila++) {
        pintaBordeCelda(fila, f_meta, c_meta);
        pintaCentroCelda(fila, f_meta, c_meta);
        pintaBordeCelda(fila, f_meta, c_meta);
        if (fila < FILS - 1) {
            pintaBordeHorizontal(MidLeft, MidCross, MidRight);
        }
        else {
            pintaBordeHorizontal(LowerLeft, LowerCross, LowerRight);
        }
    }
}

// Subprogramas privados...

void pintaCabecera() {
    cout << setw(2) << "    ";
    cout << setw(5) << 1;
    for (int i = 2; i <= COLS; i++)
        cout << setw(7) << i;
    cout << endl;
}

void pintaBordeHorizontal(char left, char cross, char right) {
    cout << "    ";
    cout << left;
    for (int i = 0; i < COLS - 1; i++) {
        cout << string(6, Horizontal) << cross;
    }
    cout << string(6, Horizontal) << right << endl;
}

void pintaBordeCelda(int fila, int filaMeta, int colMeta) {
    cout << "    ";
    for (int k = 0; k < COLS; k++) {
        cout << Vertical;
        if (filaMeta == fila && colMeta == k)
            cout << BG_ORANGE;
        else if (m[fila][k] == 0)
            cout << BG_BLACK;
        else
            cout << BG_BROWN;
        cout << "      ";
        cout << Reset;
    }
    cout << Vertical << endl;
}

void pintaCentroCelda(int fila, int filaMeta, int colMeta) {
    cout << "  " << setw(2) << fila + 1;
    for (int k = 0; k < COLS; k++) { // cada col
        cout << Vertical;
        if (m[fila][k] == 0) {
            cout << BG_BLACK;
            cout << "      ";
        }
        else {
            if (filaMeta == fila && colMeta == k)
                cout << BG_ORANGE;
            else
                cout << BG_BROWN;
            cout << "  ";
            if (m[fila][k] == 1)
                cout << FG_BLACK;
            else
                cout << FG_BLUE;
            cout << Square << Square;
            cout << Reset;
            if (filaMeta == fila && colMeta == k)
                cout << BG_ORANGE;
            else
                cout << BG_BROWN;
            cout << "  ";
        }
        cout << Reset;
    }
    cout << Vertical << endl;
}

//Aprovecho este fichero  para pasaros el c�digo del operador insertor
//sobrecargado para que cuando lea un entero te inserte el tCelda 
//correspondiente. Lo us�is como siempre. 
//Si leyera otra cosa se comportar�a como es habitual.

/*istream& operator>>(ifstream& input, tCelda& celda) { 
   int num;

   input >> num;
   celda = tCelda(num);

   return input;
}
*/