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


void experimentos(int size, int casoBase) {


    EnteroLargo a = generadorEntero(size);
    EnteroLargo b = generadorEntero(size);

    Entero820 a820 = generador820(I, J, size);
    Entero820 b820 = generador820(K, L, size);

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
    cout << tiempo << ", ";

    gettimeofday(&inicio, NULL);
    Entero820::mult820Clasica(a820, b820);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";

    gettimeofday(&inicio, NULL);
    Entero820::mult820NoRapida(a820, b820, casoBase);
    gettimeofday(&fin, NULL);
    tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    cout << tiempo << ", ";

    gettimeofday(&inicio, NULL);
    Entero820::mult820Karat(a820, b820, casoBase);
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

    cout << "Size, Caso Base, Clasica, noRapida, Karat, 820Clasica, 820noRapida, 820Karat" << endl;
    for (int i = tamInicial; i <= tamFinal; i=i*2) {
        for (int j = baseInicial; j <= baseFinal; j=j*2) {
            experimentos(i, j);
        }
    }
}
