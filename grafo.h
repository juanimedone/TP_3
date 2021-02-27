#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H

#include "casillero.h"
#include "recorrido.h"

class Grafo {

    // atributos
private:
    int agua[CANT_VERTICES][CANT_VERTICES];                      // matrices de costos
    int aire[CANT_VERTICES][CANT_VERTICES];
    int fuego[CANT_VERTICES][CANT_VERTICES];
    int tierra[CANT_VERTICES][CANT_VERTICES];
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
    Recorrido dijkstra(int origen, int destino, int matrizPesos[CANT_VERTICES][CANT_VERTICES]);

private:
    // PRE:
    // POS:
    void inicializarMatriz(int matrizPesos[CANT_VERTICES][CANT_VERTICES], const string& elemento);

    // PRE:
    // POS:
    void rellenarMatriz(int matriz[CANT_VERTICES][CANT_VERTICES]);

    // PRE:
    // POS:
    int distanciaMinima(array<int,CANT_VERTICES> distancias, array<bool,CANT_VERTICES> visitados);

    // PRE:
    // POS:
    int calcularIndice(array<int,2> posicion);

};


#endif //TP_3_GRAFO_H
