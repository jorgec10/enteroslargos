#include <iostream>
#include "EnteroLargo.h"
#include "Entero820.h"
#include <string>
using namespace std;


int main(void) {
	//list<char> lectura;
/*
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
    
    
    Entero820 a = Entero820(I, J, enteros);
    
    
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            char digito;
            cin >> digito;
            lectura.push_front(digito);
        }
        enteros[j] = EnteroLargo(lectura, true);
        lectura.clear();
    }

    Entero820 b = Entero820(K, L, enteros);
    */
    
    
    Entero820 a820, b820;
    string lectura;
    
   
        cin >> lectura;
        //a = EnteroLargo(lectura, true);
        a820 = Entero820(I, J, lectura);
    
   
        cin >> lectura;
        //b = EnteroLargo(lectura, true);
        b820 = Entero820(K, L, lectura);
    
    
    
    
    
    
    
    /*cout << "a: ";
    a.imprimir();
    cout << endl;
    cout << "b: ";
    b.imprimir();
    cout << endl;*/
    
    /*EnteroLargo resultado = a.mult820Clasica(b);
    resultado.imprimir();
    cout << endl;
    resultado = a.mult820NoRapida(b);
    resultado.imprimir();
    cout << endl;
    resultado = a.mult820Karat(b);
    resultado.imprimir();*/
    a820.mult820Clasica(b820).imprimir();
    cout << endl;
    a820.mult820NoRapida(b820).imprimir(); 
    cout << endl;
    a820.mult820Karat(b820).imprimir();
}
