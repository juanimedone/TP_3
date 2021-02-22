#ifndef TP_3_TIERRA_H
#define TP_3_TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {

    // atributos
private:
    bool defensaActiva = false;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de tierra con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Tierra(string nombre) : Personaje(nombre) {};

    // PRE: defensa_activa es true
	// POS: el personaje pierde 2 puntos de escudo y defensa_activa es false
	void desactivarDefensa();

    // PRE: -
	// POS: Devuelve COD_TIERRA
	string obtenerElemento() override;

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: aumenta o no la energia segun el caso y muestra un mensaje por pantalla
    void alimentar() override;

    // PRE: -
    // POS: de cumplirse los requisitos especificos de cada elemento, realiza el efecto de ataque correspondiente
    void atacar(array<Personaje*,3> enemigos) override;

    // PRE: -
    // POS: de cumplirse los requisitos de cada elemento, realiza el efecto de defensa correspondiente
    void defender(array<Personaje*,3> aliados) override;

    // PRE: -
    // POS: devuelve el daño que recibiria el personaje al ser atacado por el atacante,
    //      teniendo en cuenta elementos, escudo y defensa.
	int calcularAtkEntrante(Personaje* enemigo) override;


private:
    // PRE: el personaje no debe tener su energia al maximo
    // POS: aumenta la cantidad de energia que corresponda y lo muestra por pantalla
    void aumentarEnergia() override;

    // PRE: -
    // POS: devuelve true si tiene la maxima cantidad de energia, false de lo contrario
    bool energiaMaxima();

};


#endif //TP_3_TIERRA_H
