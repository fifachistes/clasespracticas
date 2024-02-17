#include <iostream>
#include <string>
using namespace std;


int main()
{
    string frase, palabra;
    int posNO, posSI, aux;

    cout << "Introduce una frase : " << endl;
    getline(cin, frase);

    while (frase.length() > 0) {
        posNO = frase.find_first_not_of(" \t");
        frase.erase(0, posNO);
        posSI = frase.find(" ");
        if (posSI == -1) {
            posSI = frase.length();
            palabra = frase.substr(0, posSI);
            cout << palabra << endl;
            cout << palabra.length() << endl;
            frase.erase(0, palabra.length());
        }
        else {
            palabra = frase.substr(0, posSI);
            cout << palabra << endl;
            cout << palabra.length() << endl;
            frase.erase(0, posSI);
        }
    }




    return 0;
}

