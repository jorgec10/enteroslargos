#include "EnteroLargo.h"
#include <iostream>
#include <list>
using namespace std;


EnteroLargo::EnteroLargo(){
    longitud = 0;
    signo = true;
}

EnteroLargo::EnteroLargo(string entero, bool sig){
    signo = sig;
    longitud = entero.size();
    for (int i = 0; i < longitud; i++) {
        digitos.push_front(entero[i]);
    }
}

EnteroLargo::EnteroLargo(list<char> entero, bool sig){
    list<char>::iterator it = entero.begin();
    while(it!=entero.end()) {
        digitos.push_back(*it);
        it++;
    }
    signo = sig;
    longitud = entero.size();
}

int EnteroLargo::getLongitud(){
    return longitud;
}

void EnteroLargo::setSigno(bool sign) {
    signo = sign;
}


void EnteroLargo::imprimir() {
    if (!signo) {
        cout << "-";
    }


    list<char>::iterator it = --digitos.end();

    while(it!=--digitos.begin()) {
        cout << *it;
        it--;
    }
}

int EnteroLargo::compara(EnteroLargo a, EnteroLargo b){

    while(a.digitos.back() == '0' && a.digitos.size()>1) {
        a.digitos.pop_back();
        a.longitud--;
    }

    while(b.digitos.back() == '0' && b.digitos.size()>1) {
        b.digitos.pop_back();
        b.longitud--;
    }

    if (a.longitud > b.longitud) return 1;
    else if (a.longitud < b.longitud) return -1;
    else{
        list<char>::iterator ita = --a.digitos.end();
        list<char>::iterator itb = --b.digitos.end();

        while (ita != --a.digitos.begin()){
            if (*ita > * itb) return 1;
            else if (*ita < * itb) return -1;
            else{
                ita--;
                itb--;
            }
        }
        return 0;
    }
}


EnteroLargo EnteroLargo::suma(EnteroLargo a, EnteroLargo b) {

    int llevada=0;
    list<char> resultado;

    if (a.signo == b.signo){ // Mismo signo, se suman y se pone el signo.
        list<char>::iterator ita = a.digitos.begin();
        list<char>::iterator itb = b.digitos.begin();


        while(ita != a.digitos.end() && itb != b.digitos.end()) {
            int suma = (*ita - '0') + (*itb - '0') + llevada;
            resultado.push_back((suma % 10) + '0');
            llevada = suma/10;

            ita++;
            itb++;
        }

        if (ita == a.digitos.end()) {
            while(itb != b.digitos.end()){
                int suma=(*itb - '0') + llevada;
                resultado.push_back((suma % 10) + '0');
                llevada = suma/10;
                itb++;
            }
        } else {
            while(ita != a.digitos.end()){
                int suma=(*ita - '0') + llevada;
                resultado.push_back((suma % 10) + '0');
                llevada = suma/10;
                ita++;
            }
        }

        if (llevada != 0) {
            resultado.push_back(llevada + '0');
        }

        return EnteroLargo(resultado, a.signo);

    } else { // Distinto signo

        list<char>::iterator itMayor;
        list<char>::iterator itMenor;
        list<char>::iterator finMayor;
        list<char>::iterator finMenor;
        bool signoMayor;

        switch (compara(a,b)) {
            case 0: {
                        for (int i = 0; i < a.longitud; i++) {
                            resultado.push_back('0');
                        }
                        return EnteroLargo(resultado, true);
            }
            case 1: {
                        itMayor = a.digitos.begin();
                        finMayor = a.digitos.end();
                        itMenor = b.digitos.begin();
                        finMenor = b.digitos.end();
                        signoMayor = a.signo;
                        break;
            }
            case -1: {
                        itMayor = b.digitos.begin();
                        finMayor = b.digitos.end();
                        itMenor = a.digitos.begin();
                        finMenor = a.digitos.end();
                        signoMayor = b.signo;
                        break;
            }
        }

        while(itMayor != finMayor && itMenor != finMenor) {
            int resta;

            if (*itMayor >= (*itMenor + llevada)){
                resta = (*itMayor - '0') - ((*itMenor -'0') + llevada);
                llevada = 0;
            } else {
                resta = ((*itMayor - '0') + 10) - ((*itMenor -'0') + llevada);
                llevada = 1;
            }
            itMayor++;
            itMenor++;
            resultado.push_back(resta + '0');
        }

        if (itMayor == finMayor) {
            while(itMenor != finMenor){
                int resta=(*itMenor - '0') - llevada;
                resultado.push_back((resta % 10) + '0');
                llevada = resta/10;
                itMenor++;
            }
        } else {
            while(itMayor != finMayor){
                int resta=(*itMayor - '0') - llevada;
                resultado.push_back((resta % 10) + '0');
                llevada = resta/10;
                itMayor++;
            }
        }

        return EnteroLargo(resultado, signoMayor);
    }
}

