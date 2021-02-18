#ifndef TP_3_TIERRA_H
#define TP_3_TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {

    // atributos
private:

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de tierra con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Tierra(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: aumenta o no la energia segun el caso y muestra un mensaje por pantalla
    void alimentar() override;

private:
    // PRE: el personaje no debe tener su energia al maximo
    // POS: aumenta la cantidad de energia que corresponda y lo muestra por pantalla
    void aumentarEnergia();

    // PRE: -
    // POS: devuelve true si tiene la maxima cantidad de energia, false de lo contrario
    bool energiaMaxima();

};


#endif //TP_3_TIERRA_H
