#include "aire.h"




string Aire::obtenerElemento() {

    return COD_AIRE;

}


void Aire::atacar(array<Personaje*,3> enemigos) {

    if (energia < ENERGIA_ATK_AIRE)

        cout << "\n\nLa energia actual es insuficiente para atacar. Valor requerido: " << ENERGIA_ATK_AIRE << endl;

    else {

        energia -= ENERGIA_ATK_AIRE;

        for(int i = 0; i < MAX_PERSONAJES; i++)

            restarVida(enemigos[i]);

    }

}


void Aire::defender(array<Personaje*,3> aliados) {

    array<int,2> posNueva{};

    if (energia < ENERGIA_DEF_AIRE)

        cout << "\n\n La energia actual es insuficiente para defender. Valor requerido: " << ENERGIA_DEF_AIRE << endl;

    else {

        cout << "\n Inserte las coordenadas a las que desea volar." << endl;
        posNueva = pedirCoordenadas();

        while ( !tablero.estaVacia(posNueva) ) {  // acceder a grafo, chequear si posNueva esta vacia

            cout << "\n\n La posicion esta ocupada. Reingrese las coordenadas " ;
            posNueva = pedirCoordenadas();
        }

        tablero.eliminar(posActual);        // eliminar pje de pos actual
        tablero.posicionar(this, posNueva);     // ubicar pje en el grafo en pos nueva

        asignarPosicion(posNueva[0], posNueva[1]);

        cout << "\n\n'" << nombre << "' ha utilizado " << ENERGIA_DEF_AIRE << "puntos de energía para volar a [" << posNueva[0] << "," << posNueva[1] << "]" << endl;

        energia -= ENERGIA_DEF_AIRE;
    }

}


void Aire::mostrar() {

    cout << "\n\n Elemento: Aire" << endl;

    mostrarAtributos();

}


void Aire::alimentar() {

    cout << "\n\n Elemento: Aire" ;

    cout << "\n\n Los personajes de aire no necesitan alimentarse \n" << endl;

}


int Aire::calcularAtkEntrante(Personaje* enemigo) {

    int danio;
    string elemento = enemigo->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA;

    else if (elemento == COD_AIRE)

        danio = ATK_BASE_AIRE;

    else if (elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO + MOD_ATK_FUEGO;

    else if (elemento == COD_TIERRA)

        danio = ATK_BASE_TIERRA;


    return (int) ( danio - danio * (MOD_ESCUDO * escudo) );

}


void Aire::aumentarEnergia() {

    energia += ENERGIA_TURNO_AIRE;

    if (energia > ENERGIA_MAXIMA)
        energia = ENERGIA_MAXIMA;

}
