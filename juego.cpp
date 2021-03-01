#include "juego.h"
#include "archivoPartida.h"


Juego::Juego() {

    srand(time(nullptr));

    turno = rand() % CANT_JUGADORES + JUGADOR_1;

    salir = false;

}


void Juego::iniciarPartida() {

    tablero.inicializarMatrices();

    posicionarPersonajes();

    cicloPrincipal();

    if (!salir)
        mostrarGanador();

    pausar();

}


void Juego::reanudarPartida() {

    ArchivoPartida archivoPartida;

    tablero.inicializarMatrices();

    cicloPrincipal();

    if (!salir)
        mostrarGanador();

    pausar();

    archivoPartida.eliminarArchivo();

}


void Juego::asignarTurno(short int turno) {

    this->turno = turno;

}


Jugador Juego::obtenerJugador1() {

    return jugador1;

}


Jugador Juego::obtenerJugador2() {

    return jugador2;

}


Grafo* Juego::obtenerTablero() {

    return &tablero;

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

            cout << " Jugador 1 \n" ;
            jugador1.posicionarPersonaje(tablero, i);

            limpiarPantalla();

            cout << " Jugador 2 \n" ;
            jugador2.posicionarPersonaje(tablero, i);
        }

    else
        for (short int i = 0; i < MAX_PERSONAJES; i++) {

            cout << " Jugador 2 \n" ;
            jugador2.posicionarPersonaje(tablero, i);

            limpiarPantalla();

            cout << " Jugador 1 \n" ;
            jugador1.posicionarPersonaje(tablero, i);
        }

}


void Juego::cicloPrincipal() {

    if (turno == JUGADOR_1)

        while ( !terminado() && !salir ) {

            tablero.mostrar();
            mostrarReferencias();
            salir = jugador1.quiereSalir();

            if (!salir) {

                jugador1.jugar(tablero, jugador2.obtenerPersonajes() );
                jugador2.chequearBajas(tablero);
                pausar();

                tablero.mostrar();
                mostrarReferencias();
                salir = jugador2.quiereSalir();

                if (salir)
                    turno = JUGADOR_2;

                else {

                    jugador2.jugar(tablero, jugador1.obtenerPersonajes() );
                    jugador1.chequearBajas(tablero);
                    pausar();
                }
            }
        }

    else
        while ( !terminado() && !salir ) {

            tablero.mostrar();
            mostrarReferencias();
            salir = jugador2.quiereSalir();

            if (!salir) {

                jugador2.jugar(tablero, jugador1.obtenerPersonajes() );
                jugador1.chequearBajas(tablero);
                pausar();

                tablero.mostrar();
                mostrarReferencias();
                salir = jugador1.quiereSalir();

                if (salir)
                    turno = JUGADOR_1;

                else {

                    jugador1.jugar(tablero, jugador2.obtenerPersonajes() );
                    jugador2.chequearBajas(tablero);
                    pausar();
                }
            }
        }

    if (salir) {

        ArchivoPartida archivoPartida;

        archivoPartida.guardarPartida(this, turno);
    }

}


bool Juego::terminado() {

    return (jugador1.todosMuertos() || jugador2.todosMuertos());

}


void Juego::mostrarReferencias() {

    array<Personaje*,MAX_PERSONAJES> personajes{};

    cout << "\n\n\n\t\t Personajes" ;

    cout << "\n\n Jugador 1" ;

    personajes = jugador1.obtenerPersonajes();

    for (int i = 0; i < jugador1.obtenerCantPersonajes(); i++) {

        cout << "\n Nombre: " << personajes[i]->obtenerNombre() << " -> " << personajes[i]->obtenerCodigo();
    }

    cout << "\n\n Jugador 2" ;

    personajes = jugador2.obtenerPersonajes();

    for (int i = 0; i < jugador2.obtenerCantPersonajes(); i++) {

        cout << "\n Nombre: " << personajes[i]->obtenerNombre() << " -> " << personajes[i]->obtenerCodigo();
    }

}


void Juego::mostrarGanador() {

    if (jugador1.todosMuertos())
        cout << "\n El jugador 2 ha ganado la partida \n" ;

    else
        cout << "\n El jugador 1 ha ganado la partida \n" ;

}
