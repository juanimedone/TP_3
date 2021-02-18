#ifndef TP_3_PERSONAJE_H
#define TP_3_PERSONAJE_H

#include "utiles.h"

class Personaje {

    // atributos
protected:
    string nombre;
    short int escudo;
    int vida;
    int energia;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Personaje(string nombre);

    // PRE: ESCUDO_MINIMO <= escudo <= ESCUDO_MAXIMO
    // POS: modifica el valor del atributo escudo
    void asignarEscudo(short int escudo);

    // PRE: VIDA_MINIMA <= vida <= VIDA_MAXIMA
    // POS: modifica el valor del atributo vida
    void asignarVida(int vida);

    // PRE: -
    // POS: devuelve el nombre del personaje
    string obtenerNombre();

    // PRE: -
    // POS: imprime por pantalla el elemento que corresponda y los atributos del personaje
    virtual void mostrar() = 0;

    // PRE: -
    // POS: modifica la energia o la vida (o no hace nada) segun el elemento del personaje
    virtual void alimentar() = 0;

    // destructor
    // PRE: -
    // POS: libera el espacio de memoria que corresponda segun el elemento del personaje
    virtual ~Personaje() = default;

protected:
    // metodo interno comun para todas las clases hijas
    // PRE: -
    // POS: imprime por pantalla todos los atributos del personaje
    void mostrarAtributos();

};



#endif //TP_3_PERSONAJE_H
