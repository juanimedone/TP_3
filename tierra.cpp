#include "tierra.h"


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
