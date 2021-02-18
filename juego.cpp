#include "juego.h"


void Juego::iniciar() {

    posicionarPersonajes();

    cicloPrincipal();

    mostrarGanador();

}


Jugador Juego::obtenerJugador1() {

    return jugador1;

}


Jugador Juego::obtenerJugador2() {

    return jugador2;

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

    for (short int i = 0; i < MAX_PERSONAJES; i++) {

        cout << " Jugador 1 \n" ;
        jugador1.posicionarPersonaje(i);

        limpiarPantalla();

        cout << " Jugador 2 \n" ;
        jugador2.posicionarPersonaje(i);
    }

}


void Juego::cicloPrincipal() {

    while ( !terminado() ) {

        tablero.mostrar();
        jugador1.jugar(tablero);
        pausar();

        tablero.mostrar();
        jugador2.jugar(tablero);
        pausar();
    }

}


bool Juego::terminado() {

    return (jugador1.todosMuertos() || jugador2.todosMuertos());

}


void Juego::mostrarGanador() {

    if (jugador1.todosMuertos())
        cout << "\n El jugador 2 ha ganado la batalla \n" ;

    else
        cout << "\n El jugador 1 ha ganado la batalla \n" ;

}
