#include "casillero.h"


void Casillero::asignarPersonaje(Personaje* personaje) {

    this->personaje = personaje;

}


Personaje* Casillero::obtenerPersonaje() {

    return personaje;

}


bool Casillero::estaVacio() {

    return (personaje == nullptr);

}
