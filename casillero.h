#ifndef TP_3_CASILLERO_H
#define TP_3_CASILLERO_H

#include "personaje.h"

class Casillero {

    // atributos
private:
    Personaje* personaje = nullptr;

    // metodos
public:
    // PRE: -
    // POS: carga el personaje en el casillero
    void asignarPersonaje(Personaje* personaje);

    // PRE: -
    // POS: devuelve el personaje que se encuentra en el casillero (si no hay devuelve nullptr)
    Personaje* obtenerPersonaje();

    // PRE: -
    // POS: devuelve true si no hay ningun personaje en el casillero, false de lo contrario
    bool estaVacio();

    // PRE: -
    // POS: devuelve el costo de pasar por el casillero segun el tipo de casillero y el elemento del personaje
    virtual int obtenerCosto(string elemento) = 0;

    // PRE: -
    // POS: devuelve el caracter que representa el tipo de casillero
    virtual char obtenerCodigo() = 0;

    // destructor
    // PRE: -
    // POS: libera el espacio de memoria que corresponda segun el tipo de casillero
    virtual ~Casillero() = default;

};


#endif //TP_3_CASILLERO_H
