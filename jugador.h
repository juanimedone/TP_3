#ifndef TP_3_JUGADOR_H
#define TP_3_JUGADOR_H

#include "grafo.h"

class Jugador {

    // atributos
private:
    Personaje** personajes;         // vector dinamico de punteros a Personaje
    short int cantPersonajes;
    short int opcion;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: da valores iniciales nulos a los atributos
    Jugador();

    // PRE: -
    // POS: devuelve true si la cantidad de Personajes cargados es igual a MAX_PERSONAJES
    bool personajesCargados();

    // PRE: -
    // POS: agrega un nuevo personaje al array
    void asignarPersonaje(Personaje* personaje);

    // PRE: -
    // POS: devuelve el array de personajes
    Personaje** obtenerPersonajes();

    // PRE: -
    // POS: devuelve la cantidad de personajes que hay en el array
    short int obtenerCantPersonajes();

    // PRE:
    // POS: pide y actualiza la posicion del personaje (con indice i en el vector) y lo coloca en el tablero
    void posicionarPersonaje(Grafo*& tablero, short int i);

    // PRE: -
    // POS: devuelve true si el jugador quiere guardar y salir de la partida, false de lo contrario
    bool quiereSalir();

    // PRE: -
    // POS: chequea si hay personajes con VIDA_NULA y de ser asi los elimina
    void chequearBajas(Grafo*& tablero);

    // PRE: -
    // POS: lleva a cabo el turno del jugador, realiza las acciones para cada personaje
    void jugar(Grafo*& tablero, Personaje** enemigos);

    // PRE: -
    // POS: devuelve true si el jugador ya no tiene pesonajes con vida, false de lo contrario
    bool todosMuertos();

    // destructor
    // PRE: -
    // POS: libera la memoria pedida en el heap
    ~Jugador();

private:
    // PRE: -
    // POS: muestra un primer submenu por pantalla (por personaje) y ejecuta la opcion elegida por el jugador
    void alimentarMover(Personaje*& personaje, Grafo*& tablero);

    // PRE: -
    // POS: muestra por pantalla las opciones de alimentarse, moverse o pasar opcion
    void mostrarOpcionesAM();

    // PRE: el usuario debe ingresar un entero
    // POS: asigna la opcion ingresada por el usuario
    void pedirOpcion();

    // PRE: -
    // POS: pide y actualiza la posicion del personaje a mover y muestra por pantalla el recorrido tomado
    void moverPersonaje(Personaje*& personaje, Grafo*& tablero);

    // PRE: -
    // POS: chequea que el movimiento sea valido, de no serlo vuelve a pedir las coordenadas hasta que lo sea
    void validarMovimiento(Grafo*& tablero, array<int,2> posInicial, array<int,2>& posFinal, Personaje* personaje,
                           int& energiaNecesaria);

    // PRE: -
    // POS: muestra un segundo submenu por pantalla (por personaje) y ejecuta la opcion elegida por el jugador
    void defenderAtacar(Personaje*& personaje, Grafo*& tablero, Personaje** enemigos);

    // PRE: -
    // POS: muestra por pantalla las opciones de defensa, ataque o pasar opcion
    void mostrarOpcionesDA();

    // PRE: -
    // POS: si tiene la energia necesaria para volar, se posiciona al personaje en las coordenadas ingresadas por el
    //      usuario, de ser invalidas las coordenadas o no tener energia suficiente, se imprime un mensaje
    void defensaAire(Personaje*& personaje, Grafo*& tablero);

    // PRE: -
    // POS: elimina el personaje con indice i del array de personajes y del tablero
    void eliminarPersonaje(short int i, Grafo*& tablero);

};


#endif //TP_3_JUGADOR_H
