#include "agua.h"


string Agua::obtenerElemento() {

    return COD_AGUA;

}


bool Agua::defensaActivada() {

    return false;

}


void Agua::mostrar() {

    cout << "\n Elemento: Agua" << endl;

    mostrarAtributos();

}


void Agua::alimentar() {

    if ( energiaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de energia (" << ENERGIA_MAXIMA << ") \n\n" ;

    else
        if (vecesAlimentado < CANT_MAX_PLANCTON)

            aumentarEnergia();

        else
            cout << "\n\n No hay mas plancton para '" << nombre << "', ya se ha alimentado 3 veces al personaje \n" << endl;

}


void Agua::atacar(Personaje** enemigos, short int cantEnemigos) {

    array<int,2> posEnemigo{}, posAtacar{};
    bool hayEnemigos = false;

    if (energia < ENERGIA_ATK_AGUA)

        cout << "\n La energia actual es insuficiente para atacar"
                "\n Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_ATK_AGUA << endl << endl;

    else {

        short int i = 0;

        cout << "\n Ingrese las coordenadas a las que desea atacar" << endl;
        posAtacar = pedirCoordenadas();

        while (i < cantEnemigos && !hayEnemigos) {

            posEnemigo = enemigos[i]->obtenerPosicion();

            if (posEnemigo == posAtacar) {

                restarVida(enemigos[i]);
                hayEnemigos = true;
            }

            i++;
        }

        energia -= ENERGIA_ATK_AGUA;

        if (!hayEnemigos)

            cout << "\n '" << nombre <<"' ataco a la posicion indicada [" << posAtacar[0] << "," << posAtacar[1]
                 << "], pero no habia enemigos ahi" << endl;

    }

}


void Agua::defender(Personaje** aliados, short int cantPersonajes) {

    int nuevaVidaPropia;

    if (energia < ENERGIA_DEF_AGUA)

        cout << "\n La energia actual es insuficiente para defender"
                "\n Energia actual: " << energia <<
                "\n Energia necesaria: " << ENERGIA_DEF_AGUA << endl;

    else {

        if (vida + RECUP_DEF_AGUA > VIDA_MAXIMA)

            nuevaVidaPropia = VIDA_MAXIMA - vida;

        else
            nuevaVidaPropia = RECUP_DEF_AGUA;

        vida += nuevaVidaPropia;

        energia -= ENERGIA_DEF_AGUA;

        mostrarMsjDefensa(nuevaVidaPropia);

        for (short int i = 0; i < cantPersonajes; i++)

            if (aliados[i] != this)
                curarAliado(aliados[i]);



    }

}


int Agua::calcularAtkEntrante(Personaje* atacante) {

    int danio;
    string elemento = atacante->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA;

    else if (elemento == COD_AIRE)

        danio = ATK_BASE_AIRE;

    else if (elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO - MOD_ATK_FUEGO;

    else {

        danio = calcularAtkEntranteTierra(atacante);
        danio += MOD_ATK_TIERRA;
    }

    return (int) ( danio - danio * (MOD_ESCUDO * escudo) );


}


void Agua::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_PLANCTON > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_PLANCTON;

    energia += nuevaEnergia;

    vecesAlimentado ++;

    cout << "\n '" << nombre << "' se ha alimentado correctamente de plancton, suma " << nuevaEnergia << " punto/s de energia" << endl
         << " Recuerde que el plancton es muy dificil de conseguir, por lo que solo se lo puede alimentar "
         << CANT_MAX_PLANCTON << " veces en total (queda/n " << CANT_MAX_PLANCTON - vecesAlimentado << ")" << endl;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << "\n" ;

}


void Agua::mostrarMsjDefensa(int nuevaVidaPropia) {

    cout << "\n '" << nombre << "' ha convertido " << ENERGIA_DEF_AGUA << " puntos de energía en " << nuevaVidaPropia << " punto/s de vida"
         << "\n Ha curado " << CURA_DEF_AGUA << " puntos de vida a sus aliados \n"
         << "\n Vida anterior: " << vida - nuevaVidaPropia << " ---> Vida actual: " << vida
         << "\n Energia anterior: " << energia + ENERGIA_DEF_AGUA << " ---> Energia actual: " << energia << endl;

}


void Agua::curarAliado(Personaje* aliado) {

    int vidaAliado, nuevaVidaAliado;

    vidaAliado = aliado->obtenerVida();

    if (vidaAliado + CURA_DEF_AGUA > VIDA_MAXIMA)

        nuevaVidaAliado = VIDA_MAXIMA - vidaAliado;

    else

        nuevaVidaAliado = CURA_DEF_AGUA;

    vidaAliado += nuevaVidaAliado;

    aliado->asignarVida(vidaAliado);

    cout << "\n Aliado: '" << aliado->obtenerNombre() << "'"
            "\n Vida anterior: " << vidaAliado - nuevaVidaAliado << " ---> Vida actual: " << vidaAliado << endl;

}

