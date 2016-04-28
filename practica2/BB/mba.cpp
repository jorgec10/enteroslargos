#include <iostream>
#include <bitset>
#include <set>

using namespace std;


bool comprueba(bitset<12> *param, int n){
    std::set<int> valores;
    for (int i = 0; i < n; i++) {
        valores.insert(param[i].to_ulong());
    }
    return valores.size()==n;
}

bool solucion(int nivel, int n, bitset<12> *param, int *solucion){
    if(nivel!=n) return false;
    std::bitset<12> b[n];
    for (int i = 0; i < n; i++) {
        b[i] = new bitset<12>(param[i].to_string());
    }
    for (int j = 0; j < solucion.size(); j++) {
        if(solucion[j]==0){
            for (int k = 0; k < n; k++) {
                b[k].set(j,false);
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
        
        std::bitset<12> segmentos[n];
        
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
        
        for (int i = 0; i < solucion.size(); i++) {
            solucion[i] = -1;
        }
        
        // Algoritmo
        do{
            // Generar
            solucion[nivel]++;
            segOn+=solucion[nivel];
            
            // Solucion
            if ((nivel==n-1) && ())
            
            
            
            
        } while (nivel==-1);
        
        
    }
}