#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys/time.h>
#include <cstdlib>

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
int utInit, utFin, avionesInit, avionesFin;
int cogidos;

int main (int argc, char* argv[]) {
    
    srand(time(NULL));

    utInit = atoi(argv[1]);
    utFin = atoi(argv[2]);
    avionesInit = atoi(argv[3]);
    avionesFin = atoi(argv[4]);
    
    for (int i = utInit; i<=utFin; i+=10) {
        
        int ut = i;
        
        for (int a = avionesInit; a <= avionesFin; a+=10) {
            
            
            int aviones = a;
            /*cout << "ut: " <<  ut;
            cout << " av: " <<  aviones;
            cout << endl;*/
            
            datos = new tupla[aviones];
            solucion = new int[ut];
            cogidos = 0;
            mejor = 0;
            
            for (int j=0; j<ut; j++) {
                solucion[j] = -1;
            }
            
            // Datos de tiempo
            for (int j=0; j<aviones; j++) {
                //cin >> datos[j].tiempo;
                datos[j].tiempo = rand()%10000;
                if (datos[j].tiempo > ut) datos[j].tiempo = ut;
            }
            
            // Datos de beneficio
            for (int j=0; j<aviones; j++) {
                //cin >> datos[j].beneficio;
                datos[j].beneficio = rand()%10000;
            }
            
            sort(datos, datos+aviones, comparaTupla);
            struct timeval inicio, fin;
            double tiempo;
            
            
            gettimeofday(&inicio, NULL);
            
            
            int k=0;
            while (k<aviones && cogidos < ut){
                    int control = solucion[datos[k].tiempo-1];
                    
                    if (control == -1) {
                        solucion[datos[k].tiempo-1] = k;
                        mejor+=datos[k].beneficio;
                        cogidos++;
                    }
                    else {
                        // Creo que esto puede simplificarlo.
                        // Por lo menos no aparece el break
                        int j = datos[k].tiempo-2;
                        control = solucion[j];
                        while (j>=0 && control!=-1) {
                            j--;
                            control = solucion[j];
                        }
                        if (control==-1) {
                            solucion[j] = k;
                            mejor+=datos[k].beneficio;
                            cogidos++;
                        }
                    }
                    k++;
            }
            //cout << mejor << endl;
            gettimeofday(&fin, NULL);
            tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1.0;
            cout << i << ", " << a << ", " << tiempo << endl;
            
        }
    }
}