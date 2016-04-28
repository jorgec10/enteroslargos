#include <iostream>
#include "EnteroLargo.h"
#include "Entero820.h"
using namespace std;

// Método que comprueba que la longitud de un entero largo es correcta, es decir
// que es potencia de 2 y mayor o igual que 8.
bool formatoCorrecto(int longitud) {
    while (longitud > 8) {
            if (longitud%2 == 0)
                longitud = longitud/2;
            else break;
    }

    if (longitud == 8) {
        return true;
    }
    return false;
}

int main(void) {

    EnteroLargo a, b;
    Entero820 a820, b820;
    string lectura;

    do {
        cin >> lectura;
        a = EnteroLargo(lectura, true);
        a820 = Entero820(I, J, lectura);
    } while (!formatoCorrecto(lectura.size()));

    do {
        cin >> lectura;
        b = EnteroLargo(lectura, true);
        b820 = Entero820(K, L, lectura);
    } while (!formatoCorrecto(lectura.size()));

    cout << "EnteroLargo A: \t";
    a.imprimir();
    cout << endl;

    cout << "EnteroLargo B: \t";
    b.imprimir();
    cout << endl;

    cout << "Entero820 A: \t";
    a820.imprimir();
    cout << endl;

    cout << "Entero820 B: \t";
    b820.imprimir();
    cout << endl;

    string resultados[6];
    string metodos[6] = {"MultClasica", "MultNoRapida", "MultKarat",
                          "mult820Clasica", "mult820NoRapida", "mult820Karat"};

    cout << endl << "Multiplicación enteros largos" << endl;
    resultados[0] = EnteroLargo::multClasica(a, b).toTexto();
    cout << metodos[0] << ": \t\t" << resultados[0] << endl;
    resultados[1] = EnteroLargo::multNoRapida(a, b, 1).toTexto();
    cout << metodos[1] << ": \t\t" << resultados[1] << endl;
    resultados[2] = EnteroLargo::multKarat(a, b, 1).toTexto();
    cout << metodos[2] << ": \t\t" << resultados[2] << endl;

    cout << endl << "Multiplicación enteros820" << endl;
    resultados[3] = Entero820::mult820Clasica(a820, b820).toTexto();
    cout << metodos[3] << ": \t" << resultados[3] << endl;
    resultados[4] = Entero820::mult820NoRapida(a820, b820, 1).toTexto();
    cout << metodos[4] << ": \t" << resultados[4] << endl;
    resultados[5] = Entero820::mult820Karat(a820, b820, 1).toTexto();
    cout << metodos[5] << ": \t\t" << resultados[5] << endl;

    cout << endl << "Validando..." << endl;
    bool todoOK = true;
    for (int i = 0; i<resultados[0].size(); i++) {
      for (int j = 1; j<6; j++) {
        if (resultados[0][i] != resultados[j][i]) {
          cout << "Método " << metodos[j] << " se diferencia en posicion " << i;
          cout << " (" << resultados[j][i] << ") del método " << metodos[0];
          cout << " (" << resultados[0][i] << ")" << endl;
          todoOK = false;
        }
      }
    }

    if (todoOK) cout << "Los resultados no tienen diferencias entre ellos" << endl;


}
