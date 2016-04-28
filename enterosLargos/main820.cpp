#include <iostream>
#include "EnteroLargo.h"
#include "Entero820.h"
#include <string>
using namespace std;


int main(void) {
	Entero820 a820, b820;
    string lectura;

    cin >> lectura;
    a820 = Entero820(I, J, lectura);

    cin >> lectura;
    b820 = Entero820(K, L, lectura);

    Entero820::mult820Clasica(a820, b820).EnteroLargo::imprimir();
    cout << endl;
    Entero820::mult820NoRapida(a820, b820, 4).EnteroLargo::imprimir();
    cout << endl;
    Entero820::mult820Karat(a820, b820, 4).EnteroLargo::imprimir();
}
