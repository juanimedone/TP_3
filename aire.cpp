#include "aire.h"


string Aire::obtenerElemento() {

    return COD_AIRE;

}


bool Aire::defensaActivada() {

    return false;

}


void Aire::atacar(Personaje** enemigos, short int cantEnemigos) {

    if (energia < ENERGIA_ATK_AIRE)

        cout << "\n La energia actual es insuficiente para atacar"
                "\n Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_ATK_AGUA << endl << endl;

    else {

        for (short int i = 0; i < cantEnemigos; ++i)

            restarVida(enemigos[i]);

        energia -= ENERGIA_ATK_AIRE;
    }

}


void Aire::mostrar() {

    cout << "\n Elemento: Aire" << endl;

    mostrarAtributos();

}


void Aire::alimentar() {

    cout << "\n Los personajes de aire no necesitan alimentarse \n";

}


int Aire::calcularAtkEntrante(Personaje* atacante) {

    int danio;
    string elemento = atacante->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA;

    else if (elemento == COD_AIRE)

        danio = ATK_BASE_AIRE;

    else if (elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO + MOD_ATK_FUEGO;

    else
        danio = ATK_BASE_TIERRA;


    return (int) ( danio - danio * (MOD_ESCUDO * escudo) );

}


void Aire::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_TURNO_AIRE > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_TURNO_AIRE;

    energia += nuevaEnergia;

    cout << "\n\n '" << nombre << "' suma " << nuevaEnergia << " puntos de energia \n" ;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia;

}
