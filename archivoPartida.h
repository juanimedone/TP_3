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
    ifstream archivoEntrada;            // para cargar una partida
    ofstream archivoSalida;             // para guardar la partida

    // metodos
public:
    // constructor
    // PRE: -
    // POS: abre el archivo de la partida guardada (si existe) con PATH_ARCHIVO_PARTIDA
    ArchivoPartida();

    // PRE: -
    // POS: devuelve true si el archivo de la partida guardada abrio correctamente, false de lo contrario
    bool hayPartidaGuardada();

    // PRE: debe existir un archivo de partida guardada
    // POS: prepara el juego para reaunudar la partida
    void cargarPartida(Juego& juego);

    // PRE: -
    // POS: crea un archivo .csv y guarda los datos de la partida
    void guardarPartida(Juego* juego, short int turno);

    // PRE: debe existir un archivo de partida guardada
    // POS: elimina el archivo .csv
    void eliminarArchivo();

    // destructor
    // PRE: -
    // POS: cierra el archivo de entrada
    ~ArchivoPartida();

private:
    // PRE: los personajes deben haber sido guardados en el .csv con el formato correspondiente
    // POS: crea los personajes, se los asigna a los jugadores y los carga en el tablero
    void cargarPersonajes(Grafo* tablero, Jugador& jugador);

    // PRE: -
    // POS: reserva espacio para el elemento correspondiente en el heap y lo devuelve como puntero a Personaje
    Personaje* crearPersonaje(const string& elemento, const string& nombre, const string& escudo, const string& vida,
                              const string& energia, array<int,2> posicion);

    // PRE: -
    // POS: carga los personajes en el archivo de guardado
    void guardarPersonajes(array<Personaje*,MAX_PERSONAJES> personajes, short int cantPersonajes);

};


#endif //TP_3_ARCHIVOPARTIDA_H
