#ifndef TP_3_NODOLISTA_H
#define TP_3_NODOLISTA_H

#include "utiles.h"

class NodoLista {

    // atributos
private:
    array<int,2> posicion;
    NodoLista* siguiente;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un nodo con posicion y el siguiente apuntando a nullptr
    NodoLista(array<int,2> posicion);

    // PRE: -
    // POS: devuelve la posicion que contiene el nodo
    array<int,2> obtenerPosicion();

    // PRE: -
    // POS: devuelve el puntero al siguiente nodo, devuelve nullptr si es el ultimo
    NodoLista* obtenerSiguiente();

    // PRE: -
    // POS: cambia el puntero al siguiente
    void cambiarSiguiente(NodoLista* siguiente);

};


#endif //TP_3_NODOLISTA_H
