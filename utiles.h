#ifndef TP_3_UTILES_H
#define TP_3_UTILES_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <array>
#include <cctype>

using namespace std;

// constante de Archivo
const string PATH_ARCHIVO = "personajes.csv";

// constantes de Menu
const int AGREGAR_PERSONAJE = 1;
const int ELIMINAR_PERSONAJE = 2;
const int MOSTRAR_PERSONAJES = 3;
const int DETALLE_PERSONAJE = 4;
const int COMENZAR_JUEGO = 5;
const int SALIR = 6;

// constantes de Personaje
const int ESCUDO_MINIMO = 0;
const int ESCUDO_MAXIMO = 2;
const int RANGO_ESCUDO = ESCUDO_MAXIMO - ESCUDO_MINIMO + 1;
const int VIDA_MINIMA = 10;
const int VIDA_MAXIMA = 100;
const int RANGO_VIDA = VIDA_MAXIMA - VIDA_MINIMA + 1;
const int ENERGIA_MINIMA = 0;
const int ENERGIA_MAXIMA = 20;
const int RANGO_ENERGIA = ENERGIA_MAXIMA - ENERGIA_MINIMA + 1;
const array<int,2> COORD_INVALIDA = {-1,-1};

// constantes de los elementos
const int CANT_MAX_PLANCTON = 3;
const int ENERGIA_PLANCTON = 10;
const int ENERGIA_HIERBAS = 8;
const int VIDA_MADERA = 15;
const string COD_TIERRA = "tierra";
const string COD_FUEGO = "fuego";
const string COD_AIRE = "aire";
const string COD_AGUA = "agua";

// constantes de cargarPersonajes
const int MOSTRAR_DETALLE = 1;
const int MOSTRAR_TODOS = 2;
const int SELECCIONAR_PERSONAJE = 3;
const int SALIR_JUEGO = 4;

// constantes de Jugador
const int MAX_PERSONAJES = 3;
const int ALIMENTARSE = 1;
const int MOVERSE = 2;
const int PASAR = 3;
const int DEFENDERSE = 1;
const int ATACAR = 2;

// constantes del tablero
const int MIN_FILA = 1;
const int MAX_FILA = 8;
const int MIN_COLUMNA = 1;
const int MAX_COLUMNA = 8;

#endif //TP_3_UTILES_H
