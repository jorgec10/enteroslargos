#include <iostream>
#include "EnteroLargo.h"
using namespace std;


int main(void) {
	list<char> lectura;

    for (int i = 0; i < 64; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo a = EnteroLargo(lectura, true);

    lectura.clear();
    for (int i = 0; i < 64; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo b = EnteroLargo(lectura, true);
    
    cout << "a: ";
    a.EnteroLargo::imprimir();
    cout << endl;
    cout << "b: ";
    b.EnteroLargo::imprimir();
    cout << endl;

    
    EnteroLargo::multClasica(a, b).EnteroLargo::imprimir();
    cout << endl;
    
    EnteroLargo::multNoRapida(a, b, 1).EnteroLargo::imprimir();
    cout << endl;
    
    EnteroLargo::multKarat(a, b, 1).EnteroLargo::imprimir();
    cout << endl;





}
