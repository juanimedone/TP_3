#include "jugador.h"


Jugador::Jugador() {

    personajes = new Personaje*[MAX_PERSONAJES];

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


Personaje** Jugador::obtenerPersonajes() {

    return personajes;

}


short int Jugador::obtenerCantPersonajes() {

    return cantPersonajes;

}


void Jugador::posicionarPersonaje(Grafo*& tablero, short int i) {

    array<int,2> posicion{};

    cout << " Personaje: " << personajes[i]->obtenerNombre() << "\n" ;

    posicion = personajes[i]->pedirCoordenadas();

    while ( !tablero->estaVacio(posicion) ) {

        cout << "\n La posicion [" << posicion[0] << "," << posicion[1] << "] esta ocupada por " <<
        tablero->obtenerPersonaje(posicion)->obtenerNombre() << "\n\n Vuelva a ingresar las coordenadas \n" ;

        posicion = personajes[i]->pedirCoordenadas();
    }

    personajes[i]->asignarPosicion(posicion);
    tablero->moverPersonaje(personajes[i], COORD_INVALIDA, posicion);

}


bool Jugador::quiereSalir() {

    cout << "\n Desea guardar la partida y salir?"
            "\n    1- Si           2- No \n\n" ;

    pedirOpcion();

    if (opcion == GUARDAR_Y_SALIR)
        return true;

    return false;

}


void Jugador::jugar(Grafo*& tablero, Jugador*& rival) {

    short int i = 0;

    while ( i < cantPersonajes && !rival->todosMuertos() ) {

        cout << "\n\n Personaje: '" << personajes[i]->obtenerNombre() << "'" ;

        if ( personajes[i]->obtenerElemento() == COD_AIRE )

            personajes[i]->aumentarEnergia();

        else if ( personajes[i]->obtenerElemento() == COD_FUEGO && personajes[i]->obtenerEnergia() == ENERGIA_MINIMA )

            personajes[i]->vidaPorCeroEnergia();

        else if ( personajes[i]->obtenerElemento() == COD_TIERRA && personajes[i]->defensaActivada() )

            personajes[i]->desactivarDefensa();


        alimentarMover(personajes[i], tablero);

        cout << "\n\n Personaje: '" << personajes[i]->obtenerNombre() << "'" ;
        defenderAtacar(personajes[i], tablero, rival->obtenerPersonajes(), rival->obtenerCantPersonajes());

        rival->chequearBajas(tablero);

        i++;
    }

}


bool Jugador::todosMuertos() {

    return (cantPersonajes == 0);

}


Jugador::~Jugador() {

    for (short int i = 0; i < cantPersonajes; i++)
        delete personajes[i];

    delete [] personajes;

}


void Jugador::alimentarMover(Personaje*& personaje, Grafo*& tablero) {

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


void Jugador::moverPersonaje(Personaje*& personaje, Grafo*& tablero) {

    array<int,2> posInicial{}, posFinal{};
    int energiaAnterior, energiaNecesaria;
    string elemento;
    Recorrido recorridoMin;

    posInicial = personaje->obtenerPosicion();
    energiaAnterior = personaje->obtenerEnergia();
    elemento = personaje->obtenerElemento();

    cout << "\n Ingrese las coordenadas a donde desea moverse " << endl;
    posFinal = personaje->pedirCoordenadas();

    recorridoMin = tablero->caminoMinimo(posInicial, posFinal, elemento);
    energiaNecesaria = recorridoMin.obtenerEnergiaGastada();

    validarMovimiento(tablero, posInicial, posFinal, personaje, energiaNecesaria);

    tablero->moverPersonaje(personaje, posInicial, posFinal);
    personaje->asignarPosicion(posFinal);

    cout << "\n '" << personaje->obtenerNombre() << "' se ha movido de [" << posInicial[0] << "," << posInicial[1]
         << "] a [" << posFinal[0] << "," << posFinal[1] << "]";

    recorridoMin.mostrar();

    personaje->asignarEnergia(energiaAnterior - energiaNecesaria);
    cout << "\n Energia anterior: " << energiaAnterior << " ---> Energia actual: " << energiaAnterior - energiaNecesaria << endl;

}


void Jugador::validarMovimiento(Grafo*& tablero, array<int,2> posInicial, array<int,2>& posFinal, Personaje* personaje, int& energiaNecesaria) {

    Recorrido recorridoMin;

    while ( !tablero->estaVacio(posFinal) || !personaje->energiaSuficiente(energiaNecesaria) ) {

        if ( !tablero->estaVacio(posFinal) )

            cout << "\n La posicion [" << posFinal[0] << "," << posFinal[1] << "] se encuentra ocupada por '" <<
                 tablero->obtenerPersonaje(posFinal)->obtenerNombre() << "'\n\n Reingrese las coordenadas a donde desea moverse\n" ;

        else
            cout << "\n El personaje " << personaje->obtenerNombre() << " no posee la energia necesaria para llegar a ["
                 << posFinal[0] << "," << posFinal[1] << "] \n\n Energia necesaria: " << energiaNecesaria <<
                 "\n Energia actual: " << personaje->obtenerEnergia() << "\n\n Reingrese las coordenadas a donde desea moverse \n" ;

        posFinal = personaje->pedirCoordenadas();

        recorridoMin = tablero->caminoMinimo(posInicial, posFinal, personaje->obtenerElemento());
        energiaNecesaria = recorridoMin.obtenerEnergiaGastada();

    }

}


void Jugador::defenderAtacar(Personaje*& personaje, Grafo*& tablero, Personaje** enemigos, short int cantEnemigos) {

    mostrarOpcionesDA();
    pedirOpcion();

    switch (opcion) {

        case DEFENDERSE:

            if (personaje->obtenerElemento() == COD_AIRE)
                defensaAire(personaje, tablero);
            else
                personaje->defender(personajes, cantPersonajes);

            break;

        case ATACAR:
            personaje->atacar(enemigos, cantEnemigos);
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


void Jugador::defensaAire(Personaje*& personaje, Grafo*& tablero) {

    int energia = personaje->obtenerEnergia();

    if (energia < ENERGIA_DEF_AIRE)

        cout << "\n La energia actual es insuficiente para defender \n"
                "\n Energia actual: " << personaje->obtenerEnergia() <<
                "\n Energia necesaria: " << ENERGIA_DEF_AIRE << endl;

    else {

        array<int,2> posInicial{}, posFinal{};

        posInicial = personaje->obtenerPosicion();

        cout << "\n Ingrese las coordenadas a las que desea volar " << endl;
        posFinal = personaje->pedirCoordenadas();

        while ( !tablero->estaVacio(posFinal) ) {

            cout << "\n La posicion [" << posFinal[0] << "," << posFinal[1] << "] esta ocupada por el personaje " <<
                    tablero->obtenerPersonaje(posFinal)->obtenerNombre() << ". Reingrese las coordenadas a las que desea volar \n" ;
            posFinal = personaje->pedirCoordenadas();
        }

        tablero->moverPersonaje(personaje, personaje->obtenerPosicion(), posFinal);
        personaje->asignarPosicion(posFinal);

        personaje->asignarEnergia(energia - ENERGIA_DEF_AIRE);

        cout << "\n '" << personaje->obtenerNombre() << "' ha utilizado " << ENERGIA_DEF_AIRE <<
                " puntos de energía para volar de [" << posInicial[0] << "," << posInicial[1]
                << "] a [" << posFinal[0] << "," << posFinal[1] << "] \n";
        cout << " Energia anterior: " << energia << " ---> Energia actual: " << energia - ENERGIA_DEF_AIRE << endl;

    }

}


void Jugador::chequearBajas(Grafo*& tablero) {

    short int i = 0;

    while (i < cantPersonajes)

        if (personajes[i]->obtenerVida() == VIDA_NULA)

            eliminarPersonaje(i, tablero);

        else
            i++;

}


void Jugador::eliminarPersonaje(short int i, Grafo*& tablero) {

    Personaje* eliminar;
    array<int,2> posicion{};

    eliminar = personajes[i];

    posicion = eliminar->obtenerPosicion();

    tablero->eliminarPersonaje(posicion);

    for (short int j = i; j < cantPersonajes - 1; j++)

        personajes[j] = personajes[j+1];


    personajes[cantPersonajes - 1] = nullptr;
    delete personajes[cantPersonajes - 1];

    cout << "\n Se ha eliminado el personaje enemigo '" << eliminar->obtenerNombre() << "' de la posicion [" << posicion[0]
         << "," << posicion[1] << "]" << endl;

    delete eliminar;
    cantPersonajes--;

}






