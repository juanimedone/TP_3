#include "lista.h"


void Lista::alta(array<int,2> posicion) {

    NodoLista* nuevoNodo = new NodoLista(posicion);

    if ( estaVacia() ) {

        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }
    else {
        ultimo->cambiarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }

}


bool Lista::estaVacia() {

    return (primero == nullptr);

}


void Lista::imprimir() {

    NodoLista* actual;

    actual = primero;

    while (actual) {

        cout << "-> [" << actual->obtenerPosicion()[0] << "," << actual->obtenerPosicion()[1] << "] " ;
        actual = actual->obtenerSiguiente();
    }

}


Lista::~Lista() {

    while ( !estaVacia() )
        baja();

}


void Lista::baja() {

    NodoLista* borrar;

    borrar = primero;

    primero = primero->obtenerSiguiente();

    delete borrar;

}
