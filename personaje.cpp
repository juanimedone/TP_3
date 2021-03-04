#include "personaje.h"


Personaje::Personaje(string nombre) {

    srand(time(nullptr));

    this->nombre = nombre;
    escudo = rand() % RANGO_ESCUDO + ESCUDO_MINIMO;
    vida = rand() % RANGO_VIDA + VIDA_MINIMA;
    energia = rand() % RANGO_ENERGIA + ENERGIA_MINIMA;
    posicion = COORD_INVALIDA;
    codigo = nombre[0];

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
         << " Posicion: [" << posicion[0] << "," << posicion[1] << "]" << endl
         << " Simbolo: " << codigo << endl;

}


array<int,2> Personaje::pedirCoordenadas() {

    static array<int,2> coords;
    string fila, columna;

    cout << "\n Fila: ";
    cin >> fila;
    cout << " Columna: ";
    cin >> columna;

    while ( !esValida(fila, columna) ) {

        cout << "\n\n Valores invalidos. Ingrese solo numeros enteros entre 0 y 7." << endl;

        cout << "\n Fila: ";
        cin >> fila;
        cout << " Columna: ";
        cin >> columna;
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

    return (filaEsNumero && columnaEsNumero && stoi(fila) < MAX_FILA && stoi(fila) >= MIN_FILA && stoi(columna) < MAX_COLUMNA && stoi(columna) >= MIN_COLUMNA);

}


void Personaje::restarVida(Personaje*& enemigo) {

    int vidaAnterior, vidaPerdida;
    array<int,2> posicion{};

    posicion = enemigo->obtenerPosicion();

    vidaAnterior = enemigo->obtenerVida();
    vidaPerdida = enemigo->calcularAtkEntrante(this);

    if ( (vidaAnterior - vidaPerdida) <= VIDA_NULA )

        vidaPerdida = vidaAnterior;

    enemigo->asignarVida(vidaAnterior - vidaPerdida);

    cout << "\n El enemigo '" << enemigo->obtenerNombre() << "' fue atacado en [" << posicion[0] << "," << posicion[1]
         << "] y perdio " << vidaPerdida << " puntos de vida"
         << "\n Vida anterior: " << vidaAnterior << " ---> Vida actual: " << vidaAnterior - vidaPerdida << endl;

}


bool Personaje::energiaMaxima() {

    if (energia == ENERGIA_MAXIMA)
        return true;

    return false;

}


int Personaje::calcularAtkEntranteTierra(Personaje* atacante) {

    int danio;
    array<int,2> posAtacante = atacante->obtenerPosicion();

    int distanciaFila = abs(posicion[0] - posAtacante[0]);
    int distanciaColumna = abs(posicion[1] - posAtacante[1]);

    danio = ATK_BASE_TIERRA;

    if (distanciaFila <= DISTANCIA_CORTA && distanciaColumna <= DISTANCIA_CORTA)

        danio *= TRIPLICAR_DANIO;

    else if (distanciaFila <= DISTANCIA_MEDIA && distanciaColumna <= DISTANCIA_MEDIA)

        danio *= DUPLICAR_DANIO;

    return danio;

}
