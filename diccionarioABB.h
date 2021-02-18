#ifndef DICCIONARIOABB_H
#define DICCIONARIOABB_H

#include <iostream>
#include "nodoDiccionarioABB.h"

using namespace std;

template <typename Clave, typename Valor>
class DiccionarioABB {

    // atributos
private:
    NodoDiccionarioABB<Clave, Valor>* raiz = nullptr;     // constructor por defecto (crea un diccionario vacio)

    // metodos
public:
    // PRE: no puede haber 2 elementos con la misma clave en el diccionario
    // POS: agrega un nuevo elemento al diccionario
    void insertar(Clave clave, Valor valor);

    // PRE: debe existir un elemento con la clave pasada por parametro
    // POS: elimina el elemento asociado a esa clave del diccionario
    void eliminar(Clave clave);

    // PRE: -
    // POS: devuelve true si la clave buscada se encuentra en el diccionario, false de lo contrario
    bool contiene(Clave clave);

    // PRE: la clave y su valor correspondiente deben existir en el diccionario
    // POS: devuelve el valor asociado a la clave
    Valor obtenerValor(Clave clave);

    // PRE: -
    // POS: muestra por pantalla todas las claves de menor a mayor
    void imprimirEnOrden();

    // PRE: -
    // POS: devuelve true si el diccionario esta vacio, false de lo contrario
    bool estaVacio();

    // destructor
    // PRE: -
    // POS: elimina todos los nodos del diccionario
    ~DiccionarioABB();

private:
    // PRE: -
    // POS: recorre el diccionario hasta insertar el nuevo nodo donde corresponde modificando los punteros. Si el diccionario estaba vacio el nuevo nodo sera la raiz
    NodoDiccionarioABB<Clave, Valor>* insertar(NodoDiccionarioABB<Clave, Valor>* nodo, Clave clave, Valor valor);

    // PRE: el nodo debe existir (nodo != nullptr)
    // POS: recorre el diccionario hasta encontrar el nodo, lo elimina y devuelve el nodo que lo reemplaza
    NodoDiccionarioABB<Clave, Valor>* eliminar(NodoDiccionarioABB<Clave, Valor>* nodo, Clave clave);

