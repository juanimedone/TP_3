#include "tierra.h"


bool Tierra::defensaActivada() {

    return defensaActiva;

}


void Tierra::desactivarDefensa() {

	escudo -= ESCUDO_DEF_TIERRA;
	defensaActiva = false;

}


string Tierra::obtenerElemento() {

    return COD_TIERRA;

}


void Tierra::mostrar() {

    cout << "\n Elemento: Tierra" << endl;

    mostrarAtributos();

}


void Tierra::alimentar() {

    if ( energiaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de energia (" << ENERGIA_MAXIMA << ") \n\n" ;

    else
        aumentarEnergia();

}


void Tierra::atacar(Personaje** enemigos, short int cantEnemigos) {

    if (energia < ENERGIA_ATK_TIERRA)

        cout << "\n La energia actual es insuficiente para atacar"
                "\n Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_ATK_TIERRA << endl << endl;

    else

        for (short int i = 0; i < cantEnemigos; i++)

            restarVida(enemigos[i]);

}


void Tierra::defender(Personaje** aliados, short int cantPersonajes) {

    if (energia < ENERGIA_DEF_TIERRA)

        cout << "\n\n La energia actual de '" << nombre << "' es insuficiente para defender \n"
                " Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_DEF_TIERRA << endl;

    else {

        escudo += ESCUDO_DEF_TIERRA;
        defensaActiva = true;

        energia -= ENERGIA_DEF_TIERRA;

        cout << "\n Se ha aumentado el valor del escudo de '" << nombre << "' en " << ESCUDO_DEF_TIERRA << " por un turno \n"
             << "\n Escudo anterior: " << escudo - ESCUDO_DEF_TIERRA << " ---> Escudo actual: " << escudo
             << "\n Energia anterior: " << energia + ENERGIA_DEF_TIERRA << " ---> Energia actual: " << energia << "\n\n";
    }

}


int Tierra::calcularAtkEntrante(Personaje* enemigo) {

    int danio;
    string elemento = enemigo->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA - MOD_ATK_AGUA;

    else if (elemento == COD_AIRE)

        danio = ATK_BASE_AIRE + MOD_ATK_AIRE;

    else if (elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO;

    else
        danio = calcularAtkEntranteTierra(enemigo);


    if (escudo > ESCUDO_MAXIMO)

        danio -= danio * MOD_DEF_TIERRA;

    else
        danio -= danio * (MOD_ESCUDO * escudo);


    return danio;

}


void Tierra::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_HIERBAS > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_HIERBAS;

    energia += nuevaEnergia;

    cout << "\n\n '" << nombre << "' se ha alimentado correctamente de hierbas, suma " << nuevaEnergia << " punto/s de energia" << endl;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << endl;

}





