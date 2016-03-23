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
        EnteroLargo multEntero(int a);
        EnteroLargo suma(EnteroLargo b);
        EnteroLargo multClasica(EnteroLargo a);
        void desplazarEntero(int desp);
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

EnteroLargo EnteroLargo::multEntero(int a) {
    int llevada = 0;
    list<char> resultado;
    
    list<char>::iterator it = digitos.begin();
    while (it != digitos.end()){
        int mult = ((*it - '0') * a) + llevada;
        resultado.push_back((mult % 10) + '0');
        llevada = mult/10;
        it++;
    }
    
    if (llevada != 0) {
        resultado.push_back(llevada + '0');
    }
    
    return EnteroLargo(resultado);
}


EnteroLargo EnteroLargo::multClasica(EnteroLargo a){
    list<char> resultado;
    EnteroLargo prodInt[longitud];
    int i = 0;
    
    
    list<char>::iterator it = digitos.begin();

    while(it != digitos.end()){

        prodInt[i]= a.multEntero(*it - '0');
        prodInt[i].desplazarEntero(i);
        it++;
        i++;
    }
    
    for (int j = 1; j < longitud; j++) {
        prodInt[j] = prodInt[j-1].suma(prodInt[j]);
    }
    
    return prodInt[longitud-1];
}

void EnteroLargo::desplazarEntero(int desp) {
    for (int i = 0; i < desp; i++) {
        digitos.push_front('0');
    }
    longitud+=desp;
}

int main(void) {
    list<char> lectura;
    
    for (int i = 0; i < 32; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo a = EnteroLargo(lectura);
    
    lectura.clear();
    for (int i = 0; i < 32; i++) {
        char digito;
        cin >> digito;
        lectura.push_front(digito);
    }
    EnteroLargo b = EnteroLargo(lectura);
    
    
    a.imprimir();
    b.imprimir();
    
    
    /*EnteroLargo suma = a.suma(b);
    cout << "La suma es: ";
    suma.imprimir();
    
    
    EnteroLargo a3 = a.multEntero(9);
    cout << "La mult por 9 es: ";
    a3.imprimir();*/
    
    EnteroLargo mult = a.multClasica(b);
    cout << "La multEL es: " << endl;
    mult.imprimir();
    
    
}
