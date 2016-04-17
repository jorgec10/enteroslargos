#include "Entero820.h"
#include <iostream>
using namespace std;

Entero820::Entero820(){
    primer0=0;
    segundo0=0;
    tamEL=0;
}

Entero820::Entero820(int posA, int posB, string entero){
    primer0 = posA;
    segundo0 = posB;

    tamEL = entero.size()/EL820SIZE;

    for (int i = 0; i < EL820SIZE; i++) {
        string inserta = entero.substr(i*tamEL, tamEL);

        enteros[EL820SIZE-1-i] = EnteroLargo(inserta, true);
    }
}

Entero820::Entero820(int posA, int posB, EnteroLargo arrayEnteros[]){
    primer0=posA;
    segundo0=posB;

    tamEL = arrayEnteros[0].getLongitud();

    for (int i = 0; i < EL820SIZE; i++) {
        enteros[EL820SIZE-1-i]=arrayEnteros[i];
    }
}


void Entero820::imprimir() {
    for (int i = 0; i < EL820SIZE; i++) {
        enteros[EL820SIZE-1-i].imprimir();
    }
}

EnteroLargo Entero820::mult820Clasica(Entero820 a, Entero820 b){
    EnteroLargo resultado;

    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;

       if (i == b.primer0 || i == b.segundo0) {
              continue;
        }

        for (int j = 0; j < EL820SIZE; j++) {

             if (j == a.primer0 || j == a.segundo0) {
              continue;
            }

            EnteroLargo mult = EnteroLargo::multClasica(b.enteros[i], a.enteros[j]);
            mult.desplazarEntero(j*a.tamEL);
            parcial = EnteroLargo::suma(parcial, mult);
        }

        parcial.desplazarEntero(i*a.tamEL);
        resultado = EnteroLargo::suma(resultado, parcial);
    }

    return resultado;
}

EnteroLargo Entero820::mult820NoRapida(Entero820 a, Entero820 b, int casoBase){
    EnteroLargo resultado;

    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;

       if (i == b.primer0 || i == b.segundo0) {
              continue;
        }

        for (int j = 0; j < EL820SIZE; j++) {

             if (j == a.primer0 || j == a.segundo0) {
              continue;
            }

            EnteroLargo mult = EnteroLargo::multNoRapida(b.enteros[i], a.enteros[j], casoBase);
            mult.desplazarEntero(j*a.tamEL);
            parcial = EnteroLargo::suma(parcial, mult);
        }

        parcial.desplazarEntero(i*a.tamEL);
        resultado = EnteroLargo::suma(resultado, parcial);
    }

    return resultado;
}

EnteroLargo Entero820::mult820Karat(Entero820 a, Entero820 b, int casoBase){
    EnteroLargo resultado;

    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;

       if (i == b.primer0 || i == b.segundo0) {
              continue;
        }

        for (int j = 0; j < EL820SIZE; j++) {

             if (j == a.primer0 || j == a.segundo0) {
              continue;
            }

            EnteroLargo mult = EnteroLargo::multKarat(b.enteros[i], a.enteros[j], casoBase);
            mult.desplazarEntero(j*a.tamEL);
            parcial = EnteroLargo::suma(parcial, mult);
        }

        parcial.desplazarEntero(i*a.tamEL);
        resultado = EnteroLargo::suma(resultado, parcial);
    }

    return resultado;
}
