#include <iostream>
#include <bitset>
#include <set>
#include <math.h>

using namespace std;

#define MAX_SEG 15

bool isSolucion(int nivel, size_t n, bitset<MAX_SEG> *param, bitset<MAX_SEG> solucion, int p){
    
    if(nivel!=p-1) return false;
    
    std::set<int> valores;

    for (size_t i = 0; i < n; i++) {
        valores.insert((param[i] & solucion).to_ulong());
    }
    
    return valores.size()==n;
    
}


int main(void){
    int numcasos;
    cin >> numcasos;
    
    for (int i = 0; i < numcasos; i++) {
        
        // Lectura de datos
        int p, n;
        cin >> p >> n; // Num segmentos y num digitos
        
        std::bitset<MAX_SEG> segmentos[n];
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                bool lectura;
                cin >> lectura;
                segmentos[j].set(k,lectura);
            }
        }
        
        // Backtracking
        bitset<MAX_SEG> solucion;
        int nivel = 0;
        int nsMin = p;           // num segmentos minimo
        int segOn = 0;
        int estado = -1;
        
        int nivelesMin = log2(p);
        
        // Algoritmo
        do{
            // Generar
            estado++;
            
            segOn+=solucion[nivel];
            
            // Solucion
            if (isSolucion(nivel,n,segmentos,solucion,p) && segOn<nsMin) {
                nsMin = segOn;
            } 
            
            if(nivel<p-1 && (segOn+p-1-nivel) >= nivelesMin){
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
        
        cout << nsMin << endl;
    }
}