#ifndef TP_3_PERSONAJE_H
#define TP_3_PERSONAJE_H

#include "utiles.h"

class Personaje {

    // atributos
protected:
    string nombre;
    short int escudo;
    int vida;
    int energia;
    array<int,2> posicion;
    char codigo;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Personaje(string nombre);

    // PRE: ESCUDO_MINIMO <= escudo <= ESCUDO_MAXIMO
    // POS: modifica el valor del atributo escudo
    void asignarEscudo(short int escudo);

    // PRE: VIDA_MINIMA <= vida <= VIDA_MAXIMA
    // POS: modifica el valor del atributo vida
    void asignarVida(int vida);

    // PRE: ENERGIA_MINIMA <= energia <= ENERGIA_MAXIMA
    // POS: modifica el valor del atributo energia
    void asignarEnergia(int energia);

    // PRE: -
    // POS: modifica los valores de posicion a los ingresados
    void asignarPosicion(array<int,2> posicion);

    // PRE: -
    // POS: asigna el simbolo que representa al personaje en el tablero
    void asignarCodigo(char codigo);

    // PRE: -
    // POS: devuelve el nombre del personaje
    string obtenerNombre();

    // PRE: -
    // POS: devuelve el valor de escudo del personaje
    short int obtenerEscudo();

    // PRE: -
    // POS: devuelve la vida actual del personaje
    int obtenerVida();

    // PRE: -
    // POS: devuelve la energia actual del personaje
    int obtenerEnergia();

    // PRE: -
    // POS: devuelve un arreglo con la posicion [fila, columna] del personaje
    array<int,2> obtenerPosicion();

    // PRE: -
    // POS: devuelve el codigo que representa al personaje en el tablero
    char obtenerCodigo();

    // PRE: -
    // POS: pide, valida y devuelve un array de coordenadas
    array<int,2> pedirCoordenadas();

    // PRE: -
    // POS: devuelve true si el personaje posee un valor de energia mayor o igual a la necesaria, false de lo contrario
    bool energiaSuficiente(int energiaNecesaria);

    // PRE: el personaje debe ser de fuego
    // POS: si el personaje tiene cero energia, reduce la vida por VIDA_TURNO_FUEGO
    void vidaPorCeroEnergia();

    // PRE: -
    // POS: devuelve el elemento del personaje
    virtual string obtenerElemento() = 0;

    // PRE: -
    // POS: imprime por pantalla el elemento que corresponda y los atributos del personaje
    virtual void mostrar() = 0;

    // PRE: -
    // POS: modifica la energia o la vida (o no hace nada) segun el elemento del personaje
    virtual void alimentar() = 0;

    // PRE: -
    // POS: aumenta la energia que corresponda segun el elemento del personaje
    virtual void aumentarEnergia() = 0;

    // PRE: -
    // POS: devuelve true si tiene su defensa activada, false de lo contrario
    virtual bool defensaActivada() = 0;

    // PRE: defensaActiva = true
    // POS: el personaje pierde 2 puntos de escudo y defensa_activa es false
    virtual void desactivarDefensa() = 0;

    // PRE: el vector enemigos contiene tres personajes
    // POS: de cumplirse los requisitos especificos de cada elemento, realiza el efecto de ataque correspondiente
    virtual void atacar(Personaje** enemigos) = 0;

    // PRE: el vector aliados contiene tres personajes
    // POS: de cumplirse los requisitos de cada elemento, realiza el efecto de defensa correspondiente
    virtual void defender(Personaje** aliados) = 0;

    // PRE: -
    // POS: devuelve el daño que recibiria el personaje al ser atacado por el atacante,
    //      teniendo en cuenta elementos, escudo y habilidades especiales.
    virtual int calcularAtkEntrante(Personaje* atacante) = 0;

    // destructor
    // PRE: -
    // POS: libera el espacio de memoria que corresponda segun el elemento del personaje
    virtual ~Personaje() = default;

protected:
    // metodos internos comunes para todas las clases hijas
    // PRE: -
    // POS: imprime por pantalla todos los atributos del personaje
    void mostrarAtributos();

    // PRE: -
    // POS: devuelve true si los valores de coordenadas ingresados son validos, false de lo contrario
    bool esValida(string& fila, string& columna);

    // PRE: -
    // POS: resta la vida correspondiente segun el ataque del enemigo y lo muestra por pantalla
    void restarVida(Personaje*& enemigo);

    // PRE: -
    // POS: devuelve true si tiene la maxima cantidad de energia, false de lo contrario
    bool energiaMaxima();

    // PRE: enemigo tiene que ser de tierra
    // POS: devuelve el danio que recibe el personaje de acuerdo a su distancia en el tablero con el atacante
    int calcularAtkEntranteTierra(Personaje* enemigo);

};



#endif //TP_3_PERSONAJE_H
