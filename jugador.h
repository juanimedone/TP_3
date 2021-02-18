#ifndef TP_3_JUGADOR_H
#define TP_3_JUGADOR_H

#include "personaje.h"
#include "grafo.h"

class Jugador {

    // atributos
private:
    Personaje* personajes[MAX_PERSONAJES];
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
    void posicionarPersonaje(short int i);

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
    void pedirCoordenadas(short int& fila, short int& columna);

    // PRE:
    // POS:
    void mostrarOpcionesAM();

    // PRE:
    // POS:
    void mostrarOpcionesDA();

    // PRE:
    // POS:
    void pedirOpcion();

};


#endif //TP_3_JUGADOR_H
