#ifndef TP_3_RECORRIDO_H
#define TP_3_RECORRIDO_H

#include "lista.h"

class Recorrido {

    // atributos
private:
    int energiaMinima;
    Lista posiciones;

    // metodos
public:
    // PRE:
    // POS:
    void asignarEnergiaMinima(int energiaMinima);

    // PRE:
    // POS:
    void agregarPosicion(array<int,2> posicion);

    // PRE:
    // POS:
    int obtenerEnergiaMinima();

    // PRE:
    // POS:
    void mostrar();

};


#endif //TP_3_RECORRIDO_H
