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


array<int,2> Personaje::pedirCoordenadas() {

    static array<int,2> coords;
    string fila, columna;

    cout << "\nFila: ";
    getline(cin, fila);
    cout << "\nColumna: ";
    getline(cin, columna);

    while ( !esValida(fila, columna) ) {

        cout << "\n\nValores invalidos. Ingrese solo numeros enteros entre 0 y 8." << endl;

        cout << "\nFila: ";
        getline(cin, fila);
        cout << "\nColumna: ";
        getline(cin, columna);
    }

    coords[0] = stoi(fila);
    coords[1] = stoi(columna);

    return coords;

}


bool Personaje::esValida(string& fila, string& columna) {

    bool filaEsNumero = all_of(fila.begin(), fila.end(), ::isdigit);
    bool columnaEsNumero = all_of(columna.begin(), columna.end(), ::isdigit);

    return (filaEsNumero && columnaEsNumero && stoi(fila) <= MAX_FILA && stoi(fila) >= MIN_FILA && stoi(columna) <= MAX_COLUMNA && stoi(columna) >= MIN_COLUMNA);

}


void Personaje::restarVida(Personaje*& enemigo) {

    int vidaPerdida, vidaActual;

    vidaPerdida = enemigo->calcularAtkEntrante(this);
    vidaActual = enemigo->obtenerVida();

    if((vidaActual-vidaPerdida) < VIDA_MINIMA)

        enemigo->asignarVida(VIDA_MINIMA);

    enemigo->asignarVida(vidaActual-vidaPerdida);

    cout << "\nEl enemigo '" << enemigo->obtenerNombre() << "' fue atacado y sufrio " << vidaPerdida << " puntos de daño";

    cout << "\nVida anterior: " << vidaActual - vidaPerdida << " -----> Vida actual: " << enemigo->obtenerVida() << "\n\n";


}

