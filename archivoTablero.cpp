#include "archivoTablero.h"


ArchivoTablero::ArchivoTablero() {

    archivo.open(PATH_ARCHIVO_TABLERO);

}


bool ArchivoTablero::estaAbierto() {

    return archivo.is_open();

}


ArchivoTablero::~ArchivoTablero() {

    archivo.close();

}


void ArchivoTablero::cargarTablero(Grafo tablero) {

    Casillero* nuevoCasillero;
    string tipo;
    array<int,2> posicion{};

    for (short int i = 0; i < MAX_FILA; i++)

        for (short int j = 0; j < MAX_COLUMNA; j++) {

            getline(archivo, tipo, ',');
            posicion[0] = i;
            posicion[1] = j;

            nuevoCasillero = crearCasillero(tipo[0]);
            tablero.asignarVertice(nuevoCasillero, posicion);
        }

    nuevoCasillero = nullptr;
    delete nuevoCasillero;
    
}


Casillero* ArchivoTablero::crearCasillero(char tipo) {

    Casillero* nuevoCasillero;

    switch (tipo) {

        case MONTANIA:
            nuevoCasillero = new Montania();
            break;

        case PRECIPICIO:
            nuevoCasillero = new Precipicio();
            break;

        case LAGO:
            nuevoCasillero = new Lago();
            break;

        case VOLCAN:
            nuevoCasillero = new Volcan();
            break;

        case CAMINO:
            nuevoCasillero = new Camino();
            break;

        case VACIO:
            nuevoCasillero = new Vacio();

    }

    return nuevoCasillero;
    
}
