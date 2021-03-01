#ifndef TP_3_VOLCAN_H
#define TP_3_VOLCAN_H

#include "casillero.h"

class Volcan : public Casillero {

    // metodos
public:
    // PRE: -
    // POS: devuelve el costo de pasar por el casillero segun el elemento del personaje
    int obtenerCosto(string elemento) override;

    // PRE: -
    // POS: devuelve el caracter que representa el tipo de casillero
    char obtenerCodigo() override;

};


#endif //TP_3_VOLCAN_H
