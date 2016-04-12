#ifndef __ENTERO_820__
#define __ENTERO_820__
#define ELSIZE 8

#include "EnteroLargo.h"

class Entero820 {
    private:
        EnteroLargo enteros[ELSIZE];
        int primer0;
        int segundo0;
        
    public:
        Entero820(int posA, int posB, EnteroLargo arrayEnteros[]);
        Entero820();
        void imprimir();
        
        EnteroLargo mult820Clasica(Entero820 b);
        EnteroLargo mult820NoRapida(Entero820 b);
        EnteroLargo mult820Karat(Entero820 b);
};

#endif