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


void Personaje::asignarEnergia(int energia) {

    this->energia = energia;

}


void Personaje::asignarPosicion(array<int,2> posicion) {

    this->posicion = posicion;

}


void Personaje::asignarCodigo(char codigo) {

    this->codigo = codigo;

}


string Personaje::obtenerNombre() {

    return nombre;
}


short int Personaje::obtenerEscudo() {

    return escudo;

}


int Personaje::obtenerVida() {

    return vida;

}


int Personaje::obtenerEnergia() {

    return energia;

}


array<int,2> Personaje::obtenerPosicion() {

    return posicion;

}


char Personaje::obtenerCodigo() {

    return codigo;

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

    coords = {stoi(fila), stoi(columna)};

    return coords;

}


bool Personaje::energiaSuficiente(int energiaNecesaria) {

    if (energiaNecesaria <= energia)
        return true;

    return false;

}


void Personaje::vidaPorCeroEnergia() {

    int vidaPerdida;

    if (vida < 5)

        vidaPerdida = vida;

    else
        vidaPerdida = VIDA_TURNO_FUEGO;

    vida -= vidaPerdida;

    cout << "\n\n " << nombre << " perdio " << vidaPerdida << " puntos de vida por no tener energia" ;
    cout << "\n Vida anterior: " << vida + vidaPerdida << " -----> Vida actual: " << vida << "\n\n" ;

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

    if ( (vidaActual-vidaPerdida) < VIDA_MINIMA )

        enemigo->asignarVida(VIDA_MINIMA);

    enemigo->asignarVida(vidaActual-vidaPerdida);

    cout << "\nEl enemigo '" << enemigo->obtenerNombre() << "' fue atacado y sufrio " << vidaPerdida << " puntos de daño";

    cout << "\nVida anterior: " << vidaActual - vidaPerdida << " -----> Vida actual: " << enemigo->obtenerVida() << "\n\n";


}


bool Personaje::energiaMaxima() {

    if (energia == ENERGIA_MAXIMA)
        return true;

    return false;

}


int Personaje::calcularAtkEntranteTierra(Personaje* enemigo) {

    int danio;
    array<int,2> posEnemigo = enemigo->obtenerPosicion();

    int distanciaFila = abs(this->posicion[0] - posEnemigo[0]);
    int distanciaColumna = abs(this->posicion[1] - posEnemigo[1]);

    danio = ATK_BASE_TIERRA;

    if (distanciaFila <= 2 && distanciaColumna <= 2)

        danio *= 3;

    else if (distanciaFila <= 4 && distanciaColumna <= 4)

        danio *= 2;

    return danio;

}
