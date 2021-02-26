#include "jugador.h"


Jugador::Jugador() {

    for (short int i = 0; i < MAX_PERSONAJES; i++)
        personajes[i] = nullptr;

}


bool Jugador::personajesCargados() {

    return ( cantPersonajes == MAX_PERSONAJES );

}


void Jugador::asignarPersonaje(Personaje* personaje) {

    personajes[cantPersonajes] = personaje;
    cantPersonajes++;

}


void Jugador::posicionarPersonaje(Grafo& tablero, short int i) {

    array<int,2> posicion{};

    cout << " Personaje: " << personajes[i]->obtenerNombre() << "\n\n" ;

    posicion = personajes[i]->pedirCoordenadas();

    while ( !tablero.estaVacio(posicion) ) {

        cout << "\n La posicion [" << posicion[0] << "," << posicion[1] << "] esta ocupada por " <<
        tablero.obtenerPersonaje(posicion)->obtenerNombre() << "\n Vuelva a ingresar las coordenadas \n" ;

        posicion = personajes[i]->pedirCoordenadas();
    }

    personajes[i]->asignarPosicion(posicion);

}


bool Jugador::quiereSalir() {

    cout << "\n\n Desea guardar la partida y salir?"
            "\n 1- Si           2- No \n\n" ;

    pedirOpcion();

    if (opcion == GUARDAR_Y_SALIR)
        return true;

    return false;

}


void Jugador::jugar(Grafo& tablero) {

    int i = 0;

    while (i < cantPersonajes) {

        cout << personajes[i]->obtenerNombre();

        alimentarMover(personajes[i], tablero);

        defenderAtacar(personajes[i], tablero);

        i++;
    }

}


bool Jugador::todosMuertos() {

    return (cantPersonajes == 0);
}


void Jugador::alimentarMover(Personaje*& personaje, Grafo& tablero) {

    mostrarOpcionesAM();
    pedirOpcion();

    switch (opcion) {

        case ALIMENTARSE:
            personaje->alimentar();
            break;

        case MOVERSE:
            moverPersonaje(personaje, tablero);
            break;

        case PASAR:
            break;

        default: cout << " Ingreso una opcion invalida" << endl;

    }

}


void Jugador::mostrarOpcionesAM() {

    cout << "\n\n 1- Alimentarse \n"
            " 2- Moverse \n"
            " 3- Pasar opcion \n\n" ;

}


void Jugador::pedirOpcion() {

    cout << " Ingrese una opcion: ";
    cin >> opcion;

}


void Jugador::moverPersonaje(Personaje*& personaje, Grafo& tablero) {

    array<int,2> posInicial{}, posFinal{};
    int energiaNecesaria;
    string elemento;

    posInicial = personaje->obtenerPosicion();
    posFinal = personaje->pedirCoordenadas();
    elemento = personaje->obtenerElemento();

    energiaNecesaria = tablero.dijkstra(posInicial, elemento).obtenerEnergiaMinima();

    while ( !tablero.estaVacio(posFinal) || !personaje->energiaSuficiente(energiaNecesaria) ) {

        if ( !tablero.estaVacio(posFinal) )

            cout << "\n La posicion [" << posFinal[0] << "," << posFinal[1] << "] se encuentra ocupada por " <<
                 tablero.obtenerPersonaje(posFinal)->obtenerNombre() << "\n\n Reingrese las coordenadas\n" ;

        else
            cout << "\n El personaje " << personaje->obtenerNombre() << " no posee la energia necesaria para llegar a ["
            << posFinal[0] << "," << posFinal[1] << "] \n\n Energia requerida: " << energiaNecesaria <<
            "\n Energia actual: " << personaje->obtenerEnergia() << "\n\n Reingrese las coordenadas\n" ;

        posFinal = personaje->pedirCoordenadas();
    }

    tablero.posicionarPersonaje(personaje, posFinal);
    personaje->asignarPosicion(posFinal);

}


void Jugador::defenderAtacar(Personaje*& personaje, Grafo& tablero) {

    mostrarOpcionesDA();
    pedirOpcion();

    switch (opcion) {

        case DEFENDERSE:
            personaje->defender();
            break;

        case ATACAR:
            personaje->atacar();
            break;

        case PASAR:
            break;

        default: cout << " Ingreso una opcion invalida" << endl;

    }

}


void Jugador::mostrarOpcionesDA() {

    cout << "\n\n 1- Defenderse \n"
            " 2- Atacar \n"
            " 3- Pasar opcion \n\n" ;

}



