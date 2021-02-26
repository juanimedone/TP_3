#include "juego.h"


Juego::Juego() {

    srand(time(nullptr));

    turno = rand() % CANT_JUGADORES + JUGADOR_1;

    salir = false;

}


void Juego::iniciarPartida() {

    posicionarPersonajes();

    cicloPrincipal();

    if (!salir)
        mostrarGanador();

}


void Juego::reanudarPartida() {

    cicloPrincipal();

    if (!salir)
        mostrarGanador();

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


Grafo Juego::obtenerTablero() {

    return tablero;

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
            salir = jugador1.quiereSalir();

            if (!salir) {

                jugador1.jugar(tablero, jugador2.obtenerPersonajes() );
                jugador2.chequearBajas(tablero);
                pausar();

                tablero.mostrar();
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
            salir = jugador2.quiereSalir();

            if (!salir) {

                jugador2.jugar(tablero, jugador1.obtenerPersonajes() );
                jugador1.chequearBajas(tablero);
                pausar();

                tablero.mostrar();
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


void Juego::mostrarGanador() {

    if (jugador1.todosMuertos())
        cout << "\n El jugador 2 ha ganado la partida \n" ;

    else
        cout << "\n El jugador 1 ha ganado la partida \n" ;

}
