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
    // constructor
    // PRE:
    // POS: asigna valores iniciales nulos a los atributos
    Recorrido();

    // PRE: -
    // POS: asigna el valor de energiaGastada para hacer el recorrido
    void asignarEnergiaGastada(int energiaGastada);

    // PRE: -
    // POS: devuelve la energia gastada en hacer el recorrido
    int obtenerEnergiaGastada();

    // PRE: -
    // POS: va agregando las posiciones recorridas en sentido inverso (desde el destino hasta el origen) al vector
    void agregarPosicion(int indice);

    // PRE: -
    // POS: imprime por pantalla la energia gastada y el camino tomado (las posiciones)
    void mostrar();

};


#endif //TP_3_RECORRIDO_H
