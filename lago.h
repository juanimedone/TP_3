#ifndef TP_3_LAGO_H
#define TP_3_LAGO_H

#include "casillero.h"

class Lago : public Casillero {

    // metodos
public:
    // PRE:
    // POS:
    int obtenerCosto(string elemento) override;

    // PRE:
    // POS:
    char obtenerCodigo() override;

};


#endif //TP_3_LAGO_H
