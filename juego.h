#ifndef TP_3_JUEGO_H
#define TP_3_JUEGO_H

#include "jugador.h"

class Juego {

    // atributos
private:
    Jugador* jugador1, *jugador2;
    Grafo* tablero;
    short int turno;
    bool salir;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: asigna los valores iniciales de los atributos y reserva el espacio necesario en el heap
    Juego();

    // PRE: -
    // POS: prepara y ejecuta el ciclo principal del juego
    void iniciarPartida();

    // PRE: -
    // POS: prepara y reanuda el ciclo principal del juego
    void reanudarPartida();

    // PRE: -
    // POS: cambia de quien es el turno
    void asignarTurno(short int turno);

    // PRE: -
    // POS: devuelve el jugador 1
    Jugador* obtenerJugador1();

    // PRE: -
    // POS: devuelve el jugador 2
    Jugador* obtenerJugador2();

    // PRE: -
    // POS: devuelve el tablero
    Grafo* obtenerTablero();

    // destructor
    // PRE: -
    // POS: libera la memoria pedida en el heap
    ~Juego();

private:
    // PRE: -
    // POS: detiene la ejecucion del programa hasta que el usuario presione una tecla para continuar
    void pausar();

    // PRE: -
    // POS: borra el contenido previo mostrado por pantalla
    void limpiarPantalla();

    // PRE: -
    // POS: pide a los jugadores y carga las posiciones de sus respectivos personajes
    void posicionarPersonajes();

    // PRE: -
    // POS: lleva a cabo los turnos de cada jugador hasta terminar o salir de la partida
    void cicloPrincipal();

    // PRE: -
    // POS: devuelve true si alguno de los jugadores tiene todos sus personajes muertos, false de lo contrario
    bool terminado();

    // PRE: -
    // POS: imprime por pantalla los nombres y los simbolos asociados a cada personaje
    void mostrarReferencias();

    // PRE: -
    // POS: imprime por pantalla los tipos de casillero y la letra asociada a cada uno
    void mostrarReferenciasCasilleros();

    // PRE: -
    // POS: imprime por pantalla quien es el ganador del juego
    void mostrarGanador();

};


#endif //TP_3_JUEGO_H
