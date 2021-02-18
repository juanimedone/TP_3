#include "agua.h"


void Agua::mostrar() {

    cout << "\n\n Elemento: Agua" << endl;

    mostrarAtributos();

}


void Agua::alimentar() {

    cout << "\n\n Elemento: Agua" ;

    if ( energiaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de energia (" << ENERGIA_MAXIMA << ") \n\n" ;

    else
        if (vecesAlimentado < CANT_MAX_PLANCTON)

            aumentarEnergia();

        else
            cout << "\n\n No hay mas plancton para '" << nombre << "', ya se ha alimentado 3 veces al personaje \n" << endl;


}


void Agua::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_PLANCTON > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_PLANCTON;

    energia += nuevaEnergia;

    vecesAlimentado ++;

    cout << "\n\n '" << nombre << "' se ha alimentado correctamente de plancton, suma " << nuevaEnergia << " punto/s de energia" << endl << endl
         << " Recuerde que el plancton es muy dificil de conseguir, por lo que solo se lo puede alimentar " << CANT_MAX_PLANCTON << " veces en total (queda/n " << CANT_MAX_PLANCTON - vecesAlimentado << ")" << endl;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << "\n\n";

}


bool Agua::energiaMaxima() {

    if (energia == ENERGIA_MAXIMA)
        return true;

    return false;

}

