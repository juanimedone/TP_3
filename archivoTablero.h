#ifndef TP_3_ARCHIVOTABLERO_H
#define TP_3_ARCHIVOTABLERO_H

#include "grafo.h"
#include "montania.h"
#include "precipicio.h"
#include "lago.h"
#include "volcan.h"
#include "camino.h"
#include "vacio.h"

class ArchivoTablero {

    // atributos
private:
    ifstream archivo;

    // metodos
public:
    // constructor
    // PRE:
    // POS:
    ArchivoTablero();

    // PRE: -
    // POS: devuelve true si se abrio correctamente, false de lo contrario
    bool estaAbierto();

    // PRE:
    // POS:
    void cargarTablero(Grafo tablero);

    // destructor
    // PRE: -
    // POS: cierra el archivo
    ~ArchivoTablero();

private:
    // PRE:
    // POS:
    Casillero* crearCasillero(char tipo);

};


#endif //TP_3_ARCHIVOTABLERO_H
