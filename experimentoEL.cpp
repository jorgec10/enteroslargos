#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "EnteroLargo.h"
using namespace std;

// Método que genera enteros largos aleatorios de un tamaño determinado.
EnteroLargo generadorEntero(int tamano){
    list<char> generado;
    for (int i = 0; i < tamano; i++) {
        generado.push_back((rand() % 10) + '0');
    }
    return EnteroLargo(generado, true);
}

// Método que realiza las multiplicaciones y mide el tiempo que tarda cada una,
// imprimiendo por pantalla los resultados en un formato que permite que éstos 
// puedan ser importados a una hoja de cálculo.
void experimentos(int size, int casoBase) {


    EnteroLargo a = generadorEntero(size);
    EnteroLargo b = generadorEntero(size);

    struct timeval inicio, fin;
    double tiempo;


    cout << size << ", " << casoBase << ", ";

    gettimeofday(&inicio, NULL);
    EnteroLargo::multClasica(a, b);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";

    gettimeofday(&inicio, NULL);
    EnteroLargo::multNoRapida(a, b, casoBase);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";

    gettimeofday(&inicio, NULL);
    EnteroLargo::multKarat(a, b, casoBase);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << endl;
}


// Argumentos: tamaño inicial, tamaño final, caso base inicial, caso base final
int main(int argc, char* argv[]){
    srand(time(NULL));

    int tamInicial = atoi(argv[1]);
    int tamFinal = atoi(argv[2]);
    int baseInicial = atoi(argv[3]);
    int baseFinal = atoi(argv[4]);

    cout << "Size, Caso Base, Clasica, noRapida, Karat" << endl;
    for (int i = tamInicial; i <= tamFinal; i=i*2) {
        for (int j = baseInicial; j <= baseFinal; j=j*2) {
            experimentos(i, j);
        }
    }
}
