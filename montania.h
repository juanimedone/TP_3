#ifndef TP_3_MONTANIA_H
#define TP_3_MONTANIA_H

#include "casillero.h"

class Montania : public Casillero {

    // metodos
public:
    // PRE:
    // POS:
    int obtenerCosto(string elemento) override;

    // PRE:
    // POS:
    char obtenerCodigo() override;

};


#endif //TP_3_MONTANIA_H
