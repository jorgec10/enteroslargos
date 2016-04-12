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
        EnteroLargo * dividirEntero();
        EnteroLargo multRapida(EnteroLargo b);
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
    
    EnteroLargo primero = EnteroLargo(primeraMitad);
    EnteroLargo segundo = EnteroLargo(segundaMitad);
    
    resultado[0] = primero;
    resultado[1] = segundo;

    return resultado;

}

EnteroLargo EnteroLargo::multRapida(EnteroLargo b){
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
        EnteroLargo * ptrA = this->dividirEntero();
        EnteroLargo * ptrB = b.dividirEntero();
        
        EnteroLargo w = *ptrA;
        EnteroLargo x = *(ptrA + 1);
        EnteroLargo y = *ptrB;
        EnteroLargo z = *(ptrB + 1);
        
        EnteroLargo m1 = w.multRapida(y);
        m1.desplazarEntero(2*s);
        EnteroLargo m2 = w.multRapida(z).suma(x.multRapida(y));
        m2.desplazarEntero(s);
        EnteroLargo m3 = x.multRapida(z);
        
        EnteroLargo s1 = m1.suma(m2);
        EnteroLargo solucion = s1.suma(m3);
        return EnteroLargo(solucion.digitos);
    }
}


int main(void) {
    list<char> lectura;
    
    for (int i = 0; i < 1024; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo a = EnteroLargo(lectura);
    
    lectura.clear();
    for (int i = 0; i < 1024; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo b = EnteroLargo(lectura);
    
    a.imprimir();
    b.imprimir();
    
    cout << "La multiplicacion de los dos EL es: " << endl;
    a.multRapida(b).imprimir();
}
