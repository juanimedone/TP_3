#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H

#include "casillero.h"
#include "recorrido.h"
#include "utiles.h"

class Grafo {

    // atributos
private:
    int agua[MAX_FILA][MAX_COLUMNA];                      // matrices de costos
    int aire[MAX_FILA][MAX_COLUMNA];
    int fuego[MAX_FILA][MAX_COLUMNA];
    int tierra[MAX_FILA][MAX_COLUMNA];
    array<Casillero*,CANT_VERTICES> vertices;

    // metodos
public:
    // PRE:
    // POS:
    void inicializarMatrices();

    // PRE:
    // POS:
    void asignarVertice(Casillero* vertice, array<int,2> posicion);

    // PRE: debe haber un personaje en posicion (personaje != nullptr)
    // POS:
    Personaje* obtenerPersonaje(array<int,2> posicion);

    // PRE:
    // POS:
    bool estaVacio(array<int,2> posicion);

    // PRE:
    // POS:
    void moverPersonaje(Personaje* personaje, array<int,2> posInicial, array<int,2> posFinal);

    // PRE:
    // POS:
    void mostrar();

    // PRE:
    // POS:
    Recorrido dijkstra(array<int,2> origen, string elemento);

private:
    // PRE:
    // POS:
    void inicializarMatriz(int matrizPesos[MAX_FILA][MAX_COLUMNA], const string& elemento);

};


#endif //TP_3_GRAFO_H
