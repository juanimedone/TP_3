#include "fuego.h"


void Fuego::vidaPorCeroEnergia() {

    if (energia == 0)
        vida -= 5;

}


string Fuego::obtenerElemento() {

    return COD_FUEGO;

}


void Fuego::mostrar() {

    cout << "\n\n Elemento: Fuego" << endl;

    mostrarAtributos();

}


void Fuego::alimentar() {

    cout << "\n\n Elemento: Fuego" ;

    if ( vidaMaxima() && energiaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de vida y energia (" << VIDA_MAXIMA << " y " << ENERGIA_MAXIMA << ") \n\n" ;

    else {

        cout << "\n\n '" << nombre << "' se ha alimentado correctamente de madera" ;

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


void Fuego::atacar(array<Personaje*,3> enemigos) {

    if (energia < ENERGIA_DEF_FUEGO)

        cout << "\n\nLa energia actual es insuficiente para atacar. Valor requerido: " << ENERGIA_DEF_FUEGO << endl;

    else {

        int filaActual = posicion[0];

        for (int i = 0; i < MAX_PERSONAJES; i++)

            if (enemigos[i]->obtenerPosicion()[0] >= filaActual - 1 && enemigos[i]->obtenerPosicion()[0] <= filaActual + 1)

                restarVida(enemigos[i]);

        energia -= ENERGIA_ATK_FUEGO;
    }

}


void Fuego::defender(array<Personaje*,3> aliados) {

	int nuevaVida;

	if (energia < ENERGIA_DEF_FUEGO)

		cout << "\n\n La energia actual es insuficiente para defender. Valor requerido: " << ENERGIA_DEF_FUEGO << endl;

	else {

        if (vida + RECUP_DEF_FUEGO > VIDA_MAXIMA)

            nuevaVida = VIDA_MAXIMA - vida;

        else
            nuevaVida = RECUP_DEF_FUEGO;

        vida += nuevaVida;
        energia -= ENERGIA_DEF_FUEGO;

        cout << "\n\n'" << nombre << "' ha convertido 10 puntos de energía en " << nuevaVida << " punto/s de vida" << endl;
        cout << "\nVida anterior: " << vida - nuevaVida << " -----> Vida actual: " << vida << "\n";
        cout << "\nEnergia actual: " << energia << "\n\n";

	}

}


int Fuego::calcularAtkEntrante(Personaje* enemigo) {

    int danio;
    string elemento = enemigo->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA + MOD_ATK_AGUA;

    else if(elemento == COD_AIRE)

        danio = ATK_BASE_AIRE - MOD_ATK_AIRE;

    else if(elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO;

    else if(elemento == COD_TIERRA) {

        array<int,2> posEnemigo = enemigo->obtenerPosicion();

        int distanciaFila = abs(posicion[0] - posEnemigo[0]);
        int distanciaColumna = abs(posicion[1] - posEnemigo[1]);

        danio = ATK_BASE_TIERRA;

        if (distanciaFila <= 2 && distanciaColumna <= 2)

            danio *= 3;

        else if (distanciaFila <= 4 && distanciaColumna <= 4)

            danio *= 2;

    }

    return (int) ( danio - danio * (MOD_ESCUDO * escudo) );

}


void Fuego::aumentarEnergia() {

    if (energia + ENERGIA_MADERA > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_MADERA;

    energia += nuevaEnergia;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << "\n\n";

}


void Fuego::aumentarVida() {

    int nuevaVida;

    if (vida + VIDA_MADERA > VIDA_MAXIMA)

        nuevaVida = VIDA_MAXIMA - vida;

    else
        nuevaVida = VIDA_MADERA;

    vida += nuevaVida;

    cout << "\n Vida anterior: " << vida - nuevaVida << " -----> Vida actual: " << vida << "\n\n";

}


bool Fuego::vidaMaxima() {



    if (vida == VIDA_MAXIMA)
        return true;

    return false;

}



