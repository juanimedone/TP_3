#include "volcan.h"


int Volcan::obtenerCosto(string elemento) {

    int costo;

    if (elemento == COD_FUEGO)
        costo = COSTO_NULO;

    else if (elemento == COD_AGUA)
        costo = COSTO_ALTO;

    else
        costo = COSTO_MEDIO;

    return costo;

}
