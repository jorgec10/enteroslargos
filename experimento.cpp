#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "EnteroLargo.h"
#include "Entero820.h"
using namespace std;

EnteroLargo generadorEntero(int tamano){
    list<char> generado;
    for (int i = 0; i < tamano; i++) {
        generado.push_back((rand() % 10) + '0');
    }
    return EnteroLargo(generado, true);
}

Entero820 generador820(int posA, int posB, int tamEL){
    EnteroLargo enteros[EL820SIZE];
    
    string ceros;
    ceros.reserve(tamEL);
    
    for (int i = 0; i < tamEL; i++) {
        ceros.push_back('0');
    }
    
    for (int i = 0; i < EL820SIZE; i++) {
        if(i==posA || i==posB){
            enteros[EL820SIZE-i-1] = EnteroLargo(ceros, true);
        }else enteros[EL820SIZE-i-1] = generadorEntero(tamEL);
    }
    return Entero820(posA, posB, enteros);
}


void experimentos(int size) {
    

    EnteroLargo a = generadorEntero(size);
    EnteroLargo b = generadorEntero(size);
    
    Entero820 a820 = generador820(I, J, size);
    Entero820 b820 = generador820(K, L, size);
    
    //cout << size << ": ";
    
    a.multClasica(b).imprimir();
    cout << endl;
    a.multNoRapida(b).imprimir();
    cout << endl;
    a.multKarat(b).imprimir();
    cout << endl << endl;
    
    a820.mult820Clasica(b820).imprimir();
    cout << endl;
    a820.mult820NoRapida(b820).imprimir();
    cout << endl;
    a820.mult820Karat(b820).imprimir();
    cout << endl << endl;
    
}


// Argumentos: tamaño inicial, tamaño final, caso base inicial, caso base final
int main(int argc, char* argv[]){
    srand(time(NULL));
    
    int tamInicial = atoi(argv[1]);
    int tamFinal = atoi(argv[2]);
    
    for (int i = tamInicial; i <= tamFinal; i=i*2) {
        experimentos(i);
    }
}
