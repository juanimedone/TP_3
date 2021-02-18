#include "personaje.h"


Personaje::Personaje(string nombre) {

    srand(time(nullptr));

    this->nombre = nombre;
    escudo = rand() % RANGO_ESCUDO + ESCUDO_MINIMO;
    vida = rand() % RANGO_VIDA + VIDA_MINIMA;
    energia = rand() % RANGO_ENERGIA + ENERGIA_MINIMA;

}


void Personaje::asignarEscudo(short int escudo) {

    this->escudo = escudo;

}


void Personaje::asignarVida(int vida) {

    this->vida = vida;

}


string Personaje::obtenerNombre() {

    return nombre;
}


void Personaje::mostrarAtributos() {

    cout << " Nombre: " << nombre << endl
         << " Escudo: " << escudo << endl
         << " Vida: " << vida << endl
         << " Energia: " << energia << endl ;

}

