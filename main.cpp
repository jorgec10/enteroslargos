#include <iostream>
#include "EnteroLargo.h"
using namespace std;


int main(void) {
	list<char> lectura;

    for (int i = 0; i < 8; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo a = EnteroLargo(lectura, true);

    lectura.clear();
    for (int i = 0; i < 8; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo b = EnteroLargo(lectura, true);
    
    cout << "a: ";
    a.imprimir();
    cout << "b: ";
    b.imprimir();
    
    cout << "La multiplicacion clasica de los dos EL es: " << endl;
    a.multClasica(b).imprimir();
    cout << "La multiplicacion no rapida de los dos EL es: " << endl;
    a.multNoRapida(b).imprimir();
    cout << "La multiplicacion karat de los dos EL es: " << endl;
    a.multKarat(b).imprimir();
}
