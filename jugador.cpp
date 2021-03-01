#include "jugador.h"


Jugador::Jugador() {

    for (short int i = 0; i < MAX_PERSONAJES; i++)
        personajes[i] = nullptr;

    cantPersonajes = 0;
    opcion = 0;

}


bool Jugador::personajesCargados() {

    return (cantPersonajes == MAX_PERSONAJES);

}


void Jugador::asignarPersonaje(Personaje* personaje) {

    personajes[cantPersonajes] = personaje;
    cantPersonajes++;

}


array<Personaje*,MAX_PERSONAJES> Jugador::obtenerPersonajes() {

    return personajes;

}


short int Jugador::obtenerCantPersonajes() {

    return cantPersonajes;

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
    tablero.moverPersonaje(personajes[i], COORD_INVALIDA, posicion);

}


bool Jugador::quiereSalir() {

    cout << "\n\n Desea guardar la partida y salir?"
            "\n 1- Si           2- No \n\n" ;

    pedirOpcion();

    if (opcion == GUARDAR_Y_SALIR)
        return true;

    return false;

}


void Jugador::chequearBajas(Grafo& tablero) {

    for (short int i = 0; i < cantPersonajes; i++)

        if (personajes[i]->obtenerVida() == VIDA_NULA)

            eliminarPersonaje(i, tablero);

}


void Jugador::jugar(Grafo& tablero, array<Personaje*,MAX_PERSONAJES> enemigos) {

    int i = 0;

    while (i < cantPersonajes) {

        cout << personajes[i]->obtenerNombre();

        if (personajes[i]->obtenerElemento() == COD_AIRE)

            personajes[i]->aumentarEnergia();

        else if (personajes[i]->obtenerElemento() == COD_FUEGO && personajes[i]->obtenerEnergia() == ENERGIA_MINIMA)

            personajes[i]->vidaPorCeroEnergia();

        alimentarMover(personajes[i], tablero);

        defenderAtacar(personajes[i], tablero, enemigos);

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
    Recorrido recorridoMin;

    posInicial = personaje->obtenerPosicion();
    posFinal = personaje->pedirCoordenadas();
    elemento = personaje->obtenerElemento();

    recorridoMin = tablero.caminoMinimo(posInicial, posFinal, elemento);
    energiaNecesaria = recorridoMin.obtenerEnergiaGastada();

    validarMovimiento(tablero, posInicial, posFinal, personaje, energiaNecesaria);

    tablero.moverPersonaje(personaje, posInicial, posFinal);
    personaje->asignarPosicion(posFinal);

    recorridoMin.mostrar();

}


void Jugador::validarMovimiento(Grafo& tablero, array<int,2> posInicial, array<int,2>& posFinal, Personaje* personaje, int& energiaNecesaria) {

    Recorrido recorridoMin;

    while ( !tablero.estaVacio(posFinal) || !personaje->energiaSuficiente(energiaNecesaria) ) {

        if ( !tablero.estaVacio(posFinal) )

            cout << "\n La posicion [" << posFinal[0] << "," << posFinal[1] << "] se encuentra ocupada por " <<
                 tablero.obtenerPersonaje(posFinal)->obtenerNombre() << "\n\n Reingrese las coordenadas \n" ;

        else
            cout << "\n El personaje " << personaje->obtenerNombre() << " no posee la energia necesaria para llegar a ["
                 << posFinal[0] << "," << posFinal[1] << "] \n\n Energia requerida: " << energiaNecesaria <<
                 "\n Energia actual: " << personaje->obtenerEnergia() << "\n\n Reingrese las coordenadas \n" ;

        posFinal = personaje->pedirCoordenadas();

        recorridoMin = tablero.caminoMinimo(posInicial, posFinal, personaje->obtenerElemento());
        energiaNecesaria = recorridoMin.obtenerEnergiaGastada();

    }

}


void Jugador::defenderAtacar(Personaje*& personaje, Grafo& tablero, array<Personaje*,MAX_PERSONAJES> enemigos) {

    mostrarOpcionesDA();
    pedirOpcion();

    switch (opcion) {

        case DEFENDERSE:

            if (personaje->obtenerElemento() == "aire")
                defensaAire(personaje, tablero);
            else
                personaje->defender(personajes);

            break;

        case ATACAR:
            personaje->atacar(enemigos);
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


void Jugador::defensaAire(Personaje*& personaje, Grafo& tablero) {

    array<int,2> posNueva{};
    int energia = personaje->obtenerEnergia();

    if (energia < ENERGIA_DEF_AIRE)

        cout << "\n\n La energia actual es insuficiente para defender. Valor requerido: " << ENERGIA_DEF_AIRE << endl;

    else {

        cout << "\n Inserte las coordenadas a las que desea volar." << endl;
        posNueva = personaje->pedirCoordenadas();

        while ( !tablero.estaVacio(posNueva) ) {

            cout << "\n\n La posicion esta ocupada por el personaje " << tablero.obtenerPersonaje(posNueva)->obtenerNombre() << ". Reingrese las coordenadas " ;
            posNueva = personaje->pedirCoordenadas();
        }

        tablero.moverPersonaje(personaje, personaje->obtenerPosicion(), posNueva);
        personaje->asignarPosicion(posNueva);

        cout << "\n\n'" << personaje->obtenerNombre() << "' ha utilizado " << ENERGIA_DEF_AIRE << "puntos de energía para volar a [" << posNueva[0] << "," << posNueva[1] << "]" << endl;

        personaje->asignarEnergia(energia - ENERGIA_DEF_AIRE);
    }

}


void Jugador::eliminarPersonaje(short int i, Grafo& tablero) {

    array<int,2> posicion{};

    posicion = personajes[i]->obtenerPosicion();

    tablero.eliminarPersonaje(posicion);

    for (short int j = i; j < MAX_PERSONAJES - 1; j++)

        personajes[j] = personajes[j+1];


    personajes[MAX_PERSONAJES - 1] = nullptr;
    delete personajes[MAX_PERSONAJES - 1];

    cantPersonajes--;

}



