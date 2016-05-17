#include <iostream>
#include <bitset>
#include <set>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

#define MAX_SEG 20

bool isSolucion(int nivel, size_t n, bitset<MAX_SEG> *param, bitset<MAX_SEG> solucion, int p){
    
    if(nivel!=p-1) return false;
    std::set<int> valores;
    for (size_t i = 0; i < n; i++) {
        valores.insert((param[i] & solucion).to_ulong());
    }
    return valores.size()==n;
}


int main(int argc, char* argv[]){
    int start, stop;
    
    start = atoi(argv[1]);
    stop = atoi(argv[2]);
    //numcasosint = atoi(argv[3]);

    for (int i = start; i <= stop; i*=2) {
        
        // Lectura de datos
        int optimo, p, n;
        n = i; // Num segmentos y num digitos
        optimo = ceil((float) log2(i));
        
        cout << n << ", ";
        
        for (int k = 0; k<optimo; k++) {
            cout << "-, ";
        }
        
        for (int k = 0; optimo+k < MAX_SEG; k++) {
        
            p = optimo + k;
            
            std::bitset<MAX_SEG> segmentos[n];
            
            for (int j = 0; j < n; j++) {
                segmentos[j] = bitset<MAX_SEG>(j);
            }
            
            // Backtracking
            bitset<MAX_SEG> solucion;
            int nivel = 0;
            int nsMin = p;           // num segmentos minimo
            int segOn = 0;
            int estado = -1;
            int minTeorico = log2(p);
            
            struct timeval inicio, fin;
            double tiempo;
            
            gettimeofday(&inicio, NULL);
            
            // Algoritmo
            do{
                // Generar
                estado++;
                segOn+=solucion[nivel];
                
                // Solucion
                if (isSolucion(nivel,n,segmentos,solucion,p) && segOn<nsMin) {
                    nsMin = segOn;
                } 
                
                // Criterio
                if(nivel<p-1 && (segOn+p-1-nivel) >= minTeorico){
                    nivel++;
                    estado = -1;
                } else {
                    while (!solucion[nivel]<1 && nivel>-1) {
                        segOn--;
                        solucion[nivel] = 0;
                        nivel--;
                    }
                    solucion[nivel]=1;
                }
                
            } while (nivel!=-1);
            
            gettimeofday(&fin, NULL);
            tiempo=(fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    
            cout << tiempo << ", ";
        }
        cout << endl;
    }
}