#include "EnteroLargo.h"
#include <iostream>
#include <list>
using namespace std;

// Constructor de un entero largo, sin parámetros.
// Es equivalente a crear el entero largo que representa al cero.
EnteroLargo::EnteroLargo(){
    longitud = 0;
    signo = true;
}

// Constructor de un entero largo a partir de un string que contiene los digitos
// y el signo, true=positivo y false=negativo.
EnteroLargo::EnteroLargo(string entero, bool sig){
    signo = sig;
    longitud = entero.size();
    for (int i = 0; i < longitud; i++) {
        digitos.push_front(entero[i]);
    }
}

// Constructor de un entero largo a partir de una lista que contiene los digitos
// y el signo, true=positivo y false=negativo.
EnteroLargo::EnteroLargo(list<char> entero, bool sig){
    list<char>::iterator it = entero.begin();
    while(it!=entero.end()) {
        digitos.push_back(*it);
        it++;
    }
    signo = sig;
    longitud = entero.size();
}

// Método que nos permite obtener la longitud de un entero largo.
int EnteroLargo::getLongitud(){
    return longitud;
}

// Método para cambiar el signo de un entero largo, recibe como parámetro el
// nuevo signo.
void EnteroLargo::setSigno(bool sign) {
    signo = sign;
}

// Método que se usa para imprimir por pantalla un entero largo.
void EnteroLargo::imprimir() {
    // Imprime el signo menos cuando es necesario.
    if (!signo) {
        cout << "-";
    }
    // Recorrido de los digitos en orden inverso para imprimir los digitos
    list<char>::iterator it = --digitos.end();
    while(it!=--digitos.begin()) {
        cout << *it;
        it--;
    }
}

