#ifndef TP_3_ARCHIVOPARTIDA_H
#define TP_3_ARCHIVOPARTIDA_H

#include "juego.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"

class ArchivoPartida {

    // atributos
private:
    ifstream archivoEntrada;
    ofstream archivoSalida;

    // metodos
public:
    // constructor
    // PRE:
    // POS:
    ArchivoPartida();

    // PRE:
    // POS:
    bool hayPartidaGuardada();

    // PRE:
    // POS:
    void cargarPartida(Juego& juego);

    // PRE:
    // POS:
    void guardarPartida(Juego* juego, short int turno);

    // destructor
    // PRE:
    // POS:
    ~ArchivoPartida();

private:
    // PRE:
    // POS:
    void cargarPersonajes(Grafo& tablero, Jugador& jugador);

    // PRE: -
    // POS: reserva espacio para el elemento correspondiente en el heap y lo devuelve como puntero a Personaje
    Personaje* crearPersonaje(const string& elemento, const string& nombre, const string& escudo, const string& vida,
                              const string& energia, array<int,2> posicion);

    // PRE:
    // POS:
    void guardarPersonajes(array<Personaje*,MAX_PERSONAJES> personajes, short int cantPersonajes);

};


#endif //TP_3_ARCHIVOPARTIDA_H
