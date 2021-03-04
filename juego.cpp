#include "juego.h"
#include "archivoPartida.h"


Juego::Juego() {

    jugador1 = new Jugador();
    jugador2 = new Jugador();

    tablero = new Grafo();

    srand(time(nullptr));

    turno = rand() % CANT_JUGADORES + JUGADOR_1;

    salir = false;

}


void Juego::iniciarPartida() {

    tablero->inicializarMatrices();

    posicionarPersonajes();

    cicloPrincipal();

    if (!salir)
        mostrarGanador();

}


void Juego::reanudarPartida() {

    ArchivoPartida archivoPartida;

    tablero->inicializarMatrices();

    cicloPrincipal();

    if (!salir) {

        mostrarGanador();
        archivoPartida.eliminarArchivo();
    }

}


void Juego::asignarTurno(short int turno) {

    this->turno = turno;

}


Jugador* Juego::obtenerJugador1() {

    return jugador1;

}


Jugador* Juego::obtenerJugador2() {

    return jugador2;

}


Grafo* Juego::obtenerTablero() {

    return tablero;

}


Juego::~Juego() {

    delete jugador1;
    delete jugador2;

    delete tablero;

}


void Juego::pausar() {

    cout << "\n\n Presione una tecla para continuar..." ;

    cin.get();
    cin.ignore();

    limpiarPantalla();

}


void Juego::limpiarPantalla() {

    #ifdef linux
        system("clear");
    #else
        system ("cls");
    #endif

}


void Juego::posicionarPersonajes() {

    if (turno == JUGADOR_1)

        for (short int i = 0; i < MAX_PERSONAJES; i++) {

            cout << "\n Preparando el juego.." ;
            cout << "\n\n\t\t POSICIONAR PERSONAJES \n\n" ;
            cout << "\n\t Jugador 1 \n\n" ;
            jugador1->posicionarPersonaje(tablero, i);

            limpiarPantalla();

            cout << "\n Preparando el juego.." ;
            cout << "\n\n\t\t POSICIONAR PERSONAJES \n\n" ;
            cout << "\n\t Jugador 2 \n\n" ;
            jugador2->posicionarPersonaje(tablero, i);

            limpiarPantalla();
        }

    else
        for (short int i = 0; i < MAX_PERSONAJES; i++) {

            cout << "\n Preparando el juego.." ;
            cout << "\n\n\t\t POSICIONAR PERSONAJES \n\n" ;
            cout << "\n\t Jugador 2 \n\n" ;
            jugador2->posicionarPersonaje(tablero, i);

            limpiarPantalla();

            cout << "\n Preparando el juego.." ;
            cout << "\n\n\t\t POSICIONAR PERSONAJES \n\n" ;
            cout << "\n\t Jugador 1 \n\n" ;
            jugador1->posicionarPersonaje(tablero, i);

            limpiarPantalla();
        }

}


void Juego::cicloPrincipal() {

    if (turno == JUGADOR_1)

        while ( !terminado() && !salir ) {

            tablero->mostrar();
            mostrarReferencias();

            cout << "\n\t Turno Jugador 1 \n" ;
            salir = jugador1->quiereSalir();

            if (!salir) {

                jugador1->jugar(tablero, jugador2);
                pausar();

                if ( !terminado() ) {

                    tablero->mostrar();
                    mostrarReferencias();

                    cout << "\n\t Turno Jugador 2 \n";
                    salir = jugador2->quiereSalir();

                    if (salir)
                        turno = JUGADOR_2;

                    else {

                        jugador2->jugar(tablero, jugador1);
                        pausar();
                    }
                }
            }
        }

    else
        while ( !terminado() && !salir ) {

            tablero->mostrar();
            mostrarReferencias();

            cout << "\n\t Turno Jugador 2 \n" ;
            salir = jugador2->quiereSalir();

            if (!salir) {

                jugador2->jugar(tablero, jugador1);
                pausar();

                if ( !terminado() ) {

                    tablero->mostrar();
                    mostrarReferencias();

                    cout << "\n\t Turno Jugador 1 \n" ;
                    salir = jugador1->quiereSalir();

                    if (salir)
                        turno = JUGADOR_1;

                    else {

                        jugador1->jugar(tablero, jugador2);
                        pausar();
                    }
                }
            }
        }

    if (salir) {

        ArchivoPartida archivoPartida;

        archivoPartida.guardarPartida(this, turno);
    }

}


bool Juego::terminado() {

    return (jugador1->todosMuertos() || jugador2->todosMuertos());

}


void Juego::mostrarReferencias() {

    Personaje** personajes;

    cout << "\n\n\t Personajes" ;

    cout << "\n\n Jugador 1\n" ;

    personajes = jugador1->obtenerPersonajes();

    for (int i = 0; i < jugador1->obtenerCantPersonajes(); i++)

        personajes[i]->mostrar();


    cout << "\n\n Jugador 2\n" ;

    personajes = jugador2->obtenerPersonajes();

    for (int i = 0; i < jugador2->obtenerCantPersonajes(); i++)

        personajes[i]->mostrar();


    mostrarReferenciasCasilleros();

}


void Juego::mostrarReferenciasCasilleros() {

    cout << "\n\n\t Tipos de casillero \n\n "
         << MONTANIA <<  ": Montania \n "
         << PRECIPICIO <<  ": Precipicio \n "
         << LAGO <<  ": Lago \n "
         << VOLCAN <<  ": Volcan \n "
         << CAMINO <<  ": Camino \n "
         << VACIO <<  ": Vacio \n\n " ;

}


void Juego::mostrarGanador() {

    if (jugador1->todosMuertos())
        cout << "\n\n Todos los personajes del jugador 1 han sido eliminados, el jugador 2 ha ganado la partida \n" ;

    else
        cout << "\n\n Todos los personajes del jugador 2 han sido eliminados, el jugador 1 ha ganado la partida \n" ;

}
