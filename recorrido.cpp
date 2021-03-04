#include "recorrido.h"


Recorrido::Recorrido() {

    energiaGastada = ENERGIA_MINIMA;
    caminoTomado.shrink_to_fit();

}


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

    reverse( caminoTomado.begin(), caminoTomado.end() );

    cout << "\n\n Recorrido: \n\n" ;

    for (int i = 0; i < caminoTomado.size(); i++) {

        int fila, columna;

        fila = caminoTomado[i] / MAX_FILA;
        columna = caminoTomado[i] % MAX_COLUMNA;

        cout << "-> [" << fila << "," << columna << "] " ;

    }

    cout << "\n\n Energia gastada: " << energiaGastada << endl;
}



