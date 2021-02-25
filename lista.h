#ifndef TP_3_LISTA_H
#define TP_3_LISTA_H

#include "nodoLista.h"

class Lista {

    // atributos
private:
    NodoLista* primero = nullptr;
    NodoLista* ultimo = nullptr;

    // metodos
public:
    // PRE: no puede haber 2 posiciones iguales en la lista
    // POS: inserta la posicion en orden actualizando los punteros correspondientes
    void alta(array<int,2> posicion);

    // PRE: -
    // POS: devuelve true si la lista esta vacia, false de lo contrario
    bool estaVacia();

    // PRE:
    // POS:
    void imprimir();

    // destructor
    // PRE: -
    // POS: libera la memoria dando de baja todos los nodos de la lista
    ~Lista();

private:
    // PRE:
    // POS:
    void baja();

};


#endif //TP_3_LISTA_H
