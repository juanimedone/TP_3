#include "grafo.h"


void Grafo::asignarVertice(Casillero* vertice, array<int, 2> posicion) {

    short int fila, columna;

    fila = posicion[0];
    columna = posicion[1];

    vertices[fila][columna] = vertice;

}


Personaje* Grafo::obtenerPersonaje(array<int, 2> posicion) {

    return ;

}


bool Grafo::estaVacio(array<int,2> posicion) {

    return ;

}


void Grafo::posicionarPersonaje(Personaje* personaje, array<int,2> posicion) {



}


Recorrido Grafo::dijkstra(array<int, 2> origen, array<int, 2> destino, string elemento) {

    return ;

}
