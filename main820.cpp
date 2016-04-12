#include <iostream>
#include "EnteroLargo.h"
#include "Entero820.h"
using namespace std;


int main(void) {
	list<char> lectura;

    EnteroLargo enteros[8];
    
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            char digito;
            cin >> digito;
            lectura.push_front(digito);
        }
        enteros[j] = EnteroLargo(lectura, true);
        lectura.clear();
    }
    
    Entero820 a = Entero820(0, 2, enteros);
    

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            char digito;
            cin >> digito;
            lectura.push_front(digito);
        }
        enteros[j] = EnteroLargo(lectura, true);
        lectura.clear();
    }
    
    Entero820 b = Entero820(0, 4, enteros);
    
    /*cout << "a: ";
    a.imprimir();
    cout << endl;
    cout << "b: ";
    b.imprimir();
    cout << endl;*/
    
    EnteroLargo resultado = a.mult820Clasica(b);
    resultado.imprimir();
    cout << endl;
    resultado = a.mult820NoRapida(b);
    resultado.imprimir();
    cout << endl;
    resultado = a.mult820Karat(b);
    resultado.imprimir();
}
