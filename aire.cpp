#include "aire.h"


string Aire::obtenerElemento() {

    return COD_AIRE;

}


bool Aire::defensaActivada() {

    return false;

}


void Aire::atacar(Personaje** enemigos) {

    if (energia < ENERGIA_ATK_AIRE)

        cout << "\n\nLa energia actual es insuficiente para atacar. Valor requerido: " << ENERGIA_ATK_AIRE << endl;

    else {

        energia -= ENERGIA_ATK_AIRE;

        short int i = 0;

        while (enemigos[i]) {

            restarVida(enemigos[i]);

            i++;

        }

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

    int nuevaEnergia;

    if (energia + ENERGIA_TURNO_AIRE > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_TURNO_AIRE;

    energia += nuevaEnergia;

    cout << "\n\n " << nombre << " suma " << nuevaEnergia << " puntos de energia \n" ;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << "\n\n";


}
