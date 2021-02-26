#ifndef TP_3_PRECIPICIO_H
#define TP_3_PRECIPICIO_H

#include "casillero.h"

class Precipicio : public Casillero {

    // metodos
public:
    // PRE:
    // POS:
    int obtenerCosto(string elemento) override;

};


#endif //TP_3_PRECIPICIO_H
