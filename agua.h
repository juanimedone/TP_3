#ifndef TP_3_AGUA_H
#define TP_3_AGUA_H

#include "personaje.h"

class Agua : public Personaje {

    // atributos
private:
    short int vecesAlimentado = 0;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de agua con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Agua(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: aumenta o no la energia segun el caso y muestra un mensaje por pantalla
    void alimentar() override;

private:
    // PRE: el personaje no debe tener su energia al maximo y no haber alcanzado el limite de vecesAlimentado
    // POS: aumenta la cantidad de energia que corresponda, lo muestra por pantalla e incrementa vecesAlimentado en 1
    void aumentarEnergia();

    // PRE: -
    // POS: devuelve true si tiene la maxima cantidad de energia, false de lo contrario
    bool energiaMaxima();

};


#endif //TP_3_AGUA_H
