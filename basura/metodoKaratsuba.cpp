#include <iostream>
#include <list>
using namespace std;

class EnteroLargo {
    private:
        list<char> digitos;
        int longitud;
        bool signo;  // True -> positivo, False -> negativo

    public:
        EnteroLargo(list<char> entero, bool sig);
        EnteroLargo();
        void imprimir();
        EnteroLargo suma(EnteroLargo b);
        void desplazarEntero(int desp);
        EnteroLargo * dividirEntero();
        EnteroLargo multKarat(EnteroLargo b);
        EnteroLargo resta(EnteroLargo b);
        int compara(EnteroLargo b);
};

EnteroLargo::EnteroLargo(){
    longitud = 0;
    signo = true;
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

void EnteroLargo::imprimir() {
    if (signo) {
        cout << "+";
    } else {
        cout << "-";
    } 
        
    
    list<char>::iterator it = --digitos.end();

    while(it!=--digitos.begin()) {
        cout << *it;
        it--;
    }

    cout << endl;
}

int EnteroLargo::compara(EnteroLargo b){
    if (longitud > b.longitud) return 1;
    else if (longitud < b.longitud) return -1;
    else{
        list<char>::iterator ita = --digitos.end();
        list<char>::iterator itb = --b.digitos.end();
        
        while (ita != --digitos.begin()){
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


EnteroLargo EnteroLargo::suma(EnteroLargo b) {
    int llevada=0;
    list<char> resultado;

    if (signo == b.signo){ // Mismo signo, se suman y se pone el signo.
        list<char>::iterator ita = digitos.begin();
        list<char>::iterator itb = b.digitos.begin();
    
    
        while(ita != digitos.end() && itb != b.digitos.end()) {
            int suma = (*ita - '0') + (*itb - '0') + llevada;
            resultado.push_back((suma % 10) + '0');
            llevada = suma/10;
    
            ita++;
            itb++;
        }
    
        if (ita == digitos.end()) {
            while(itb != b.digitos.end()){
                int suma=(*itb - '0') + llevada;
                resultado.push_back((suma % 10) + '0');
                llevada = suma/10;
                itb++;
            }
        } else {
            while(ita != digitos.end()){
                int suma=(*ita - '0') + llevada;
                resultado.push_back((suma % 10) + '0');
                llevada = suma/10;
                ita++;
            }
        }
    
        if (llevada != 0) {
            resultado.push_back(llevada + '0');
        }
    
        return EnteroLargo(resultado, signo);
        
    } else { // Distinto signo
        
        list<char>::iterator itMayor;
        list<char>::iterator itMenor;
        list<char>::iterator finMayor;
        list<char>::iterator finMenor;
        bool signoMayor;
        
        switch (this->compara(b)) {
            case 0: {
                        for (int i = 0; i < longitud; i++) {
                            resultado.push_back('0');
                        }
                        return EnteroLargo(resultado, true);
            }
            case 1: {
                        itMayor = digitos.begin();
                        finMayor = digitos.end();
                        itMenor = b.digitos.begin();
                        finMenor = b.digitos.end();
                        signoMayor = signo;
                        break;
            }
            case -1: {
                        itMayor = b.digitos.begin();
                        finMayor = b.digitos.end();
                        itMenor = digitos.begin();
                        finMenor = digitos.end();
                        signoMayor = b.signo;
                        break;
            }
        }
        
        while(itMayor != finMayor && itMenor != finMenor) {
            int resta;
    
            if (*itMayor >= *itMenor){
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
        return EnteroLargo(resultado, signoMayor);
    }
}

EnteroLargo EnteroLargo::resta(EnteroLargo b) {
    return this->suma(EnteroLargo(b.digitos, !b.signo));
}


void EnteroLargo::desplazarEntero(int desp) {
    for (int i = 0; i < desp; i++) {
        digitos.push_front('0');
    }
    longitud+=desp;
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

EnteroLargo EnteroLargo::multKarat(EnteroLargo b){
    int s = longitud/2;
    if(longitud==1 && b.longitud==1){
        list<char> mult;
        int a = (*digitos.begin() - '0') * (*b.digitos.begin() - '0');
        int modulo = a % 10;
        int llevada = a/10;
        mult.push_back(modulo + '0');
        if(llevada != 0){
            mult.push_back(llevada + '0');
        }
        return EnteroLargo(mult, signo);
    } else {
        
        EnteroLargo * ptrA = this->dividirEntero();
        EnteroLargo * ptrB = b.dividirEntero();
        
        EnteroLargo w = *ptrA;
        EnteroLargo x = *(ptrA + 1);
        EnteroLargo y = *ptrB;
        EnteroLargo z = *(ptrB + 1);
        
        
        
        
        /*
        EnteroLargo w = dividirEntero(true);
        EnteroLargo x = dividirEntero(false);
        EnteroLargo y = b.dividirEntero(true);
        EnteroLargo z = b.dividirEntero(false);*/

        EnteroLargo m1 = w.multKarat(y);
        
        EnteroLargo m3 = x.multKarat(z);

        EnteroLargo m2 = w.resta(x).multKarat(z.resta(y));
        m2 = m2.suma(m1).suma(m3);

        m1.desplazarEntero(2*s);
        m2.desplazarEntero(s);
        
        EnteroLargo s1 = m1.suma(m2);
        EnteroLargo solucion = s1.suma(m3);
        
        return EnteroLargo(solucion.digitos, signo);
    }
}


int main(void) {
    list<char> lectura;

    for (int i = 0; i < 1024; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo a = EnteroLargo(lectura, true);

    lectura.clear();
    for (int i = 0; i < 1024; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo b = EnteroLargo(lectura, true);
    
    cout << "a: ";
    a.imprimir();
    cout << "b: ";
    b.imprimir();
    
    cout << "La multiplicacion de los dos EL es: " << endl;
    a.multKarat(b).imprimir();
}
