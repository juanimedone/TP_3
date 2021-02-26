#include "archivoPartida.h"


ArchivoPartida::ArchivoPartida() {

    archivo.open(PATH_ARCHIVO_PARTIDA);

}


bool ArchivoPartida::hayPartidaGuardada() {

    return archivo.is_open();

}


void ArchivoPartida::cargarPartida(Juego& juego) {

    string turno;
    Jugador jugador1, jugador2;
    Grafo tablero;

    jugador1 = juego.obtenerJugador1();
    jugador2 = juego.obtenerJugador2();
    tablero = juego.obtenerTablero();

    getline(archivo, turno);
    juego.asignarTurno( (short) stoi(turno) );

    cargarPersonajes(tablero, jugador1);
    cargarPersonajes(tablero, jugador2);

}


void ArchivoPartida::guardarPartida() {



}


ArchivoPartida::~ArchivoPartida() {

    archivo.close();

}


void ArchivoPartida::cargarPersonajes(Grafo& tablero, Jugador& jugador) {

    Personaje* nuevoPersonaje;
    string turno, elemento, nombre, escudo, vida, energia, fila, columna;
    array<int,2> posicion{};

    for (short int i = 0; i < MAX_PERSONAJES; i++) {

        getline(archivo, elemento, ',');
        getline(archivo, nombre, ',');
        getline(archivo, escudo, ',');
        getline(archivo, vida, ',');
        getline(archivo, energia, ',');
        getline(archivo, fila, ',');
        getline(archivo, columna);

        posicion = {stoi(fila), stoi(columna)};
        nuevoPersonaje = crearPersonaje(elemento, nombre, escudo, vida, energia, posicion);

        tablero.posicionarPersonaje(nuevoPersonaje, posicion);
        jugador.asignarPersonaje(nuevoPersonaje);

    }

    nuevoPersonaje = nullptr;
    delete nuevoPersonaje;

}


Personaje* ArchivoPartida::crearPersonaje(const string& elemento, const string& nombre, const string& escudo,
                                          const string& vida, const string& energia, array<int,2> posicion) {

    Personaje* nuevoPersonaje;

    if (elemento == "agua")
        nuevoPersonaje = new Agua(nombre);

    else if (elemento == "fuego")
        nuevoPersonaje = new Fuego(nombre);

    else if (elemento == "tierra")
        nuevoPersonaje = new Tierra(nombre);

    else
        nuevoPersonaje = new Aire(nombre);

    nuevoPersonaje->asignarEscudo( (short) stoi(escudo) );
    nuevoPersonaje->asignarVida( stoi(vida) );
    nuevoPersonaje->asignarEnergia( stoi(energia) );
    nuevoPersonaje->asignarPosicion(posicion);

    return nuevoPersonaje;

}
