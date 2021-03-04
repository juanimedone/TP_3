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
    // POS: devuelve COD_AGUA
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
    // POS: aumenta o no la energia segun el caso y muestra un mensaje por pantalla
    void alimentar() override;

    // PRE: el vector parametro contiene tres personajes
    // POS: de cumplirse los requisitos especificos de cada elemento, realiza el efecto de ataque correspondiente
    void atacar(Personaje** enemigos, short int cantEnemigos) override;

    // PRE: -
    // POS: de cumplirse los requisitos de cada elemento, realiza el efecto de defensa correspondiente
    void defender(Personaje** aliados, short int cantPersonajes) override;

    // PRE: -
    // POS: devuelve el daño que recibiria el personaje al ser atacado por un enemigo,
    //      teniendo en cuenta elementos, escudo y habilidades especiales
    int calcularAtkEntrante(Personaje* enemigo) override;

private:
    // PRE: el personaje no debe tener su energia al maximo y no haber alcanzado el limite de vecesAlimentado
    // POS: aumenta la cantidad de energia que corresponda, lo muestra por pantalla e incrementa vecesAlimentado en 1
    void aumentarEnergia() override;

    // PRE: -
    // POS: muestra por pantalla el efecto de la defensa
    void mostrarMsjDefensa(int nuevaVidaPropia);

    // PRE: -
    // POS: incrementa la vida del aliado y lo muestra por pantalla
    void curarAliado(Personaje* aliado);

};


#endif //TP_3_AGUA_H
