#ifndef TP_3_AIRE_H
#define TP_3_AIRE_H

#include "personaje.h"

class Aire: public Personaje {

    // atributos
private:

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de aire con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Aire(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: imprime un mensaje por pantalla
    void alimentar() override;

};


#endif //TP_3_AIRE_H