EnteroLargo EnteroLargo::resta(EnteroLargo a, EnteroLargo b) {
    return suma(a, EnteroLargo(b.digitos, !b.signo));
}


void EnteroLargo::desplazarEntero(int desp) {
    for (int i = 0; i < desp; i++) {
        digitos.push_front('0');
    }
    longitud+=desp;
}

EnteroLargo EnteroLargo::dividirEntero(bool mitad){
     list<char> resultado;
      int s = longitud/2;
      int indice = 0;
     if(!mitad){ // Primera mitad
        list<char>::iterator it = digitos.begin();
         while(it != digitos.end() && indice < s){
             resultado.push_back(*it);
             it++;
             indice++;
         }
     } else { // Segunda mitad
         list<char>::iterator it = digitos.begin();
         while(it !=digitos.end() && indice < s){
             it++;
             indice++;
        }
         while(it != digitos.end()){
             resultado.push_back(*it);
             it++;
         }
         }
         return EnteroLargo(resultado, signo);
	 }



EnteroLargo * EnteroLargo::dividirEntero(){
    list<char> primeraMitad;
    list<char> segundaMitad;
    int s = longitud/2;
    int indice = 0;
    static EnteroLargo resultado[2];

    list<char>::iterator it = digitos.begin();
    while(it != digitos.end() && indice < s){
        primeraMitad.push_back(*it);
        it++;
        indice++;
    }
    while(it != digitos.end()){
        segundaMitad.push_back(*it);
        it++;
    }

    EnteroLargo primero = EnteroLargo(primeraMitad, signo);
    EnteroLargo segundo = EnteroLargo(segundaMitad, signo);

    resultado[0] = primero;
    resultado[1] = segundo;

    return resultado;

}

EnteroLargo EnteroLargo::multSencilla(EnteroLargo a, int b) {
    int llevada = 0;
    list<char> resultado;

    list<char>::iterator it = a.digitos.begin();
    while (it != a.digitos.end()){
        int mult = ((*it - '0') * b) + llevada;
        resultado.push_back((mult % 10) + '0');
        llevada = mult/10;
        it++;
    }

    if (llevada != 0) {
        resultado.push_back(llevada + '0');
    }

    return EnteroLargo(resultado, a.signo);
}

EnteroLargo EnteroLargo::multClasica(EnteroLargo a, EnteroLargo b){
    EnteroLargo resultado;
    int i = 0;

    list<char>::iterator it = a.digitos.begin();

    while(it != a.digitos.end()){
        EnteroLargo parcial;
        parcial = multSencilla(b, *it -'0');
        parcial.desplazarEntero(i);
        resultado = suma(resultado, parcial);
        it++;
        i++;
    }

    if(b.signo != a.signo) resultado.setSigno(false);
    else resultado.setSigno(true);

    return resultado;
}

EnteroLargo EnteroLargo::multNoRapida(EnteroLargo a, EnteroLargo b, int casoBase){
    int s = a.longitud/2;
    if(a.longitud==casoBase || b.longitud==casoBase){
        return multClasica(a, b);
    } else {

        EnteroLargo w = a.dividirEntero(true);
        EnteroLargo x = a.dividirEntero(false);
        EnteroLargo y = b.dividirEntero(true);
        EnteroLargo z = b.dividirEntero(false);

        EnteroLargo m1 = multNoRapida(w, y, casoBase);
        EnteroLargo m2 = suma(multNoRapida(w, z, casoBase), multNoRapida(x, y, casoBase));
        EnteroLargo m3 = multNoRapida(x, z, casoBase);
        
        m1.desplazarEntero(2*s);
        m2.desplazarEntero(s);

        EnteroLargo s1 = suma(m1, m2);
        EnteroLargo solucion = suma(s1, m3);

        if(b.signo != a.signo) return EnteroLargo(solucion.digitos, false);
        else return EnteroLargo(solucion.digitos, true);

    }
}

EnteroLargo EnteroLargo::multKarat(EnteroLargo a, EnteroLargo b, int casoBase){

    int s = a.longitud/2;
    if(a.longitud==casoBase || b.longitud==casoBase){
        return multClasica(a, b);
    } else {

        EnteroLargo w = a.dividirEntero(true);
        EnteroLargo x = a.dividirEntero(false);
        EnteroLargo y = b.dividirEntero(true);
        EnteroLargo z = b.dividirEntero(false);

        EnteroLargo m1 = multKarat(w, y, casoBase);
        EnteroLargo m3 = multKarat(x, z, casoBase);
        EnteroLargo m2 = multKarat(resta(w, x), resta(z, y), casoBase);

        m2 = suma(m2, m1);
        m2 = suma(m2, m3);
        
        m1.desplazarEntero(2*s);
        m2.desplazarEntero(s);

        EnteroLargo s1 = suma(m1, m2);
        EnteroLargo solucion = suma(s1, m3);

        if(a.signo != b.signo) return EnteroLargo(solucion.digitos, false);
        else return EnteroLargo(solucion.digitos, true);
    }
}
