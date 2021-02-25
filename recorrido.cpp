#include "recorrido.h"


void Recorrido::asignarEnergiaGastada(int energiaGastada) {

    this->energiaGastada = energiaGastada;

}


int Recorrido::obtenerEnergiaGastada() {

    return energiaGastada;

}


void Recorrido::mostrar() {

    cout << "\n\n Energia gastada: " << energiaGastada <<
            "\n\n Recorrido: \n" ;

    posiciones.imprimir();

}
