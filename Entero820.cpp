#include "Entero820.h"
#include <iostream>
using namespace std;

Entero820::Entero820(){
    primer0=0;
    segundo0=0;
    longitud=0;
}


Entero820::Entero820(int posA, int posB, EnteroLargo arrayEnteros[]){
    primer0=posA;
    segundo0=posB;
    
    // Sabemos que es siempre de 8
    for (int i = 0; i < 8; i++) {
        enteros[i]=arrayEnteros[i];
    }
}


void Entero820::imprimir() {
    for (int i = 0; i < 8; i++) {
        enteros[i].imprimir();
    }
}
