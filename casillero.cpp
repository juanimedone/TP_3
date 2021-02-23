#include "casillero.h"


void Casillero::asignarPersonaje(Personaje* personaje) {

    this->personaje = personaje;

}


bool Casillero::estaVacio() {

    return (personaje == nullptr);

}
