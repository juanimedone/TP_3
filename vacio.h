#ifndef TP_3_VACIO_H
#define TP_3_VACIO_H

#include "casillero.h"

class Vacio : public Casillero {

    // metodos
public:
    // PRE:
    // POS:
    int obtenerCosto(string elemento) override;

    // PRE:
    // POS:
    char obtenerCodigo() override;

};


#endif //TP_3_VACIO_H
