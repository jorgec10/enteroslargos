#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
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
    
    struct timeval inicio, fin;
    double tiempo;
    
    cout << size << ", ";
    
    gettimeofday(&inicio, NULL);
    a.multClasica(b);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";
    
    gettimeofday(&inicio, NULL);
    a.multNoRapida(b);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";
    
    gettimeofday(&inicio, NULL);
    a.multKarat(b);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";
    
    gettimeofday(&inicio, NULL);
    a820.mult820Clasica(b820);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";
    
    gettimeofday(&inicio, NULL);
    a820.mult820NoRapida(b820);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";
    
    gettimeofday(&inicio, NULL);
    a820.mult820Karat(b820);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << endl;
}


// Argumentos: tamaño inicial, tamaño final, caso base inicial, caso base final
int main(int argc, char* argv[]){
    srand(time(NULL));
    
    int tamInicial = atoi(argv[1]);
    int tamFinal = atoi(argv[2]);
    
    cout << "Size, Clasica, noRapida, Karat, 820Clasica, 820noRapida, 820Karat" << endl;
    for (int i = tamInicial; i <= tamFinal; i=i*2) {
        experimentos(i);
    }
}
