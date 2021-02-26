#include "recorrido.h"


void Recorrido::asignarEnergiaMinima(int energiaMinima) {

    this->energiaMinima = energiaMinima;

}


void Recorrido::agregarPosicion(array<int,2> posicion) {

    posiciones.alta(posicion);

}


int Recorrido::obtenerEnergiaMinima() {

    return energiaMinima;

}


void Recorrido::mostrar() {

    cout << "\n\n Energia gastada: " << energiaMinima <<
            "\n\n Recorrido: \n" ;

    posiciones.imprimir();

}
