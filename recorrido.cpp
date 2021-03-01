#include "recorrido.h"


void Recorrido::asignarEnergiaGastada(int energiaGastada) {

    this->energiaGastada = energiaGastada;

}


int Recorrido::obtenerEnergiaGastada() {

    return energiaGastada;

}


void Recorrido::mostrar() {

    array<int,2> posicion{};
    int i = 0;

    cout << "\n\n Energia gastada: " << energiaGastada <<
            "\n\n Recorrido: \n" ;

    while (caminoTomado[i]) {

        posicion = {};

        cout << "-> [" << posicion[0] << "," << posicion[1] << "] " ;
    }

}
