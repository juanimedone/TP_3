#include "recorrido.h"


void Recorrido::asignarEnergiaGastada(int energiaGastada) {

    this->energiaGastada = energiaGastada;

}


int Recorrido::obtenerEnergiaGastada() {

    return energiaGastada;

}


void Recorrido::agregarPosicion(int indice) {

    caminoTomado.push_back(indice);

}


void Recorrido::mostrar() {

    int i = 0;

    reverse(caminoTomado.begin(), caminoTomado.end());

    cout << "\n\n Energia gastada: " << energiaGastada <<
            "\n\n Recorrido: \n" ;

    while (caminoTomado[i]) {

        int fila, columna;

        fila = caminoTomado[i] / MAX_FILA;
        columna = caminoTomado[i] % MAX_COLUMNA;

        cout << "-> [" << fila << "," << columna << "] " ;
    }

}
