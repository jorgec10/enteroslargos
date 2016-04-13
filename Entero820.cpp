#include "Entero820.h"
#include <iostream>
using namespace std;

Entero820::Entero820(){
    primer0=0;
    segundo0=0;
}

Entero820::Entero820(int posA, int posB, string entero){
    primer0 = posA;
    segundo0 = posB;
    
    int longitud = entero.size();
    list<char> digitosEL;
    
    for (int i = 0; i < EL820SIZE; i++) {
        string inserta = entero.substr(i*ELSIZE, ELSIZE);
        enteros[i] = EnteroLargo(inserta, true);
        
        /*digitosEL.push_front(entero[i]);
        if (i % ELSIZE == 0 && i!=0){
            enteros[(i/ELSIZE)-1] = EnteroLargo(digitosEL, true);
            digitosEL.clear();
        }*/
    }
}

Entero820::Entero820(int posA, int posB, EnteroLargo arrayEnteros[]){
    primer0=posA;
    segundo0=posB;
    
    for (int i = 0; i < EL820SIZE; i++) {
        enteros[EL820SIZE-1-i]=arrayEnteros[i];
    }
}


void Entero820::imprimir() {
    for (int i = 0; i < EL820SIZE; i++) {
        enteros[i].imprimir();
    }
}

EnteroLargo Entero820::mult820Clasica(Entero820 b){
    EnteroLargo resultado;
    
    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;
        
       if (i == b.primer0 || i == b.segundo0) {
              continue;  
        }
        
        for (int j = 0; j < EL820SIZE; j++) {
            
             if (j == primer0 || j == segundo0) {
              continue;  
            }
        
            EnteroLargo mult = b.enteros[i].multClasica(enteros[j]);
            mult.desplazarEntero(j*ELSIZE);
            parcial = parcial.suma(mult);
        }
        
        parcial.desplazarEntero(i*ELSIZE);
        resultado = resultado.suma(parcial);
    }
    
    return resultado;
}

EnteroLargo Entero820::mult820NoRapida(Entero820 b){
    EnteroLargo resultado;
    
    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;
        
       if (i == b.primer0 || i == b.segundo0) {
              continue;  
        }
        
        for (int j = 0; j < EL820SIZE; j++) {
            
             if (j == primer0 || j == segundo0) {
              continue;  
            }
        
            EnteroLargo mult = b.enteros[i].multNoRapida(enteros[j]);
            mult.desplazarEntero(j*ELSIZE);
            parcial = parcial.suma(mult);
        }
        
        parcial.desplazarEntero(i*ELSIZE);
        resultado = resultado.suma(parcial);
    }
    
    return resultado;
}

EnteroLargo Entero820::mult820Karat(Entero820 b){
    EnteroLargo resultado;
    
    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;
        
       if (i == b.primer0 || i == b.segundo0) {
              continue;  
        }
        
        for (int j = 0; j < EL820SIZE; j++) {
            
             if (j == primer0 || j == segundo0) {
              continue;  
            }
        
            EnteroLargo mult = b.enteros[i].multKarat(enteros[j]);
            mult.desplazarEntero(j*ELSIZE);
            parcial = parcial.suma(mult);
        }
        
        parcial.desplazarEntero(i*ELSIZE);
        resultado = resultado.suma(parcial);
    }
    
    return resultado;
}