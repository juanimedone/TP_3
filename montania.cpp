#include "montania.h"


int Montania::obtenerCosto(string elemento) {

    int costo;

    if (elemento == COD_TIERRA)
        costo = COSTO_NULO;

    else if (elemento == COD_AIRE)
        costo = COSTO_ALTO;

    else
        costo = COSTO_MEDIO;

    return costo;

}
