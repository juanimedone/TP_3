#include "tierra.h"


void Tierra::desactivarDefensa() {

	escudo -= ESCUDO_DEF_TIERRA;
	defensaActiva = false;

}


string Tierra::obtenerElemento() {

    return COD_TIERRA;

}


void Tierra::mostrar() {

    cout << "\n\n Elemento: Tierra" << endl;

    mostrarAtributos();

}


void Tierra::alimentar() {

    cout << "\n\n Elemento: Tierra" ;

    if ( energiaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de energia (" << ENERGIA_MAXIMA << ") \n\n" ;

    else
        aumentarEnergia();


}


void Tierra::atacar(array<Personaje*,MAX_PERSONAJES> enemigos) {

    if (energia < ENERGIA_ATK_TIERRA)

        cout << "\n\nLa energia actual es insuficiente para atacar. Valor requerido: " << ENERGIA_ATK_TIERRA << endl;

    else

        for (short int i = 0; i < MAX_PERSONAJES; i++)

            restarVida(enemigos[i]);

}


void Tierra::defender(array<Personaje*,MAX_PERSONAJES> aliados, Grafo& tablero) {

    if (energia < ENERGIA_DEF_TIERRA)

        cout << "\n\nLa energia actual es insuficiente para defender. Valor requerido: " << ENERGIA_DEF_TIERRA << endl;

    else {

        escudo += ESCUDO_DEF_TIERRA;

        if (escudo > ESCUDO_MAXIMO)
            defensaActiva = true;

        energia -= ENERGIA_DEF_TIERRA;
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

    else if (elemento == COD_TIERRA)

        danio = calcularAtkEntranteTierra(enemigo);


    if (defensaActiva)

        danio -= danio * MOD_DEF_TIERRA;

    else
        danio -= danio * (MOD_ESCUDO * escudo);


    return (int) danio;

}


void Tierra::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_HIERBAS > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_HIERBAS;

    energia += nuevaEnergia;

    cout << "\n\n '" << nombre << "' se ha alimentado correctamente de hierbas, suma " << nuevaEnergia << " punto/s de energia" << endl;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << "\n\n";

}


bool Tierra::energiaMaxima() {

    if (energia == ENERGIA_MAXIMA)
        return true;

    return false;

}
