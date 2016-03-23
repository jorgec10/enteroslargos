#include <iostream>
#include <list>
using namespace std;

class EnteroLargo {
    private:
        list<char> digitos;
        int longitud;
        
    public:
        EnteroLargo(list<char> entero);
        EnteroLargo();
        void imprimir();
        EnteroLargo suma(EnteroLargo b);
        void desplazarEntero(int desp);
        EnteroLargo dividirEntero(bool mitad);
        EnteroLargo multKarat(EnteroLargo b);
        EnteroLargo resta(EnteroLargo b);
};

EnteroLargo::EnteroLargo(){
    longitud = 0;
}

EnteroLargo::EnteroLargo(list<char> entero){
    list<char>::iterator it = entero.begin();
    while(it!=entero.end()) {
        digitos.push_back(*it);
        it++;
    }
    longitud = entero.size();
}

void EnteroLargo::imprimir() {
    list<char>::iterator it = --digitos.end();
    
    while(it!=--digitos.begin()) {
        cout << *it;
        it--;
    }
    
    cout << endl;
}

EnteroLargo EnteroLargo::suma(EnteroLargo b) {
    int llevada=0;
    list<char> resultado;
    
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
    
    return EnteroLargo(resultado);
}

EnteroLargo EnteroLargo::resta(EnteroLargo b) {
    int llevada=0;
    list<char> resultado;
    
    list<char>::iterator ita = digitos.begin();
    list<char>::iterator itb = b.digitos.begin();
    
    while(ita != digitos.end() && itb != b.digitos.end()) {
        int resta;

        if (*ita >= *itb){
            resta = (*ita - '0') - ((*itb -'0') + llevada);
            llevada = 0;
        } else {
            resta = ((*ita - '0') + 10) - ((*itb -'0') + llevada);
            llevada = 1;
        }
        resultado.push_back(resta + '0');
    }
    return EnteroLargo(resultado);
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
    
    return EnteroLargo(resultado);
    
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
        return EnteroLargo(mult);
    } else {
        EnteroLargo w = dividirEntero(true);
        EnteroLargo x = dividirEntero(false);
        EnteroLargo y = b.dividirEntero(true);
        EnteroLargo z = b.dividirEntero(false);
        
        EnteroLargo m1 = w.multKarat(y);
        m1.desplazarEntero(2*s);

        EnteroLargo m3 = x.multKarat(z);

        EnteroLargo m2 = w.resta(x).multKarat(z.resta(y));
        m2 = m2.suma(m1).suma(m3);
        m2.desplazarEntero(s);
        
        
        EnteroLargo s1 = m1.suma(m2);
        EnteroLargo solucion = s1.suma(m3);
        return EnteroLargo(solucion.digitos);
    }
}


int main(void) {
    list<char> lectura;
    
    for (int i = 0; i < 8; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo a = EnteroLargo(lectura);
    
    lectura.clear();
    for (int i = 0; i < 8; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo b = EnteroLargo(lectura);
    
    a.imprimir();
    b.imprimir();
    
    /*cout << "La multiplicacion de los dos EL es: " << endl;
    a.multKarat(b).imprimir();*/
}
