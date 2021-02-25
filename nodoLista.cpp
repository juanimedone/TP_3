#include "nodoLista.h"


NodoLista::NodoLista(array<int,2> posicion) {

    this->posicion = posicion;
    siguiente = nullptr;

}


array<int,2> NodoLista::obtenerPosicion() {

    return posicion;

}


NodoLista *NodoLista::obtenerSiguiente() {

    return siguiente;

}


void NodoLista::cambiarSiguiente(NodoLista* siguiente) {

    this->siguiente = siguiente;

}
