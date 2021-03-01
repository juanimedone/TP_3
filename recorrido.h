#ifndef TP_3_RECORRIDO_H
#define TP_3_RECORRIDO_H

#include "utiles.h"

class Recorrido {

    // atributos
private:
    int energiaGastada;
    vector<int> caminoTomado;

    // metodos
public:
    // PRE: -
    // POS: asigna el valor de energiaGastada para hacer el recorrido
    void asignarEnergiaGastada(int energiaGastada);

    // PRE: -
    // POS: devuelve la energia gastada en hacer el recorrido
    int obtenerEnergiaGastada();

    // PRE: -
    // POS: imprime por pantalla la energia gastada y el camino tomado (las posiciones)
    void mostrar();

};


#endif //TP_3_RECORRIDO_H
