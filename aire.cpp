#include "aire.h"


void Aire::energiaPorTurno() {

    energia += ENERGIA_TURNO_AIRE;

    if (energia > ENERGIA_MAXIMA)
        energia = ENERGIA_MAXIMA;

}


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

        cout << "\n\nLa energia actual es insuficiente para defender. Valor requerido: " << ENERGIA_DEF_AIRE << endl;

    else {

        cout << "\nInserte las coordenadas a las que desea volar." << endl;
        posNueva = pedirCoordenadas();    //----

        energia -= ENERGIA_DEF_AIRE;

        //acceder a grafo, chequear si posNueva esta vacia
        //eliminar pje de pos actual

        asignarPosicion(posNueva[0], posNueva[1]);

        //ubicar pje en el grafo en pos nueva  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿

        cout << "\n\n'" << nombre << "' ha utilizado " << ENERGIA_DEF_AIRE << "puntos de energía para volar a [" << posNueva[0] << "," << posNueva[1] << "]" << endl;

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


array<int,2> Aire::pedirPosicionDefensa() {

    static array<int,2> coords;
    string fila, columna;

    cout << "\nInserte las coordenadas a las que desea volar." << endl;
    pedirCoordenadas(fila, columna);

    coords[0] = stoi(fila);
    coords[1] = stoi(columna);

    return coords;

}

