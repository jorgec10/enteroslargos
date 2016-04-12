#include <iostream>
#include "EnteroLargo.h"
#include "Entero820.h"
using namespace std;


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
    
    list<char> digitosEL;
    list<char> digitosEL820;
    
    for (int i = 0; i < 2; i++) {
        
        string lectura;
        int longitud = 0;
        
        cin >> lectura;
        
        for (int i = 0; i < lectura.size(); i++) {
            
            digitosEL.push_front(lectura[i]);
            digitosEL820.push_front(lectura[i]);
            
            longitud++;
            
            if (longitud ) 
        }
        //cout << formatoCorrecto(longitud) << endl;
        //digitosEL.clear();
    }
    
    
    
}
