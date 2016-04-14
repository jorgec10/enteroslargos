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
    
    //EnteroLargo prueba1 = EnteroLargo("6", false);
    //EnteroLargo prueba2 = EnteroLargo("6", true);
    
    
    
    
    
    
    
    
    cout << "a: ";
    a.imprimir();
    cout << endl;
    cout << "b: ";
    b.imprimir();
    cout << endl;
    
    //cout << "La multiplicacion clasica de los dos EL es: " << endl;
    a.multClasica(b).imprimir();
    cout << endl;
    //cout << "La multiplicacion no rapida de los dos EL es: " << endl;
    a.multNoRapida(b).imprimir();
    cout << endl;
    //cout << "La multiplicacion karat de los dos EL es: " << endl;
    a.multKarat(b).imprimir();
    cout << endl;
    
    /*cout << endl << "Compara: ";
    cout << prueba1.compara(prueba2);
    cout << endl;
    
    cout << endl << "Prueba: ";
    prueba1.suma(prueba2).imprimir();
    cout << endl;
    */

    
    
}
