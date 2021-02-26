#ifndef TP_3_UTILES_H
#define TP_3_UTILES_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <array>
#include <algorithm>

using namespace std;

// constantes de archivos
const string PATH_ARCHIVO_TABLERO = "tablero.csv";
const string PATH_ARCHIVO_PARTIDA = "partida.csv";
const string PATH_ARCHIVO_PERSONAJES = "personajes.csv";

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
const int VIDA_NULA = 0;
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
const int VIDA_MADERA = 5;
const int ENERGIA_MADERA = 10;
const int ENERGIA_TURNO_AIRE = 5;

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
const short int GUARDAR_Y_SALIR = 1;

// constantes del tablero
const int MIN_FILA = 1;
const int MAX_FILA = 8;
const int MIN_COLUMNA = 1;
const int MAX_COLUMNA = 8;
const int CANT_VERTICES = MAX_FILA * MAX_COLUMNA;

// constante de dijkstra
const int INFINITO = 9999;

// constantes de los casilleros
const char MONTANIA = 'M';
const char PRECIPICIO = 'P';
const char LAGO = 'L';
const char VOLCAN = 'V';
const char CAMINO = 'C';
const char VACIO = 'X';
const int COSTO_NULO = 0;
const int COSTO_MEDIO = 1;
const int COSTO_ALTO = 2;
const int COSTO_VACIO = 15;

// constantes de la defensa
const int ENERGIA_DEF_FUEGO = 10;
const int RECUP_DEF_FUEGO = 10;
const int ENERGIA_DEF_AGUA = 12;
const int RECUP_DEF_AGUA = 50;
const int CURA_DEF_AGUA = 10;
const int ENERGIA_DEF_AIRE = 15;
const int ENERGIA_DEF_TIERRA = 5;
const int ESCUDO_DEF_TIERRA = 2;

const float MOD_ESCUDO = 0.1;
const float MOD_DEF_TIERRA = 0.8;

// constantes del ataque
const int ENERGIA_ATK_FUEGO = 5;
const int ENERGIA_ATK_AIRE = 8;
const int ENERGIA_ATK_TIERRA = 6;
const int ENERGIA_ATK_AGUA = 5;
const int ATK_BASE_FUEGO = 20;
const int MOD_ATK_FUEGO = 10;
const int ATK_BASE_AIRE = 15;
const int MOD_ATK_AIRE = 5;
const int ATK_BASE_TIERRA = 10;
const int MOD_ATK_TIERRA = 20;
const int ATK_BASE_AGUA = 20;
const int MOD_ATK_AGUA = 10;

// codigos de elemento
const string COD_TIERRA = "tierra";
const string COD_FUEGO = "fuego";
const string COD_AIRE = "aire";
const string COD_AGUA = "agua";

// constantes de Juego
const int CANT_JUGADORES = 2;
const int JUGADOR_1 = 1;
const int JUGADOR_2 = 2;

#endif //TP_3_UTILES_H
