#ifndef NODODICCIONARIOABB_H
#define NODODICCIONARIOABB_H

#include <iostream>

using namespace std;

template <typename Clave, typename Valor>
class NodoDiccionarioABB {

    // atributos
private:
    Clave clave;
    Valor valor;
    NodoDiccionarioABB<Clave, Valor>* izquierda;      // hijo izquierdo
    NodoDiccionarioABB<Clave, Valor>* derecha;        // hijo derecho
    NodoDiccionarioABB<Clave, Valor>* padre;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un nodo con la clave y el valor dados y sus punteros apuntando a nullptr
    NodoDiccionarioABB(Clave clave, Valor valor);

    // PRE: -
    // POS: cambia la clave del nodo
    void asignarClave(Clave clave);

    // PRE: -
    // POS: asigna el hijo izquierdo
    void asignarIzquierda(NodoDiccionarioABB<Clave, Valor>* izquierda);

    // PRE: -
    // POS: asigna el hijo derecho
    void asignarDerecha(NodoDiccionarioABB<Clave, Valor>* derecha);

    // PRE: -
    // POS: asigna el padre del nodo
    void asignarPadre(NodoDiccionarioABB<Clave, Valor>* padre);

    // PRE: -
    // POS: devuelve la clave
    Clave obtenerClave();

    // PRE: -
    // POS: devuelve el valor
    Valor obtenerValor();

    // PRE: -
    // POS: devuelve el puntero al hijo izquierdo
    NodoDiccionarioABB<Clave, Valor>* obtenerIzquierda();

    // PRE: -
    // POS: devuelve el puntero al hijo derecho
    NodoDiccionarioABB<Clave, Valor>* obtenerDerecha();

    // PRE: -
    // POS: devuelve el puntero al padre
    NodoDiccionarioABB<Clave, Valor>* obtenerPadre();

    // PRE: -
    // POS: devuelve true si el nodo es hoja (si no tiene hijos)
    bool esHoja();

    // PRE: -
    // POS: devuelve true si el nodo solo tiene hijo izquierdo
    bool soloHijoIzquierdo();

    // PRE: -
    // POS: devuelve true si el nodo solo tiene hijo derecho
    bool soloHijoDerecho();

    // PRE: -
    // POS: libera la memoria pedida en el heap
    ~NodoDiccionarioABB();

};



template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>::NodoDiccionarioABB(Clave clave, Valor valor) {

    this->clave = clave;
    this->valor = valor;
    izquierda = nullptr;
    derecha = nullptr;
    padre = nullptr;

}


template <typename Clave, typename Valor>
void NodoDiccionarioABB<Clave, Valor>::asignarClave(Clave clave) {

    this->clave = clave;

}


template <typename Clave, typename Valor>
void NodoDiccionarioABB<Clave, Valor>::asignarIzquierda(NodoDiccionarioABB<Clave, Valor>* izquierda) {

    this->izquierda = izquierda;

}


template <typename Clave, typename Valor>
void NodoDiccionarioABB<Clave, Valor>::asignarDerecha(NodoDiccionarioABB<Clave, Valor>* derecha) {

    this->derecha = derecha;

}


template <typename Clave, typename Valor>
void NodoDiccionarioABB<Clave, Valor>::asignarPadre(NodoDiccionarioABB<Clave, Valor>* padre) {

    this->padre = padre;

}


template <typename Clave, typename Valor>
Clave NodoDiccionarioABB<Clave, Valor>::obtenerClave() {

    return clave;

}


template <typename Clave, typename Valor>
Valor NodoDiccionarioABB<Clave, Valor>::obtenerValor() {

    return valor;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* NodoDiccionarioABB<Clave, Valor>::obtenerIzquierda() {

    return izquierda;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* NodoDiccionarioABB<Clave, Valor>::obtenerDerecha() {

    return derecha;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* NodoDiccionarioABB<Clave, Valor>::obtenerPadre() {

    return padre;

}


template <typename Clave, typename Valor>
bool NodoDiccionarioABB<Clave, Valor>::esHoja() {

    return (izquierda == nullptr && derecha == nullptr);

}


template <typename Clave, typename Valor>
bool NodoDiccionarioABB<Clave, Valor>::soloHijoIzquierdo() {

    return (izquierda != nullptr && derecha == nullptr);

}


template <typename Clave, typename Valor>
bool NodoDiccionarioABB<Clave, Valor>::soloHijoDerecho() {

    return (izquierda == nullptr && derecha != nullptr);

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>::~NodoDiccionarioABB() {

    delete valor;

}


#endif // NODODICCIONARIOABB_H