// Método que compara dos enteros largos recibidos como parámetros. Si a>b devuelve 1,
// si a<b devuelve -1 y si a=b devuelve 0.
int EnteroLargo::compara(EnteroLargo a, EnteroLargo b){

    // Primero eliminamos posibles apariciones de ceros a la izquierda
    while(a.digitos.back() == '0' && a.digitos.size()>1) {
        a.digitos.pop_back();
        a.longitud--;
    }
    while(b.digitos.back() == '0' && b.digitos.size()>1) {
        b.digitos.pop_back();
        b.longitud--;
    }
    // Para posibilitar la reducción del orden, probamos a comparar por longitud.
    if (a.longitud > b.longitud) return 1;
    else if (a.longitud < b.longitud) return -1;
    // Si son dos enteros de la misma longitud, hay que recorrerlos digito a digito
    // e ir comparando.
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

// Método que permite realizar la suma de dos enteros largos a y b. Se obtiene
// el entero largo resultado de la suma.
EnteroLargo EnteroLargo::suma(EnteroLargo a, EnteroLargo b) {

    int llevada=0; // Usamos este entero para llevar la cuenta del acarreo.
    list<char> resultado;

    // Si tienen el mismo signo, se suman los enteros y se pone el signo.
    if (a.signo == b.signo){
        list<char>::iterator ita = a.digitos.begin();
        list<char>::iterator itb = b.digitos.begin();

        // Recorremos cifra a cifra y vamos haciendo la suma hasta que uno de los
        // números llega a su fin.
        while(ita != a.digitos.end() && itb != b.digitos.end()) {
            int suma = (*ita - '0') + (*itb - '0') + llevada;
            resultado.push_back((suma % 10) + '0');
            llevada = suma/10;

            ita++;
            itb++;
        }
        // Esta comprobación permite tratar enteros largos con distinta longitud.
        // Ya que cuando termina el recorrido de los dígitos de uno de ellos,
        // añade los dígitos del otro.
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

        // Si al terminar de recorrer ambos números nos queda un acarreo, se añade
        // al principio del entero largo resultante.
        if (llevada != 0) {
            resultado.push_back(llevada + '0');
        }

        return EnteroLargo(resultado, a.signo);

    // Si son de distinto signo, tenemos que ver cual de ellos es el mayor, hacer la
    // resta del mayor menos el menor y poner el signo del mayor.
    } else {

        // Iteradores para recorrer posteriormente los números.
        list<char>::iterator itMayor;
        list<char>::iterator itMenor;
        list<char>::iterator finMayor;
        list<char>::iterator finMenor;
        bool signoMayor;

        // Realizamos la comparación para ver qué entero es mayor.
        // Con este bloque de código inicializamos los iteradores para
        // realizar una resta genérica.
        switch (compara(a,b)) {
            // Si son iguales, el resultado de la suma es cero
            case 0: {
                        for (int i = 0; i < a.longitud; i++) {
                            resultado.push_back('0');
                        }
                        return EnteroLargo(resultado, true);
            }
            // Si a es mayor que b.
            case 1: {
                        itMayor = a.digitos.begin();
                        finMayor = a.digitos.end();
                        itMenor = b.digitos.begin();
                        finMenor = b.digitos.end();
                        signoMayor = a.signo;
                        break;
            }
            // Si a es menor que b.
            case -1: {
                        itMayor = b.digitos.begin();
                        finMayor = b.digitos.end();
                        itMenor = a.digitos.begin();
                        finMenor = a.digitos.end();
                        signoMayor = b.signo;
                        break;
            }
        }

        // Recorremos cifra a cifra y vamos haciendo la resta hasta que uno de los
        // números llega a su fin.
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

        // Esta comprobación permite tratar enteros largos con distinta longitud.
        // Ya que cuando termina el recorrido de los dígitos de uno de ellos,
        // añade los dígitos del otro.
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

// Método que permite realizar la resta de dos enteros largos a y b.
// Devuelve el resultado de la resta.
EnteroLargo EnteroLargo::resta(EnteroLargo a, EnteroLargo b) {
    // Este método ha sido implementado utilizando la suma implementada
    // anteriormente, ya que está nos permite realizar sumas con enteros largos
    // de distinto signo. Por tanto, cuando se solicita la resta: a-b; el
    // algoritmo calcula a + (-b)
    return suma(a, EnteroLargo(b.digitos, !b.signo));
}

// Método que realiza la multiplicación de un entero largo por 10^x, que en este caso es
// considerado un desplazamiento tantas veces como indique el entero pasado como parámetro.
void EnteroLargo::desplazarEntero(int desp) {
    for (int i = 0; i < desp; i++) {
        digitos.push_front('0');
    }
    longitud+=desp;
}

// Método usado para devolver una mitad de un entero largo, si el parámetro mitad
// es igual a true, devuelve la primera mitad; si es false, devuelve la segunda
// mitad.
EnteroLargo EnteroLargo::dividirEntero(bool mitad){
    list<char> resultado;
    int s = longitud/2;    // Será usada después para realizar la comprobación de la mitad.
    int indice = 0;        // Junto a la variable s nos permite realizar el recorrido para obtener la mitad.

    // Mete en la lista resultado los dígitos de la primera mitad del entero largo.
    if(!mitad){
        list<char>::iterator it = digitos.begin();
        while(it != digitos.end() && indice < s){
            resultado.push_back(*it);
            it++;
            indice++;
        }

    // Mete en la lista resultado los dígitos de la segunda mitad del entero largo.
    } else {
        list<char>::iterator it = digitos.begin();
        // Avance "feo" para quitarnos la primera mitad
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


/*
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

}*/

// Método que realiza la multiplicación de un entero largo a por un entero b. El
// resultado es un nuevo entero largo. Este método es usado por la multiplicación
// clásica para simplificar su contenido y mejorar la legibilidad.
EnteroLargo EnteroLargo::multSencilla(EnteroLargo a, int b) {
    int llevada = 0; // Usamos este entero para llevar la cuenta del acarreo.
    list<char> resultado;

    // Recorre el entero largo cifra a cifra y va multiplicando por b, teniendo en
    // cuenta el acarreo.
    list<char>::iterator it = a.digitos.begin();
    while (it != a.digitos.end()){
        int mult = ((*it - '0') * b) + llevada;
        resultado.push_back((mult % 10) + '0');
        llevada = mult/10;
        it++;
    }

    // Si al terminar de recorrer el número nos queda un acarreo, se añade
    // al principio del entero largo resultante.
    if (llevada != 0) {
        resultado.push_back(llevada + '0');
    }

    return EnteroLargo(resultado, a.signo);
}


// Método que realiza la multiplicación clásica entre dos enteros largos, hace uso
// de la multiplicación sencilla. Representa el método directo de multiplicación
// requerido en la práctica.
EnteroLargo EnteroLargo::multClasica(EnteroLargo a, EnteroLargo b){
    EnteroLargo resultado;  // En esta variable se irán acumulando las sumas
                            // parciales en cada iteración del bucle principal
    int i = 0;              // Nos permite realizar los desplazamientos
                            // necesarios en el bucle.

    list<char>::iterator it = a.digitos.begin();

    // Recorremos el entero largo a de digito en digito, multiplicando cada digito por
    // el entero largo b.
    while(it != a.digitos.end()){
        EnteroLargo parcial; // Aquí guardamos el resultado de la multiplicación.
        parcial = multSencilla(b, *it -'0');
        parcial.desplazarEntero(i); // Desplazamiento que hay que tener en cuenta
                                    // para hacer las sumas parciales, en función
                                    // de i.
        resultado = suma(resultado, parcial);
        it++;
        i++;
    }

    // Si son de distinto signo, el resultado es de signo negativo
    if(b.signo != a.signo) resultado.setSigno(false);
    // si no, el resultado es de signo positivo.
    else resultado.setSigno(true);

    return resultado;
}


// Método que realiza la multiplicación de enteros largos a y b, mediante el método
// divide y vencerás no rápido. Es un método recursivo.
EnteroLargo EnteroLargo::multNoRapida(EnteroLargo a, EnteroLargo b, int casoBase){

    // Comprobación del caso base, si se cumple llama a la multiplicación clásica.
    // Es decir, un método directo. Equivalente a Pequeño(a, b) en esquema de diapositivas.
    if(a.longitud==casoBase || b.longitud==casoBase){
        return multClasica(a, b);   // Equivalente a SolucionDirecta(a, b).
    // Caso recursivo.
    } else {
        int s = a.longitud/2;       // Obtiene la mitad de longitud para realizar
                                    // futuros desplazamientos.

        // En las siguientes líneas se hace el cálculo de la siguiente fórmula.
        // del método divide y vencerás:
        // solucion = a*b = 10^(2s)*w*y + 10^(s)*(w*z+x*y) + x*z

        // Dividimos los enteros largos y los guardamos en las variables w, x, y, z.
        EnteroLargo w = a.dividirEntero(true);
        EnteroLargo x = a.dividirEntero(false);
        EnteroLargo y = b.dividirEntero(true);
        EnteroLargo z = b.dividirEntero(false);

        // Obtenemos los resultados parciales del método detallado arriba.
        EnteroLargo m1 = multNoRapida(w, y, casoBase);
        EnteroLargo m2 = suma(multNoRapida(w, z, casoBase), multNoRapida(x, y, casoBase));
        EnteroLargo m3 = multNoRapida(x, z, casoBase);

        // Realizamos los desplazamientos en función de s.
        m1.desplazarEntero(2*s);
        m2.desplazarEntero(s);

        // Obtenemos el resultado realizando las correspondientes sumas.
        EnteroLargo s1 = suma(m1, m2);
        EnteroLargo solucion = suma(s1, m3);

        // Si son de distinto signo, el resultado es de signo negativo
        if(b.signo != a.signo) return EnteroLargo(solucion.digitos, false);
        // si no, el resultado es de signo positivo.
        else return EnteroLargo(solucion.digitos, true);

    }
}

EnteroLargo EnteroLargo::multKarat(EnteroLargo a, EnteroLargo b, int casoBase){

    // Comprobación del caso base, si se cumple llama a la multiplicación clásica.
    // Es decir, un método directo. Equivalente a Pequeño(a, b) en esquema de diapositivas.
    if(a.longitud==casoBase || b.longitud==casoBase){
        return multClasica(a, b);   // Equivalente a SolucionDirecta(a, b).
    // Caso recursivo.
    } else {
        int s = a.longitud/2;       // Obtiene la mitad de longitud para realizar
                                    // futuros desplazamientos.

        // En las siguientes líneas se hace el cálculo de la siguiente fórmula.
        // del método divide y vencerás Karatsuba y Ofman:
        // solucion = u*v = 10^(2s)*w*y + 10^(s)*[(w-x)*(z-y) + w*y + x*z] + x*z

        // Dividimos los enteros largos y los guardamos en las variables w, x, y, z.
        EnteroLargo w = a.dividirEntero(true);
        EnteroLargo x = a.dividirEntero(false);
        EnteroLargo y = b.dividirEntero(true);
        EnteroLargo z = b.dividirEntero(false);

        // Obtenemos los resultados parciales del método detallado arriba.
        EnteroLargo m1 = multKarat(w, y, casoBase);
        EnteroLargo m3 = multKarat(x, z, casoBase);
        EnteroLargo m2 = multKarat(resta(w, x), resta(z, y), casoBase);
        m2 = suma(m2, m1);
        m2 = suma(m2, m3);

        // Realizamos los desplazamientos en función de s.
        m1.desplazarEntero(2*s);
        m2.desplazarEntero(s);

        // Obtenemos el resultado realizando las correspondientes sumas.
        EnteroLargo s1 = suma(m1, m2);
        EnteroLargo solucion = suma(s1, m3);

        // Si son de distinto signo, el resultado es de signo negativo
        if(a.signo != b.signo) return EnteroLargo(solucion.digitos, false);
        // si no, el resultado es de signo positivo.
        else return EnteroLargo(solucion.digitos, true);
    }
}

// Método para convertir un entero largo a string. Utilizado para comparar los
// resultados en las validaciones
string EnteroLargo::toTexto(){
  string resultado;
  resultado.reserve(longitud);

  // Añade el signo menos cuando es necesario.
  if (!signo) {
      resultado.push_back('-');
  }
  // Recorrido de los digitos en orden inverso para añadir los digitos
  list<char>::iterator it = --digitos.end();
  while(it!=--digitos.begin()) {
      resultado.push_back(*it);
      it--;
  }
  return resultado;
}
