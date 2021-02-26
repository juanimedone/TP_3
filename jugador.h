#ifndef TP_3_JUGADOR_H
#define TP_3_JUGADOR_H

#include "personaje.h"
#include "grafo.h"

class Jugador {

    // atributos
private:
    array<Personaje*,MAX_PERSONAJES> personajes;
    short int cantPersonajes = 0;
    short int opcion = 0;

    // metodos
public:
    // constructor
    // PRE:
    // POS:
    Jugador();

    // PRE:
    // POS:
    bool personajesCargados();

    // PRE:
    // POS:
    void asignarPersonaje(Personaje* personaje);

    // PRE:
    // POS:
    void posicionarPersonaje(Grafo& tablero, short int i);

    // PRE:
    // POS:
    bool quiereSalir();

    // PRE:
    // POS:
    void chequearBajas(Grafo& tablero);

    // PRE:
    // POS:
    void jugar(Grafo& tablero);

    // PRE:
    // POS:
    bool todosMuertos();

private:
    // PRE:
    // POS:
    void alimentarMover(Personaje*& personaje, Grafo& tablero);

    // PRE:
    // POS:
    void defenderAtacar(Personaje*& personaje, Grafo& tablero);

    // PRE:
    // POS:
    void moverPersonaje(Personaje*& personaje, Grafo& tablero);

    // PRE:
    // POS:
    void mostrarOpcionesAM();

    // PRE:
    // POS:
    void mostrarOpcionesDA();

    // PRE:
    // POS:
    void pedirOpcion();

    // PRE:
    // POS:
    void eliminarPersonaje(short int i, Grafo& tablero);

};


#endif //TP_3_JUGADOR_H
