#include "Entero820.h"
#include <iostream>
using namespace std;

// Constructor de un entero820, sin parámetros.
// Es equivalente a crear el entero820 que representa el 0.
Entero820::Entero820(){
    primer0=0;
    segundo0=0;
    tamEL=0;
}

// Constructor de un entero820 a partir de un string con los digitos
// que lo componen. También es necesario indicar en que posiciones
// se encuentran los dos ceros que lo caracterizan.
Entero820::Entero820(int posA, int posB, string entero){
    primer0 = posA;
    segundo0 = posB;

    tamEL = entero.size()/EL820SIZE;

    for (int i = 0; i < EL820SIZE; i++) {
        string inserta = entero.substr(i*tamEL, tamEL);

        enteros[EL820SIZE-1-i] = EnteroLargo(inserta, true);
    }
}

// Constructor de un entero820 a partir de un array que contiene los enteros largos
// que lo componen. También es necesario indicar en que posiciones
// se encuentran los dos ceros que lo caracterizan.
Entero820::Entero820(int posA, int posB, EnteroLargo arrayEnteros[]){
    primer0=posA;
    segundo0=posB;

    tamEL = arrayEnteros[0].getLongitud();

    for (int i = 0; i < EL820SIZE; i++) {
        enteros[EL820SIZE-1-i]=arrayEnteros[i];
    }
}

// Método que imprime por pantalla un entero820. Utiliza el método imprimir
// de los enteros largos que lo componen.
void Entero820::imprimir() {
    for (int i = 0; i < EL820SIZE; i++) {
        enteros[EL820SIZE-1-i].EnteroLargo::imprimir();
    }
}

// Método que realiza la multiplicación directa de dos enteros820 a y b, usando
// para ello la multiplicación clásica de los enteros largos.
// Devuelve un entero largo con el resultado de la multiplicación.
EnteroLargo Entero820::mult820Clasica(Entero820 a, Entero820 b){
    EnteroLargo resultado;          // Variable en la que se acumulan los resultados
                                    // parciales hasta obtener el resultado.

    // Usamos este primer for para recorrer el entero820 b, el recorrido se realiza
    // de entero largo en entero largo.
    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;        // Variable en la que se guarda el resultado de
                                    // la multiplicación de cada uno de los enteros
                                    // largos de b por el entero820 a.

        // Si en la posicion en la que nos encontramos hay algún 0, no se tiene en cuenta
        // para la suma. Nos saltamos la iteración para ahorrar tiempo.
        if (i != b.primer0 && i != b.segundo0) {

            // En este for recorremos el entero820 a, el recorrido se realiza
            // de entero largo en entero largo.
            for (int j = 0; j < EL820SIZE; j++) {

                // Si en la posicion en la que nos encontramos hay algún 0, no se
                // tiene en cuenta para la suma. Nos saltamos la iteración para
                // ahorrar tiempo.
                if (j != a.primer0 && j != a.segundo0) {

                    // En este punto llegamos a la multiplicacion directa entre dos
                    // enteros largos, que en este caso se realiza mediante la multiplicación
                    // clásica.
                    EnteroLargo mult = EnteroLargo::multClasica(b.enteros[i], a.enteros[j]);
                    // Tenemos en cuenta los correspondientes desplazamientos con respecto a.
                    mult.desplazarEntero(j*a.tamEL);
                    // Acumulamos el resultado en parcial.
                    parcial = EnteroLargo::suma(parcial, mult);
                }
            }
            // Tenemos en cuenta los correspondientes desplazamientos con respecto a b.
            parcial.desplazarEntero(i*b.tamEL);
            // Acumulamos la suma en el entero largo resultado.
            resultado = EnteroLargo::suma(resultado, parcial);
        }
    }

    return resultado;
}

