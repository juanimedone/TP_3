#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H

#include "matriz.h"
#include "casillero.h"
#include "recorrido.h"

class Grafo {

    // atributos
private:
    Matriz<int>* agua, *aire, *fuego, *tierra;     // matrices de costos
    Casillero* vertices[MAX_FILA][MAX_COLUMNA];
    // int elementos = MAX_FILA * MAX_COLUMNA;

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

};


#endif //TP_3_GRAFO_H
