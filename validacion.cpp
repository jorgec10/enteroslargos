#include <iostream>
#include "EnteroLargo.h"
#include "Entero820.h"
using namespace std;




bool formatoCorrecto(int longitud) {
    while (longitud > 8) {
            if (longitud%2 == 0)
                longitud = longitud/2;
            else break;
    }

    if (longitud == 8) {
        return true;
    }
    return false;
}

int main(void) {

    EnteroLargo a, b;
    Entero820 a820, b820;
    string lectura;

    do {
        cin >> lectura;
        a = EnteroLargo(lectura, true);
        a820 = Entero820(I, J, lectura);
    } while (!formatoCorrecto(lectura.size()));

    do {
        cin >> lectura;
        b = EnteroLargo(lectura, true);
        b820 = Entero820(K, L, lectura);
    } while (!formatoCorrecto(lectura.size()));

    a.imprimir();
    cout << endl;

    b.imprimir();
    cout << endl;

    a820.imprimir();
    cout << endl;

    b820.imprimir();
    cout << endl;


    cout << "Let's multiplicate" << endl;
    EnteroLargo::multClasica(a, b).imprimir();
    cout << endl;
    EnteroLargo::multNoRapida(a, b, 1).imprimir();
    cout << endl;
    EnteroLargo::multKarat(a, b, 1).imprimir();
    cout << endl << endl;

    cout << "Multiplicando enteros820" << endl;
    Entero820::mult820Clasica(a820, b820).imprimir();
    cout << endl;
    Entero820::mult820NoRapida(a820, b820, 1).imprimir();
    cout << endl;
    Entero820::mult820Karat(a820, b820, 1).imprimir();
    cout << endl;



}