    // PRE: el nodo debe ser hoja
    // POS: elimina la memoria correspondiente del nodo y devuelve nullptr
    NodoDiccionarioABB<Clave, Valor>* eliminarCasoHoja(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: el nodo debe tener solo un hijo
    // POS: elimina la memoria correspondiente del nodo y devuelve el nodo hijo
    NodoDiccionarioABB<Clave, Valor>* eliminarCasoUnHijo(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: el nodo debe tener los 2 hijos
    // POS: elimina la memoria correspondiente del nodo (haciendo un cambio de clave) y devuelve el nuevo nodo hijo
    NodoDiccionarioABB<Clave, Valor>* eliminarCasoDosHijos(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: el nodo debe existir (nodo != nullptr)
    // POS: recorre el diccionario desde la raiz hasta encontrarse con el nodo y devuelve el nodo siguiente
    NodoDiccionarioABB<Clave, Valor>* sucesor(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: el nodo debe existir (nodo != nullptr)
    // POS: devuelve el nodo con la menor clave (desde el nodo pasado por parametro)
    NodoDiccionarioABB<Clave, Valor>* buscarMenor(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: el nodo debe existir (nodo != nullptr)
    // POS: devuelve el nodo con la mayor clave (desde el nodo pasado por parametro)
    NodoDiccionarioABB<Clave, Valor>* buscarMayor(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: -
    // POS: recorre el diccionario hasta encontrar el nodo buscado y lo devuelve, si no existe devuelve nullptr
    NodoDiccionarioABB<Clave, Valor>* buscar(NodoDiccionarioABB<Clave, Valor>* nodo, Clave clave);

    // PRE: -
    // POS: recorre el diccionario por completo de izquierda a derecha mientras imprime las claves de los nodos
    void imprimirEnOrden(NodoDiccionarioABB<Clave, Valor>* nodo);

    // PRE: -
    // POS: libera la memoria dando de baja uno por uno (mientras recorre el diccionario) todos los nodos
    void eliminarTodo(NodoDiccionarioABB<Clave, Valor>* nodo);

};


template <typename Clave, typename Valor>
void DiccionarioABB<Clave, Valor>::insertar(Clave clave, Valor valor) {

    raiz = insertar(raiz, clave, valor);

}

template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::insertar(NodoDiccionarioABB<Clave, Valor>* nodo, Clave clave, Valor valor) {

    if (nodo == nullptr)
        nodo = new NodoDiccionarioABB<Clave, Valor>(clave, valor);

    else if (clave < nodo->obtenerClave()) {

        nodo->asignarIzquierda(insertar(nodo->obtenerIzquierda(), clave, valor));
        nodo->obtenerIzquierda()->asignarPadre(nodo);
    }
    else {

        nodo->asignarDerecha(insertar(nodo->obtenerDerecha(), clave, valor));
        nodo->obtenerDerecha()->asignarPadre(nodo);
    }

    return nodo;

}


template <typename Clave, typename Valor>
void DiccionarioABB<Clave, Valor>::eliminar(Clave clave) {

    raiz = eliminar(raiz, clave);

}

template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::eliminar(NodoDiccionarioABB<Clave, Valor>* nodo, Clave clave) {

    if (clave == nodo->obtenerClave())

        if (nodo->esHoja())
            nodo = eliminarCasoHoja(nodo);

        else if (nodo->soloHijoIzquierdo() || nodo->soloHijoDerecho())
            nodo = eliminarCasoUnHijo(nodo);

        else
            nodo = eliminarCasoDosHijos(nodo);

    else if (clave < nodo->obtenerClave())
        nodo->asignarIzquierda(eliminar(nodo->obtenerIzquierda(), clave));

    else
       nodo->asignarDerecha(eliminar(nodo->obtenerDerecha(), clave));


    return nodo;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::eliminarCasoHoja(NodoDiccionarioABB<Clave, Valor>* nodo) {

    delete nodo;
    return nullptr;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::eliminarCasoUnHijo(NodoDiccionarioABB<Clave, Valor>* nodo) {

    NodoDiccionarioABB<Clave, Valor>* hijo;

    if (nodo->soloHijoIzquierdo())
        hijo = nodo->obtenerIzquierda();

    else
        hijo = nodo->obtenerDerecha();

    hijo->asignarPadre(nodo->obtenerPadre());

    delete nodo;

    return hijo;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::eliminarCasoDosHijos(NodoDiccionarioABB<Clave, Valor>* nodo) {

    Clave claveSucesor = sucesor(nodo)->obtenerClave();

    nodo->asignarClave(claveSucesor);
    nodo->asignarDerecha(eliminar(nodo->obtenerDerecha(), claveSucesor));

    return nodo;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::sucesor(NodoDiccionarioABB<Clave, Valor>* nodo) {

    if (nodo->obtenerDerecha())
        return buscarMenor(nodo->obtenerDerecha());

    NodoDiccionarioABB<Clave, Valor>* sucesor = nullptr;
    NodoDiccionarioABB<Clave, Valor>* ancestro = raiz;

    while (ancestro != nodo)

        if (nodo->obtenerClave() < ancestro->obtenerClave()) {

            sucesor = ancestro;
            ancestro = ancestro->obtenerIzquierda();
        }
        else
            ancestro = ancestro->obtenerDerecha();

    return sucesor;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::buscarMenor(NodoDiccionarioABB<Clave, Valor>* nodo) {

    if (nodo->obtenerIzquierda())
        return buscarMenor(nodo->obtenerIzquierda());

    return nodo;

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::buscarMayor(NodoDiccionarioABB<Clave, Valor>* nodo) {

    if (nodo->obtenerDerecha())
        return buscarMayor(nodo->obtenerDerecha());

    return nodo;

}


template <typename Clave, typename Valor>
bool DiccionarioABB<Clave, Valor>::contiene(Clave clave) {

    return (buscar(raiz, clave));

}


template <typename Clave, typename Valor>
NodoDiccionarioABB<Clave, Valor>* DiccionarioABB<Clave, Valor>::buscar(NodoDiccionarioABB<Clave, Valor>* nodo, Clave clave) {

    if (nodo == nullptr || clave == nodo->obtenerClave())
        return nodo;

    if (clave < nodo->obtenerClave())
        return buscar(nodo->obtenerIzquierda(), clave);

    return buscar(nodo->obtenerDerecha(), clave);

}


template <typename Clave, typename Valor>
Valor DiccionarioABB<Clave, Valor>:: obtenerValor(Clave clave) {

    return buscar(raiz, clave)->obtenerValor();

}


template <typename Clave, typename Valor>
void DiccionarioABB<Clave, Valor>::imprimirEnOrden() {

    imprimirEnOrden(raiz);
    cout << endl;

}

template <typename Clave, typename Valor>
void DiccionarioABB<Clave, Valor>::imprimirEnOrden(NodoDiccionarioABB<Clave, Valor>* nodo) {

    if (nodo) {

        imprimirEnOrden(nodo->obtenerIzquierda());
        cout << nodo->obtenerClave() << " - ";
        imprimirEnOrden(nodo->obtenerDerecha());
    }

}


template <typename Clave, typename Valor>
bool DiccionarioABB<Clave, Valor>::estaVacio() {

    return (raiz == nullptr);

}


template <typename Clave, typename Valor>
DiccionarioABB<Clave, Valor>::~DiccionarioABB() {

    eliminarTodo(raiz);

}


template <typename Clave, typename Valor>
void DiccionarioABB<Clave, Valor>::eliminarTodo(NodoDiccionarioABB<Clave, Valor>* nodo) {

    if (nodo == nullptr)
        return;

    eliminarTodo(nodo->obtenerIzquierda());
    eliminarTodo(nodo->obtenerDerecha());

    delete nodo;

}



#endif //DICCIONARIOABB_H
