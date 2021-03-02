#include "archivoPartida.h"


ArchivoPartida::ArchivoPartida() {

    archivoEntrada.open(PATH_ARCHIVO_PARTIDA);

}


bool ArchivoPartida::hayPartidaGuardada() {

    return archivoEntrada.is_open();

}


void ArchivoPartida::cargarPartida(Juego& juego) {

    string turno;
    Jugador* jugador1, *jugador2;
    Grafo* tablero;

    jugador1 = juego.obtenerJugador1();
    jugador2 = juego.obtenerJugador2();
    tablero = juego.obtenerTablero();

    getline(archivoEntrada, turno);
    juego.asignarTurno( (short) stoi(turno) );

    cargarPersonajes(tablero, jugador1);
    cargarPersonajes(tablero, jugador2);

}


void ArchivoPartida::guardarPartida(Juego* juego, short int turno) {

    array<Personaje*,MAX_PERSONAJES> personajes{};
    short int cantPersonajes;

    archivoSalida.open(PATH_ARCHIVO_PARTIDA);

    archivoSalida << turno << "\n" ;

    personajes = juego->obtenerJugador1()->obtenerPersonajes();
    cantPersonajes = juego->obtenerJugador1()->obtenerCantPersonajes();
    guardarPersonajes(personajes, cantPersonajes);

    personajes = juego->obtenerJugador2()->obtenerPersonajes();
    cantPersonajes = juego->obtenerJugador2()->obtenerCantPersonajes();
    guardarPersonajes(personajes, cantPersonajes);

    archivoSalida.close();

}


void ArchivoPartida::eliminarArchivo() {

    remove(PATH_ARCHIVO_PARTIDA);

}


ArchivoPartida::~ArchivoPartida() {

    archivoEntrada.close();

}


void ArchivoPartida::cargarPersonajes(Grafo* tablero, Jugador* jugador) {

    Personaje* nuevoPersonaje;
    string turno, elemento, nombre, escudo, vida, energia, fila, columna;
    array<int,2> posicion{};

    for (short int i = 0; i < MAX_PERSONAJES; i++) {

        getline(archivoEntrada, elemento, ',');
        getline(archivoEntrada, nombre, ',');
        getline(archivoEntrada, escudo, ',');
        getline(archivoEntrada, vida, ',');
        getline(archivoEntrada, energia, ',');
        getline(archivoEntrada, fila, ',');
        getline(archivoEntrada, columna);

        posicion = {stoi(fila), stoi(columna)};
        nuevoPersonaje = crearPersonaje(elemento, nombre, escudo, vida, energia, posicion);

        tablero->moverPersonaje(nuevoPersonaje, COORD_INVALIDA, posicion);
        jugador->asignarPersonaje(nuevoPersonaje);

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


void ArchivoPartida::guardarPersonajes(array<Personaje*,MAX_PERSONAJES> personajes, short int cantPersonajes) {

    int fila, columna;

    for (short int i = 0; i < cantPersonajes; i++) {

        fila = personajes[i]->obtenerPosicion()[0];
        columna = personajes[i]->obtenerPosicion()[1];

        archivoSalida << personajes[i]->obtenerElemento() << "," ;
        archivoSalida << personajes[i]->obtenerNombre() << "," ;
        archivoSalida << personajes[i]->obtenerEscudo() << "," ;
        archivoSalida << personajes[i]->obtenerVida() << "," ;
        archivoSalida << personajes[i]->obtenerEnergia() << "," ;
        archivoSalida << fila << "," ;
        archivoSalida << columna;

        archivoSalida << "\n" ;
    }

}
