#include "grafo.h"


void Grafo::inicializarMatrices() {

    inicializarMatriz(this->agua, COD_AGUA);
    inicializarMatriz(this->aire, COD_AIRE);
    inicializarMatriz(this->tierra, COD_TIERRA);
    inicializarMatriz(this->fuego, COD_FUEGO);

}


void Grafo::asignarVertice(Casillero* vertice, array<int, 2> posicion) {

    short int fila, columna;

    fila = posicion[0];
    columna = posicion[1];

    vertices[fila][columna] = vertice;

}


Personaje* Grafo::obtenerPersonaje(array<int, 2> posicion) {

    int fila, columna;

    fila = posicion[0];
    columna = posicion[1];

    return vertices[fila][columna]->obtenerPersonaje();

}


bool Grafo::estaVacio(array<int,2> posicion) {

    int fila, columna;

    fila = posicion[0];
    columna = posicion[1];

    return vertices[fila][columna]->estaVacio();

}


void Grafo::moverPersonaje(Personaje* personaje, array<int,2> posInicial, array<int,2> posFinal) {

    int filaFinal, columnaFinal;

    filaFinal = posFinal[0];
    columnaFinal = posFinal[1];

    if (posInicial != COORD_INVALIDA) {

        int filaInicial, columnaInicial;

        filaInicial = posInicial[0];
        columnaInicial = posInicial[1];

        vertices[filaInicial][columnaInicial]->asignarPersonaje(nullptr);

    }

    vertices[filaFinal][columnaFinal]->asignarPersonaje(personaje);

}


void Grafo::mostrar() {



}


Recorrido Grafo::dijkstra(array<int, 2> origen, string elemento) {

    Recorrido recorridoMin;
    bool visitados[MAX_FILA][MAX_COLUMNA];

    for (short int i = 0; i < MAX_FILA; i++)

        for (short int j = 0; j < MAX_COLUMNA; j++)

            visitados[i][j] = false;

    recorridoMin.asignarEnergiaMinima(COSTO_NULO);

    // if (elemento == COD_AGUA)

    for (short int i = 0; i < MAX_FILA; i++)      // elementos - 1

        for (short int j = 0; j < MAX_COLUMNA; j++) {

            int posMin = distanciaMinima(recorridoMin.obtenerEnergiaMinima(), visitados);
            visitados[posMin] = true;

            for (unsigned j = 0; j < elementos; j++){
                int minDist = recorridoMin.precioMinimo[posMin] + precios->obtenerValor(posMin, j);
                if (!visitados[j] && recorridoMin.precioMinimo[posMin] != E_INFINITO && minDist < recorridoMin.precioMinimo[j]) {
                    recorridoMin.precioMinimo[j] = minDist;
                    recorridoMin.rutaMinima[j] = vertices->obtenerDato(posMin);
                }
            }
        }


    return recorridoMin;

}


void Grafo::inicializarMatriz(int matrizPesos[MAX_FILA][MAX_COLUMNA], const string& elemento) {

    for (int i = 0; i < MAX_FILA - 1; i++)

        for (int j = 0; j < MAX_COLUMNA - 1; j++) {

            int pesoActual = vertices[i * MAX_FILA + j]->obtenerCosto(elemento);
            int pesoSiguiente = vertices[i * MAX_FILA + j+1]->obtenerCosto(elemento);

            matrizPesos[i * MAX_FILA + j][j+1] = pesoSiguiente;
            matrizPesos[i * MAX_FILA + j+1][j] = pesoActual;

        }

    for (int i = 0; i < MAX_COLUMNA - 1; i++)

        for (int j = 0; j < MAX_FILA - 1; j++) {

            int pesoActual = vertices[i + j*8]->obtenerCosto(elemento);
            int pesoSiguiente = vertices[i + (j+1)*8]->obtenerCosto(elemento);

            matrizPesos[i*MAX_FILA+j+8][j] = pesoSiguiente;
            matrizPesos[i*MAX_FILA+j][j+8] = pesoActual;

        }

}
