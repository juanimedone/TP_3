#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H

#include "matriz.h"
#include "casillero.h"

class Grafo {

    // atributos
private:
    Matriz<int>* agua, *aire, *fuego, *tierra;     // matrices de costos
    Casillero* vertices[MAX_FILA][MAX_COLUMNA];

    // metodos
public:
    // PRE: debe haber un personaje en posicion (personaje != nullptr)
    // POS:
    Personaje* obtenerPersonaje(array<int,2> posicion);

    // PRE:
    // POS:
    bool estaVacio(array<int,2> posicion);

    // PRE:
    // POS:
    void posicionarPersonaje(Personaje* personaje, array<int,2> posicion);

    // PRE:
    // POS:
    Recorrido dijkstra(array<int,2> origen, array<int,2> destino);

};


#endif //TP_3_GRAFO_H
