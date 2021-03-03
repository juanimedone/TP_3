#ifndef TP_3_FUEGO_H
#define TP_3_FUEGO_H

#include "personaje.h"

class Fuego : public Personaje {

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de fuego con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Fuego(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: Devuelve COD_FUEGO
    string obtenerElemento() override;

    // PRE: solo para personajes de tierra
    // POS: devuelve false
    bool defensaActivada() override;

    // PRE: solo para personajes de tierra
    // POS: -
    void desactivarDefensa() override {};

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: aumenta o no la vida dependiendo el caso y muestra un mensaje por pantalla
    void alimentar() override;

    // PRE: -
    // POS: de cumplirse los requisitos especificos de cada elemento, realiza el efecto de ataque correspondiente
    void atacar(Personaje** enemigos) override;

    // PRE: -
    // POS: de cumplirse los requisitos de cada elemento, realiza el efecto de defensa correspondiente
    void defender(Personaje** aliados) override;

    // PRE: -
    // POS: devuelve el da�o que recibiria el personaje al ser atacado por el atacante,
    //      teniendo en cuenta elementos, escudo y habilidades especiales.
    int calcularAtkEntrante(Personaje* enemigo) override;

private:
    // PRE: el personaje no debe tener su energia al maximo
    // POS: aumenta la cantidad de energia que corresponda y lo muestra por pantalla
    void aumentarEnergia() override;

    // PRE: el personaje no debe tener su vida al maximo
    // POS: aumenta la cantidad de vida que corresponda y lo muestra por pantalla
    void aumentarVida();

    // PRE: -
    // POS: devuelve true si tiene la maxima cantidad de vida, false de lo contrario
    bool vidaMaxima();

};


#endif //TP_3_FUEGO_H
