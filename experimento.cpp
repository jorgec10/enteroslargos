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

Entero820 generador820(int posA, int posB){
    EnteroLargo enteros[EL820SIZE];
    for (int i = 0; i < EL820SIZE; i++) {
        if(i==posA || i==posB){
            enteros[ELSIZE-i-1] = EnteroLargo("00000000", true);
        }else enteros[ELSIZE-i-1] = generadorEntero(ELSIZE);
    }
    return Entero820(posA, posB, enteros);
}




int main(){
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        EnteroLargo r = generadorEntero(64);
        r.imprimir();
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        Entero820 r = generador820(I, J);
        r.imprimir();
        cout << endl;
    }
    
}
