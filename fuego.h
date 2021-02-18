#ifndef TP_3_FUEGO_H
#define TP_3_FUEGO_H

#include "personaje.h"

class Fuego : public Personaje {

    // atributos
private:

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de fuego con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Fuego(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: aumenta o no la vida dependiendo el caso y muestra un mensaje por pantalla
    void alimentar() override;

private:
    // PRE: el personaje no debe tener su vida al maximo
    // POS: aumenta la cantidad de vida que corresponda y lo muestra por pantalla
    void aumentarVida();

    // PRE: -
    // POS: devuelve true si tiene la maxima cantidad de vida, false de lo contrario
    bool vidaMaxima();

};


#endif //TP_3_FUEGO_H
