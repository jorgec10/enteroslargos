#ifndef __ENTERO_820__
#define __ENTERO_820__

#include "EnteroLargo.h"

#define EL820SIZE 8

#define I 0
#define J 2
#define K 4
#define L 0

class Entero820 {
    private:
        // Array de enteros largos que componen el entero820. Se almacenan en 
        // orden inverso para facilitar su tratamiento.
        EnteroLargo enteros[EL820SIZE];
        // Tamaño de los enteros largos que lo componen.
        int tamEL;
        
        // Características de los enteros820.
        // Primera posición donde hay un entero largo = 0.
        int primer0;
        // Segunda posición donde hay un entero largo = 0.
        int segundo0;

    public:
    
        // Todos los métodos y constructores se encuentran documentados en Entero820.cpp
        Entero820();
        Entero820(int posA, int posB, string entero);
        Entero820(int posA, int posB, EnteroLargo arrayEnteros[]);

        void imprimir();

        static EnteroLargo mult820Clasica(Entero820 a, Entero820 b);
        static EnteroLargo mult820NoRapida(Entero820 a, Entero820 b, int casoBase);
        static EnteroLargo mult820Karat(Entero820 a, Entero820 b, int casoBase);
};

#endif
