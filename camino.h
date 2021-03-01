#ifndef TP_3_CAMINO_H
#define TP_3_CAMINO_H

#include "casillero.h"

class Camino : public Casillero {

    // metodos
public:
    // PRE: -
    // POS: devuelve el costo de pasar por el casillero
    int obtenerCosto(string elemento) override;

    // PRE: -
    // POS: devuelve el caracter que representa el tipo de casillero
    char obtenerCodigo() override;

};


#endif //TP_3_CAMINO_H
