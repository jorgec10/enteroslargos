#ifndef __ENTERO_820__
#define __ENTERO_820__

#include "EnteroLargo.h"

class Entero820 {
    private:
        EnteroLargo enteros[8];
        int primer0;
        int segundo0;
        int longitud;
        
    public:
        Entero820(int posA, int posB, EnteroLargo arrayEnteros[]);
        Entero820();
};

#endif