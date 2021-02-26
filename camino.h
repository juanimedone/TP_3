#ifndef TP_3_CAMINO_H
#define TP_3_CAMINO_H

#include "casillero.h"

class Camino : public Casillero {

    // metodos
public:
    // PRE:
    // POS:
    int obtenerCosto(string elemento) override;

};


#endif //TP_3_CAMINO_H
