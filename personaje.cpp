#include "personaje.h"


Personaje::Personaje(string nombre) {

    srand(time(nullptr));

    this->nombre = nombre;
    escudo = rand() % RANGO_ESCUDO + ESCUDO_MINIMO;
    vida = rand() % RANGO_VIDA + VIDA_MINIMA;
    energia = rand() % RANGO_ENERGIA + ENERGIA_MINIMA;
    posicion = COORD_INVALIDA;

}


void Personaje::asignarEscudo(short int escudo) {

    this->escudo = escudo;

}


void Personaje::asignarVida(int vida) {

    this->vida = vida;

}


void Personaje::asignarPosicion(short int fila, short int columna) {

    posicion[0] = fila;
    posicion[1] = columna;

}


string Personaje::obtenerNombre() {

    return nombre;
}


int Personaje::obtenerVida() {

    return vida;

}


array<int,2> Personaje::obtenerPosicion() {

    return posicion;

}


void Personaje::mostrarAtributos() {

    cout << " Nombre: " << nombre << endl
         << " Escudo: " << escudo << endl
         << " Vida: " << vida << endl
         << " Energia: " << energia << endl
         << " Posicion: [" << posicion[0] << ", " << posicion[1] << "]" << endl;

}

