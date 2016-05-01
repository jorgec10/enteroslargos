#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tupla {
    int beneficio;
    int tiempo;
};

typedef struct tupla tupla;

bool comparaTupla(tupla a, tupla b) {
    if (a.beneficio < b.beneficio) return false;
    else return true;
}

tupla* datos;
int *solucion;
int mejor;
int ut, aviones;
int cogidos;

int main (void) {
    
    // Lectura de datos
    int ncasos;
    cin >> ncasos;
    for (int i = 0; i<ncasos; i++) {
        
        cin >> ut >> aviones;
        
        datos = new tupla[aviones];
        solucion = new int[ut];
        cogidos = 0;
        mejor = 0;
        
        for (int j=0; j<ut; j++) {
            solucion[j] = -1;
        }
        
        for (int j=0; j<aviones; j++) {
            cin >> datos[j].tiempo;
            if (datos[j].tiempo > ut) datos[j].tiempo = ut;
        }
        
        for (int j=0; j<aviones; j++) {
            cin >> datos[j].beneficio;
        }
        
        sort(datos, datos+aviones, comparaTupla);
        
        for (int k = 0; k<aviones; k++){
                int argo = solucion[datos[k].tiempo-1];
                
                if (argo == -1) {
                    solucion[datos[k].tiempo-1] = k;
                    mejor+=datos[k].beneficio;
                    cogidos++;
                }
                else {
                    for (int j = datos[k].tiempo-2; j >= 0; j--) {
                        argo = solucion[j];
                        if (argo == -1) {
                            solucion[j] = k;
                            mejor+=datos[k].beneficio;
                            cogidos++;
                            break;
                        }
                    }
                }
        }
        cout << mejor << endl;
    }
    
}