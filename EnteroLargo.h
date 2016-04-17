#ifndef _ENTERO_LARGO_
#define _ENTERO_LARGO_
#include <list>
#include <string>

using namespace std;

class EnteroLargo {
    private:
        list<char> digitos;
        int longitud;
        bool signo;  // True -> positivo, False -> negativo

        static EnteroLargo multSencilla(EnteroLargo a, int b);
        void setSigno(bool sign);

    public:
        EnteroLargo();
        EnteroLargo(string entero, bool sig);
        EnteroLargo(list<char> entero, bool sig);

        int getLongitud();

        void imprimir();
        void desplazarEntero(int desp);

        EnteroLargo dividirEntero(bool mitad);
        EnteroLargo * dividirEntero();

        static EnteroLargo suma(EnteroLargo a,EnteroLargo b);
        static EnteroLargo resta(EnteroLargo a, EnteroLargo b);

        static int compara(EnteroLargo a, EnteroLargo b);

        static EnteroLargo multClasica(EnteroLargo a, EnteroLargo b);
        static EnteroLargo multNoRapida(EnteroLargo a, EnteroLargo b, int casoBase);
        static EnteroLargo multKarat(EnteroLargo a, EnteroLargo b, int casoBase);


};

#endif
