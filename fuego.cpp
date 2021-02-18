#include "fuego.h"


void Fuego::mostrar() {

    cout << "\n\n Elemento: Fuego" << endl;

    mostrarAtributos();

}


void Fuego::alimentar() {

    cout << "\n\n Elemento: Fuego" ;

    if ( vidaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de vida (" << VIDA_MAXIMA << ") \n\n" ;

    else
        aumentarVida();


}


void Fuego::aumentarVida() {

    int nuevaVida;

    if (vida + VIDA_MADERA > VIDA_MAXIMA)

        nuevaVida = VIDA_MAXIMA - vida;

    else
        nuevaVida = VIDA_MADERA;

    vida += nuevaVida;

    cout << "\n\n '" << nombre << "' se ha alimentado correctamente de madera, suma " << nuevaVida << " punto/s de vida" << endl;

    cout << "\n Vida anterior: " << vida - nuevaVida << " -----> Vida actual: " << vida << "\n\n";

}


bool Fuego::vidaMaxima() {

    if (vida == VIDA_MAXIMA)
        return true;

    return false;

}

