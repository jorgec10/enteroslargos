#include <iostream>
#include <bitset>
#include <set>

using namespace std;

#define MAX_SEG 15

bool comprueba(bitset<MAX_SEG> *param, size_t n){
    std::set<int> valores;
    for (size_t i = 0; i < n; i++) {
        valores.insert(param[i].to_ulong());
    }
    return valores.size()==n;
}

bool isSolucion(int nivel, int n, bitset<MAX_SEG> *param, int *solucion, int p){
    
    if(nivel!=p-1) return false;
    std::bitset<MAX_SEG> b[n];
    for (int i = 0; i < n; i++) {
        b[i] = bitset<MAX_SEG>(param[i].to_ulong());
    }
    for (int j = 0; j < p; j++) {
        if(solucion[j]==0){
            for (int k = 0; k < n; k++) {
                b[k].reset(j);
            }
        }
    }
    
    return comprueba(b, n);
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
        int solucion[p];
        int nivel = 0;
        int nsMin = p;           // num segmentos minimo
        int segOn = 0;
        
        for (int i = 0; i < p; i++) {
            solucion[i] = -1;
        }
        
        // Algoritmo
        do{
            // Generar
            solucion[nivel]++;
            segOn+=solucion[nivel];
            
            // Solucion
            if (isSolucion(nivel,n,segmentos,solucion,p) && segOn<nsMin) {
                nsMin = segOn;
            } 
            
            if (nivel<p-1) {
                nivel++;
            } else {
                while (!solucion[nivel]<1 && nivel>-1) {
                    segOn--;
                    solucion[nivel] = -1;
                    nivel--;
                }
            }
            
        } while (nivel!=-1);
        
        cout << nsMin << endl;
    }
}