// Método que realiza la multiplicación directa de dos enteros820 a y b, usando
// para ello la multiplicación divide y venceras no rápida de los enteros largos.
// Devuelve un entero largo con el resultado de la multiplicación.
EnteroLargo Entero820::mult820NoRapida(Entero820 a, Entero820 b, int casoBase){
    EnteroLargo resultado;          // Variable en la que se acumulan los resultados
                                    // parciales hasta obtener el resultado.

    // Usamos este primer for para recorrer el entero820 b, el recorrido se realiza
    // de entero largo en entero largo.
    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;        // Variable en la que se guarda el resultado de
                                    // la multiplicación de cada uno de los enteros
                                    // largos de b por el entero820 a.

        // Si en la posicion en la que nos encontramos hay algún 0, no se tiene en cuenta
        // para la suma. Nos saltamos la iteración para ahorrar tiempo.
        if (i != b.primer0 && i != b.segundo0) {

            // En este for recorremos el entero820 a, el recorrido se realiza
            // de entero largo en entero largo.
            for (int j = 0; j < EL820SIZE; j++) {

                // Si en la posicion en la que nos encontramos hay algún 0, no se
                // tiene en cuenta para la suma. Nos saltamos la iteración para
                // ahorrar tiempo.
                if (j != a.primer0 && j != a.segundo0) {

                    // En este punto llegamos a la multiplicacion directa entre dos
                    // enteros largos, que en este caso se realiza mediante la multiplicación
                    // divide y venceras no rápida.
                    EnteroLargo mult = EnteroLargo::multNoRapida(b.enteros[i], a.enteros[j], casoBase);
                    // Tenemos en cuenta los correspondientes desplazamientos con respecto a.
                    mult.desplazarEntero(j*a.tamEL);
                    // Acumulamos el resultado en parcial.
                    parcial = EnteroLargo::suma(parcial, mult);
                }
            }
            // Tenemos en cuenta los correspondientes desplazamientos con respecto a b.
            parcial.desplazarEntero(i*b.tamEL);
            // Acumulamos la suma en el entero largo resultado.
            resultado = EnteroLargo::suma(resultado, parcial);
        }
    }

    return resultado;
}

// Método que realiza la multiplicación directa de dos enteros820 a y b, usando
// para ello la multiplicación divide y venceras Karatsuba y Ofman de los enteros largos.
// Devuelve un entero largo con el resultado de la multiplicación.
EnteroLargo Entero820::mult820Karat(Entero820 a, Entero820 b, int casoBase){
    EnteroLargo resultado;          // Variable en la que se acumulan los resultados
                                    // parciales hasta obtener el resultado.

    // Usamos este primer for para recorrer el entero820 b, el recorrido se realiza
    // de entero largo en entero largo.
    for (int i = 0; i < EL820SIZE; i++) {
        EnteroLargo parcial;        // Variable en la que se guarda el resultado de
                                    // la multiplicación de cada uno de los enteros
                                    // largos de b por el entero820 a.

        // Si en la posicion en la que nos encontramos hay algún 0, no se tiene en cuenta
        // para la suma. Nos saltamos la iteración para ahorrar tiempo.
        if (i != b.primer0 && i != b.segundo0) {

            // En este for recorremos el entero820 a, el recorrido se realiza
            // de entero largo en entero largo.
            for (int j = 0; j < EL820SIZE; j++) {

                // Si en la posicion en la que nos encontramos hay algún 0, no se
                // tiene en cuenta para la suma. Nos saltamos la iteración para
                // ahorrar tiempo.
                if (j != a.primer0 && j != a.segundo0) {

                    // En este punto llegamos a la multiplicacion directa entre dos
                    // enteros largos, que en este caso se realiza mediante la multiplicación
                    // divide y venceras Karatsuba y Ofman.
                    EnteroLargo mult = EnteroLargo::multKarat(b.enteros[i], a.enteros[j], casoBase);
                    // Tenemos en cuenta los correspondientes desplazamientos con respecto a.
                    mult.desplazarEntero(j*a.tamEL);
                    // Acumulamos el resultado en parcial.
                    parcial = EnteroLargo::suma(parcial, mult);
                }
            }
            // Tenemos en cuenta los correspondientes desplazamientos con respecto a b.
            parcial.desplazarEntero(i*b.tamEL);
            // Acumulamos la suma en el entero largo resultado.
            resultado = EnteroLargo::suma(resultado, parcial);
        }
    }

    return resultado;
}

// Método para convertir un entero820 a string. Utilizado para comparar los
// resultados en las validaciones
string Entero820::toTexto(){
    string resultado;
    resultado.reserve(EL820SIZE*tamEL);
    // Recorrido para concatenar todos los string de todos los enteros largos
    for (int i = 0; i < EL820SIZE; i++) {
        resultado.append(enteros[EL820SIZE-1-i].toTexto());
    }

    return resultado;
}
