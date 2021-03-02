#ifndef TP_3_MENUPRINCIPAL_H
#define TP_3_MENUPRINCIPAL_H

#include "juego.h"
#include "diccionarioABB.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"

class MenuPrincipal {

    // atributos
private:
    short int opcion = 0;

    //metodos
public:
    // PRE: -
    // POS: imprime por pantalla un mensaje inicial
    void iniciar();

    // PRE: -
    // POS: detiene la ejecucion del programa hasta que el usuario presione una tecla para continuar
    void pausar();

    // PRE: -
    // POS: ejecuta el ciclo principal del menu
    void interfazPrincipal(Juego& juego, DiccionarioABB<string,Personaje*>& diccionario);

private:

    // PRE: -
    // POS: borra el contenido previo mostrado por pantalla
    void limpiarPantalla();

    // PRE: -
    // POS: imprime por pantalla las opciones del menu
    void mostrarOpciones();

    // PRE: el usuario debe ingresar un entero
    // POS: asigna la opcion ingresada por el usuario
    void pedirOpcion();

    // PRE: -
    // POS: muestra todos los personajes y si no fue cargado previamente, crea y agrega al diccionario el personaje indicado por el usuario
    void agregarPersonaje(DiccionarioABB<string,Personaje*>& diccionario);

    // PRE: -
    // POS: si el diccionario no esta vacio, muestra todos los personajes y elimina el ingresado por el usuario (si existe)
    void eliminarPersonaje(DiccionarioABB<string,Personaje*>& diccionario);

    // PRE: -
    // POS: imprime por pantalla todos los nombres de los personajes del diccionario (si el dicionario esta vacio muestra un mensaje)
    void mostrarPersonajes(DiccionarioABB<string,Personaje*>& diccionario);

    // PRE: -
    // POS: imprime por pantalla todos los atributos del personaje ingresado por el usuario (si existe y el diccionario no esta vacio)
    void detallePersonaje(DiccionarioABB<string,Personaje*>& diccionario);

    // PRE: el usuario no debe ingresar espacios
    // POS: asigna el elemento ingresado por el usuario
    void pedirElemento(string& elemento);

    // PRE: -
    // POS: asigna el nombre ingresado por el usuario
    void pedirNombre(string& nombre);

    // PRE: -
    // POS: en caso de ser invalido, vuelve a pedirle al usuario que ingrese el elemento hasta que sea valido
    void validarElemento(string& elemento);

    // PRE: -
    // POS: convierte cada letra de la cadena a minuscula
    void pasarAMinuscula(string& cadena);

    // PRE: -
    // POS: reserva espacio para el elemento correspondiente en el heap y lo devuelve como puntero a Personaje
    Personaje* crearPersonaje(const string& elemento, const string& nombre);

    // PRE: -
    // POS: carga los personajes en los arrays de los jugadores
    void cargarPersonajes(Jugador jugador1, Jugador jugador2, DiccionarioABB<string,Personaje*>& diccionario);

    // PRE: -
    // POS: muestra el submenu de seleccionar personaje
    void menuJuego(Jugador jugador, DiccionarioABB<string,Personaje*>& diccionario, int& numPersonaje);

    // PRE: -
    // POS: imprime por pantalla las opciones para la seleccion de los personajes
    void mostrarOpcionesJuego();

    // PRE: -
    // POS: pide el personaje deseado, lo asigna al array de jugador y lo elimina del diccionario
    void seleccionarPersonaje(Jugador jugador, DiccionarioABB<string,Personaje*>& diccionario, int& numPersonaje);

    // PRE: -
    // POS: asigna el codigo correspondiente al personaje segun su numero de personaje
    void asignarCodigo(Personaje* personaje, int numPersonaje);

};


#endif //TP_3_MENUPRINCIPAL_H
