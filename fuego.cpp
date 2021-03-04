#include "fuego.h"


string Fuego::obtenerElemento() {

    return COD_FUEGO;

}


bool Fuego::defensaActivada() {

    return false;

}


void Fuego::mostrar() {

    cout << "\n Elemento: Fuego" << endl;

    mostrarAtributos();

}


void Fuego::alimentar() {

    if ( vidaMaxima() && energiaMaxima() )

        cout << "\n El personaje tiene la maxima cantidad de vida y energia (" << VIDA_MAXIMA << " y " << ENERGIA_MAXIMA << ") \n\n" ;

    else {

        cout << "\n '" << nombre << "' se ha alimentado correctamente de madera" ;

        if (vidaMaxima()) {

            cout << "\n\n El personaje tiene la maxima cantidad de vida (" << VIDA_MAXIMA << ") \n\n" ;

            aumentarEnergia();
        }

        else if (energiaMaxima()) {

            cout << "\n\n El personaje tiene la maxima cantidad de energia (" << ENERGIA_MAXIMA << ") \n\n" ;

            aumentarVida();
        }

        else {

            aumentarEnergia();
            aumentarVida();
        }
    }
}


void Fuego::atacar(Personaje** enemigos, short int cantEnemigos) {

    if (energia < ENERGIA_ATK_FUEGO)

        cout << "\n La energia actual es insuficiente para atacar"
                "\n Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_ATK_FUEGO << endl << endl;

    else {

        int filaAtacante = posicion[0];
        int filaEnemigo;
        bool hayEnemigos = false;

        for (short int i = 0; i < cantEnemigos; i++) {

            filaEnemigo = enemigos[i]->obtenerPosicion()[0];

            if (filaEnemigo >= filaAtacante - 1 && filaEnemigo <= filaAtacante + 1) {

                restarVida(enemigos[i]);
                hayEnemigos = true;
            }
        }

        if (!hayEnemigos)

            cout << "\n '" << nombre <<"' realizo un ataque a sus filas adyacentes, pero no habia enemigos ahi" << endl;

        energia -= ENERGIA_ATK_FUEGO;
    }

}


void Fuego::defender(Personaje** aliados, short int cantPersonajes) {

	int nuevaVida;

	if (energia < ENERGIA_DEF_FUEGO)

        cout << "\n La energia actual es insuficiente para defender"
                "\n Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_DEF_FUEGO << endl;

	else {

        if (vida + RECUP_DEF_FUEGO > VIDA_MAXIMA)

            nuevaVida = VIDA_MAXIMA - vida;

        else
            nuevaVida = RECUP_DEF_FUEGO;

        vida += nuevaVida;
        energia -= ENERGIA_DEF_FUEGO;

        cout << "\n '" << nombre << "' ha convertido " <<  ENERGIA_DEF_FUEGO << " puntos de energia en " << nuevaVida << " punto/s de vida"
                "\n Vida anterior: " << vida - nuevaVida << " ---> Vida actual: " << vida <<
                "\n Energia anterior: " << energia + ENERGIA_DEF_FUEGO << " ---> Energia actual: " << energia << endl;

	}

}


int Fuego::calcularAtkEntrante(Personaje* atacante) {

    int danio;
    string elemento = atacante->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA + MOD_ATK_AGUA;

    else if (elemento == COD_AIRE)

        danio = ATK_BASE_AIRE - MOD_ATK_AIRE;

    else if (elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO;

    else
        danio = calcularAtkEntranteTierra(atacante);


    return (int) ( danio - danio * (MOD_ESCUDO * escudo) );

}


void Fuego::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_MADERA > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_MADERA;

    energia += nuevaEnergia;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia;

}


void Fuego::aumentarVida() {

    int nuevaVida;

    if (vida + VIDA_MADERA > VIDA_MAXIMA)

        nuevaVida = VIDA_MAXIMA - vida;

    else
        nuevaVida = VIDA_MADERA;

    vida += nuevaVida;

    cout << "\n Vida anterior: " << vida - nuevaVida << " -----> Vida actual: " << vida << "\n" ;

}


bool Fuego::vidaMaxima() {

    if (vida == VIDA_MAXIMA)
        return true;

    return false;

}



