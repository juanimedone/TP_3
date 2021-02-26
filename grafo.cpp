#include "grafo.h"


void Grafo::inicializarMatrices() {

    for (int i = 0; i < CANT_VERTICES; i++) {

        for (int j = 0; j < CANT_VERTICES; j++) {


        }
    }

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


void Grafo::posicionarPersonaje(Personaje* personaje, array<int,2> posicion) {

    int fila, columna;

    fila = posicion[0];
    columna = posicion[1];

    vertices[fila][columna]->asignarPersonaje(personaje);

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
