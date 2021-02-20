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
    array<int,2> posicion;

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
    // POS: modifica los valores de posicion a los ingresados
    void asignarPosicion(short int fila, short int columna);

    // PRE: -
    // POS: devuelve el nombre del personaje
    string obtenerNombre();

    // PRE: -
    // POS: devuelve la vida actual del personaje
    int obtenerVida();

    // PRE: -
    // POS: devuelve un arreglo con la posicion [fila, columna] del personaje
    array<int,2> obtenerPosicion();

    // PRE: -
    // POS: devuelve el elemento del personaje
    virtual string obtenerElemento() = 0;

    // PRE: -
    // POS: imprime por pantalla el elemento que corresponda y los atributos del personaje
    virtual void mostrar() = 0;

    // PRE: -
    // POS: modifica la energia o la vida (o no hace nada) segun el elemento del personaje
    virtual void alimentar() = 0;

    // PRE: el vector enemigos contiene tres personajes
    // POS: de cumplirse los requisitos especificos de cada elemento, realiza el efecto de ataque correspondiente
    virtual void atacar(array<Personaje*,3> enemigos) = 0;

    // PRE: el vector aliados contiene tres personajes
    // POS: de cumplirse los requisitos de cada elemento, realiza el efecto de defensa correspondiente
    virtual void defender(array<Personaje*,3> aliados) = 0;

    // PRE: -
    // POS: devuelve el daño que recibiria el personaje al ser atacado por el atacante,
    //      teniendo en cuenta elementos, escudo y habilidades especiales.
    virtual int calcularAtkEntrante(Personaje* atacante) = 0;

    // destructor
    // PRE: -
    // POS: libera el espacio de memoria que corresponda segun el elemento del personaje
    virtual ~Personaje() = default;


protected:
    // metodos internos comunes para todas las clases hijas
    // PRE: -
    // POS: imprime por pantalla todos los atributos del personaje
    void mostrarAtributos();

    // PRE:
    // POS:
    array<int,2> pedirCoordenadas();

    // PRE:
    // POS:
    bool esValida(string& fila, string& columna);

    // PRE:
    // POS:
    void restarVida(Personaje*& enemigo);

};



#endif //TP_3_PERSONAJE_H
