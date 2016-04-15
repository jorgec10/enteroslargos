#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "EnteroLargo.h"
using namespace std;

EnteroLargo generadorEntero(int tamano){
    list<char> generado;
    for (int i = 0; i < tamano; i++) {
        generado.push_back((rand() % 10) + '0');
    }
    return EnteroLargo(generado, true);
}

void experimentos(int size) {
    

    EnteroLargo a = generadorEntero(size);
    EnteroLargo b = generadorEntero(size);
  
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
    cout << tiempo << endl;
}


// Argumentos: tamaño inicial, tamaño final, caso base inicial, caso base final
int main(int argc, char* argv[]){
    srand(time(NULL));
    
    int tamInicial = atoi(argv[1]);
    int tamFinal = atoi(argv[2]);
    
    cout << "Size, Clasica, noRapida, Karat" << endl;
    for (int i = tamInicial; i <= tamFinal; i=i*2) {
        experimentos(i);
    }
}
